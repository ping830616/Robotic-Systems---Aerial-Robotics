classdef bh_quat_rot_CLS
% QUATERNION convention 
%
% We'll adopt the same convention used by Phillips(see REF #1). 
%
%      q     = q0  +  qx.i  +  qy.j  +  qz.k
%
%      q_col = [q0, qx, qy, qz]'
%
% ATTENTION:
%
% In ALL of the utilities contained in this class we expect/enforce
% a NORMALISED quaternion, ie:
%
%         1  =  q0^2  +  qx^2  +  qy^2  +  qz^2
%--------------------------------------------------------------------------  
% REFERENCES:
%  REF_#1   "Mechanics of Flight - 2nd Edition", Warren F. Phillips
%--------------------------------------------------------------------------  
    
methods
function OBJ = bh_quat_rot_CLS()
end
%--------------------------------------------------------------------------
% CALC Q from utilities
%--------------------------------------------------------------------------
function [q_col, q_xyz]  = calc_q_from_eigenaxis(OBJ, E_col, theta_rad)
        
    validateattributes(E_col,    {'numeric', 'sym'},{'vector', 'numel',3});
    validateattributes(theta_rad,{'numeric', 'sym'},{'scalar'});
    
    %  CHECK the UNIT vector condition for the Eigenaxis
    if( isnumeric(E_col) )
        tmp_abs_diff = abs( 1 - sum(E_col.^2)  );
        if( tmp_abs_diff > 1e-10)
            warning('###_WARNING:  Hey the E_col was NOT a UNIT VECTOR !')
        end
    end
    
    % Enforce the UNIT vector condition
    E_col      = E_col / norm(E_col);
        
    % OK, proceed
    theta      = theta_rad;    
    Ex         = E_col(1);
    Ey         = E_col(2);
    Ez         = E_col(3);
    
    % Here is the definition of the quaternion parameters
    % *** REF: page  996 of Phillips ***
    q_col(1,1) =       cos(theta/2);  % q0
    q_col(2,1) =  Ex * sin(theta/2);  % qX
    q_col(3,1) =  Ey * sin(theta/2);  % qY
    q_col(4,1) =  Ez * sin(theta/2);  % qZ
    
    q_xyz      = q_col(2:4);
    
    % do a check on the UNITY condition of the quaternion
    LOC_check_unit_quaternion(q_col);
end
%--------------------------------------------------------------------------
function [q_col, q_xyz]  = calc_q_from_dcm(OBJ, my_DCM)
    
    validateattributes(my_DCM, {'numeric', 'sym'},{'size', [3,3]});
    
    % CHECK that we've been given a DCM
    if( isnumeric(my_DCM) )
        tmp_abs_diff = abs( eye(3) - (my_DCM.' * my_DCM) );
        tmp_abs_diff = sum(tmp_abs_diff(:));
        if( tmp_abs_diff > 1e-10)
            warning('###_WARNING:  Hey the DCM seems a little strange !')
        end
    end
    
    % *** REF: page 1011 of Phillips ***
    C_23 = my_DCM(2,3);
    C_32 = my_DCM(3,2);
    C_31 = my_DCM(3,1);
    C_13 = my_DCM(1,3);
    C_12 = my_DCM(1,2);
    C_21 = my_DCM(2,1);
              
    C_11 = my_DCM(1,1);
    C_22 = my_DCM(2,2);
    C_33 = my_DCM(3,3);
    
    q_sq = 0.25 * [  (1 + C_11 + C_22 + C_33);
                     (1 + C_11 - C_22 - C_33);
                     (1 - C_11 + C_22 - C_33);
                     (1 - C_11 - C_22 + C_33);  ];
    
    [~, ind] = max( q_sq );
    
    switch(ind)
        case 1  % so q0^2 was max 
              q0 = sqrt( q_sq(1) );
              qx = (C_23 - C_32) / (4*q0);
              qy = (C_31 - C_13) / (4*q0);
              qz = (C_12 - C_21) / (4*q0);
        case 2 % so qx^2 was max 
              qx = sqrt( q_sq(2) );
              q0 = (C_23 - C_32) / (4*qx);
              qy = (C_12 + C_21) / (4*qx);
              qz = (C_31 + C_13) / (4*qx);
        case 3 % so qy^2 was max 
              qy = sqrt( q_sq(3) );
              q0 = (C_31 - C_13) / (4*qy);
              qx = (C_12 + C_21) / (4*qy);
              qz = (C_23 + C_32) / (4*qy);
        case 4 % so qz^2 was max 
              qz = sqrt( q_sq(4) );
              q0 = (C_12 - C_21) / (4*qz);
              qx = (C_31 + C_13) / (4*qz);
              qy = (C_23 + C_32) / (4*qz);
        otherwise
            error('###_ERROR:  do NOT know what happened here');
    end

    q_col = [q0; qx; qy; qz];    
    q_xyz = [qx; qy; qz];
      
    % do a check on the UNITY condition
    LOC_check_unit_quaternion(q_col, "ASSERT");
end
%--------------------------------------------------------------------------
function [q_col, q_123]  = calc_q_from_YPR(OBJ, yaw, pitch, roll)

    Rz_YAW   = [  cos(yaw), sin(yaw), 0;
                 -sin(yaw), cos(yaw), 0;
                         0,        0, 1;  ];

    Ry_PITCH = [  cos(pitch), 0,  -sin(pitch);
                           0, 1,            0;
                  sin(pitch), 0,   cos(pitch);  ];


    Rx_ROLL  = [  1,            0,         0;
                  0,    cos(roll), sin(roll);
                  0,   -sin(roll), cos(roll); ];
 
                          
    %  v_BODY_B = DCM_B_given_A * v_INERTIAL_A 
    
    my_DCM_B_given_A =  Rx_ROLL *  Ry_PITCH * Rz_YAW;
    
    [q_col, q_xyz]   = calc_q_from_dcm(OBJ, my_DCM_B_given_A );
    
    % do a check on the UNITY condition
    LOC_check_unit_quaternion(q_col, "ASSERT");
end
%--------------------------------------------------------------------------
% CALC THINGS from Q utilities
%--------------------------------------------------------------------------
function my_DCM_B_given_A = calc_dcm_from_q(OBJ, q_col)

    validateattributes(q_col,    {'numeric', 'sym'},{'vector', 'numel',4});
        
    % quick check that we've been given a UNIT quaternion
    if( isnumeric(q_col) )
       LOC_check_unit_quaternion(q_col,"WARNING");
    end
    
    q0    = q_col(1);
    qx    = q_col(2);
    qy    = q_col(3);
    qz    = q_col(4);
    
    % *** REF: page  998 of Phillips ***
    % *** PROOF: bh_explore_eigenaxis_AND_quat_DCM_derivation.mlx ***
    %            (it is a substitution from this result)
    C_11  = qx^2 + q0^2 - qy^2 - qz^2;
    C_12  = 2*(qx*qy + qz*q0);
    C_13  = 2*(qx*qz - qy*q0);
       
    C_21  = 2*(qx*qy - qz*q0);
    C_22  = qy^2 + q0^2 - qx^2 - qz^2;
    C_23  = 2*(qy*qz + qx*q0);
    
    C_31  = 2*(qx*qz + qy*q0);
    C_32  = 2*(qy*qz - qx*q0);
    C_33  = qz^2 + q0^2 - qx^2 - qy^2;
    
    
    my_DCM_B_given_A = [ C_11, C_12, C_13;
                         C_21, C_22, C_23;
                         C_31, C_32, C_33;   ];   
end
%--------------------------------------------------------------------------
function [my_yaw, my_pitch, my_roll] = calc_yaw_pitch_roll_from_q(OBJ, q_col)

    validateattributes(q_col,    {'numeric', 'sym'},{'vector', 'numel',4});
    
    % quick check that we've been given a UNIT quaternion
    if( isnumeric(q_col) )
       LOC_check_unit_quaternion(q_col, "WARNING");
    end
    
    q0    = q_col(1);
    qx    = q_col(2);
    qy    = q_col(3);
    qz    = q_col(4);
    
    % *** REF  : page 1009 of Phillips     ***
    % *** PROOF: bh_explore_YPR_from_q.mlx ***
    
    SOME_ARBITRARY_VALUE = 1;
    
        if( abs(q0*qy - qx*qz - 0.5) < 1e-10 )
        
            my_yaw   = SOME_ARBITRARY_VALUE;
            my_roll  = 2*asin(qx/cos(pi/4)) + my_yaw;
            my_pitch = pi/2;
            
    elseif( abs(q0*qy - qx*qz + 0.5) < 1e-10 )
        
            my_yaw   = SOME_ARBITRARY_VALUE;
            my_roll  = 2*asin(qx/cos(pi/4)) - my_yaw;
            my_pitch = -pi/2;
             
    else
            my_yaw   = atan2(2*(q0*qz + qx*qy), (q0^2 + qx^2 - qy^2 - qz^2) );
            my_roll  = atan2(2*(q0*qx + qy*qz), (q0^2 + qz^2 - qx^2 - qy^2) );
            my_pitch = asin( 2*(q0*qy - qx*qz));       
    end
    
end
%--------------------------------------------------------------------------
function [ E_col, theta_rad] = calc_eigenaxis_from_q(OBJ, q_col)
    % NOTE:
    %   a.)  theta_rad  - will be in the interval [0, 2Pi]
       
    validateattributes(q_col,    {'numeric', 'sym'},{'vector', 'numel',4});
    
    % quick check that we've been given a UNIT quaternion
    if( isnumeric(q_col) )
       LOC_check_unit_quaternion(q_col,"WARNING");
    end
    
    q0    = q_col(1); % ==    cos(theta/2)
    qx    = q_col(2); % == Ex.sin(theta/2)
    qy    = q_col(3); % == Ey.sin(theta/2)
    qz    = q_col(4); % == Ez.sin(theta/2)
    
    % NOTE the following:
    %   acos() returns an angle in the interval  [0, pi]
    
    theta_rad = 2 * acos(q0);  % so theta_rad is in the interval [0, 2.pi]
    
    if(class(q_col) == "sym")
        Ex    = qx / sHTH;
        Ey    = qy / sHTH;
        Ez    = qz / sHTH;
        
        E_col = [Ex; Ey; Ez;]; 
    else % we're NUMERIC
    
        import bh_rots_PKG.bh_tf_is_value_zero

        % is sin(theta/2) close to zero ?
        sHTH       = sin(theta_rad/2);
        tf_is_zero = bh_tf_is_value_zero(sHTH);
    
        if( ~tf_is_zero )
            Ex    = qx / sHTH;
            Ey    = qy / sHTH;
            Ez    = qz / sHTH;
            
            E_col = [Ex; Ey; Ez;];  
        else
            warning('###_WARNING:  Hey the sin(theta/2) is nearly ZERO !');
            % REMEMBER: theta_rad/2 is zero when theta = 0,2.k.Pi. This 
            %           corresponds to a ZERO rotation angle, so the concept
            %           of a rotation axis is NOT defined.
    
            E_col = [0;0;0];
        end
    end   

end
%--------------------------------------------------------------------------
function q_out = calc_q_pm_pi_from_q(OBJ, q_col)
   
    
    q0    = q_col(1); % ==    cos(theta/2)
    qx    = q_col(2); % == Ex.sin(theta/2)
    qy    = q_col(3); % == Ey.sin(theta/2)
    qz    = q_col(4); % == Ez.sin(theta/2)
   
    % NOTE the following:
    %   acos() ---> returns an angle in the interval  [0, pi]   
    theta_rad = 2 * acos(q0);  % so theta_rad is in the interval [0, 2.pi]
    theta_deg = rad2deg(theta_rad);
    
    % is sin(theta/2) close to zero ?
    sHTH = sin(theta_rad/2);
    if( isnumeric(sHTH) && abs(sHTH) < 1e-10)
            warning('###_WARNING:  Hey the sin(theta/2) is nearly ZERO !')
    end
  
    Ex    = qx / sHTH;
    Ey    = qy / sHTH;
    Ez    = qz / sHTH;
    
    import bh_rots_PKG.bh_wrap_DEG_angle   
    
    wrapped_theta_deg = bh_wrap_DEG_angle(theta_deg, "-180_TO_180");
    wrapped_theta_rad = deg2rad(wrapped_theta_deg);
    
    q_out(1,1) =       cos(wrapped_theta_rad/2);  % q0
    q_out(2,1) =  Ex * sin(wrapped_theta_rad/2);  % qX
    q_out(3,1) =  Ey * sin(wrapped_theta_rad/2);  % qY
    q_out(4,1) =  Ez * sin(wrapped_theta_rad/2);  % qZ
end
%--------------------------------------------------------------------------
function Bvec = convert_Gvec_to_Bvec(OBJ, q_col, Gvec)
    arguments
        OBJ
        q_col (4,1)
        Gvec  (3,1)
    end

    % quick check that we've been given a UNIT quaternion
    if( isnumeric(q_col) )
        tmp_abs_diff = abs( 1 - sum(q_col.^2)  );
        if( tmp_abs_diff > 1e-10)
            warning('###_WARNING:  Hey the q_col was NOT a UNIT quaternion !')
        end
    end

    % make sure we have a UNIT quaternion
    e      = q_col / norm(q_col);
    e_conj = [e(1); -1*e(2:4)];

    Gq    = [0;Gvec];

    % vB = conj(e) *  (vG*e)
    Part_1 = LOC_q_mult(Gq, e);
    Bq     = LOC_q_mult(e_conj, Part_1);
 
    Bvec   = Bq(2:4);
end
%--------------------------------------------------------------------------
% CALC Q_DOT utilities
%--------------------------------------------------------------------------
function q_dot = calc_qdot_from_wb(OBJ, q_col, wb_col)
    
    validateattributes(q_col,    {'numeric', 'sym'},{'vector', 'numel',4});
    validateattributes(wb_col,   {'numeric', 'sym'},{'vector', 'numel',3});
    
    % quick check that we've been given a UNIT quaternion
    if( isnumeric(q_col) )
        tmp_abs_diff = abs( 1 - sum(q_col.^2)  );
        if( tmp_abs_diff > 1e-10)
            warning('###_WARNING:  Hey the q_col was NOT a UNIT vector !')
        end
    end
    
    % *** REF: page  999 of Phillips ***
    % *** PROOF: bh_explore_eigenaxis_AND_quat_rates.mlx ***    
    q0     = q_col(1);
    qx     = q_col(2);
    qy     = q_col(3);
    qz     = q_col(4);
           
    A      = [  -qx,  -qy,  -qz;
                 q0,  -qz,   qy;
                 qz,   q0,  -qx;
                -qy,   qx,   q0;  ];
      
    wb_col = wb_col(:);
  
    q_dot  = 0.5 * A * wb_col;
       
end
%--------------------------------------------------------------------------

end % methods
end % class
%_#########################################################################
%   UTILITIES
%_#########################################################################
function LOC_check_unit_quaternion(q_col,assert_str)
    arguments
        q_col
        assert_str (1,1) string  {mustBeMember(assert_str,["ASSERT", "WARNING"])} = "WARNING"
    end

    if( ~isnumeric(q_col) )
       return
    end
    
    % so we're numeric
    tmp_abs_diff = abs( 1 - sum(q_col.^2)  );
    tf_is_good   = tmp_abs_diff < 1e-10;

    switch(assert_str)
        case "WARNING"
              if(~tf_is_good)
                  warning("###_WARNING:  you do NOT have a UNIT quaternion");
              end
        case "ASSERT"
              assert(tf_is_good, "###_ERROR:  you do NOT have a UNIT quaternion")
        otherwise
            error("###_ERR:  UNknown method ---> LOC_check_unit_condition() ");
    end

end
%--------------------------------------------------------------------------
function C = LOC_q_mult(A,B)
    arguments
        A (4,1)
        B (4,1)
    end
    % Quaternion multiplication
    % *** REF: page  1001 of Phillips ***

    [A0,Ax,Ay,Az] = deal( A(1), A(2), A(3), A(4) );
    [B0,Bx,By,Bz] = deal( B(1), B(2), B(3), B(4) );

    C0 = A0*B0 - Ax*Bx - Ay*By - Az*Bz ;
    Cx = A0*Bx + Ax*B0 + Ay*Bz - Az*By ;
    Cy = A0*By - Ax*Bz + Ay*B0 + Az*Bx ;
    Cz = A0*Bz + Ax*By - Ay*Bx + Az*B0 ;

    C  = [C0;Cx;Cy;Cz];
end
