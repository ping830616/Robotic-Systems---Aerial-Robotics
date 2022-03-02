classdef bh_eul_eigenaxis_CLS < bh_rots_PKG.bh_vis_DCM_passive_CLS
% DEFINITIONS:
%
% The Eigenaxis description of pose is defined by:
%    a.)  E_vec = [Ex, Ey, Ez]  where:   1 = Ex^2 + Ey^2 + Ez^2
%    b.)  theta = rotation (Righ Hand rule) about E_vec
%
% In ALL of the utilities contained in this class we expect/enforce
% a NORMALISED Eigenaxis vector, ie:
%
%         1  =  Ex^2 + Ey^2 + Ez^2
%--------------------------------------------------------------------------  
%  EXPECTED USAGE MODE_#1:
%
%       OBJ    = bh_eul_eigenaxis_CLS(e_vec, theta_rad); 
%
%  EXPECTED USAGE MODE_#2:
%
%       OBJ    = bh_eul_eigenaxis_CLS(DCM_B_given_A);
%  METHODS:
%    e_dot_col = calc_e_rates_using_wb(OBJ, wb_col)
%      NEW_OBJ = convert_angle_to_pm_pi(OBJ)
%--------------------------------------------------------------------------
% % you can also VISUALIZE the passive rotation matrix
%  
%   OBJ.plot()
%
%   OBJ.plot_pair()
%
%   NOTE:  these visualiztion methods are inherited from the 
%          bh_vis_DCM_passive_CLS class
%--------------------------------------------------------------------------
% COMMENTS:
% a.)  For USAGE_MODE_#2:  we supply a DCM and then compute the Eigenaxis
%      parameters (see PROTECTED method calc_e_and_theta).  In this
%      calculation we compute theta within the range [0, pi] ... and then
%      compute the corresponding rotation axis for that positive angle.
%
%      Please see the tutorial <bh_test_eig.mlx> for demonstrations of this
%--------------------------------------------------------------------------
% REFERENCE:
%  Wie chapter 5 - "Space Vehicle Dynamics and Control"
%--------------------------------------------------------------------------  
properties (SetAccess = private)
   e_col         = [NaN; NaN; NaN];
   theta_rad     = NaN;
   DCM_B_given_A = NaN(3,3);
end

properties (Dependent = true)
   theta_deg  % the angle in DEGREES
   e_axis     % same as e_col .. but displayed as a ROW
end  

methods
function OBJ = bh_eul_eigenaxis_CLS(varargin)
%  ALLOWED USAGE:
%    OBJ = bh_eul_eigenaxis_CLS(e_vec, theta_rad);
%    OBJ = bh_eul_eigenaxis_CLS(DCM_B_given_A);
    
    if(2==nargin)
       e_vec     = varargin{1};
       theta_rad = varargin{2};
       validateattributes(e_vec,    {'numeric', 'sym'},{'vector', 'numel',3});
       validateattributes(theta_rad,{'numeric', 'sym'},{'scalar'});

       e_vec = e_vec/norm(e_vec);  % UNIT vector

       OBJ.e_col         = e_vec(:);
       OBJ.theta_rad     = theta_rad;       
       OBJ.DCM_B_given_A = OBJ.calc_DCM_B_given_A();
       
       
    elseif(1==nargin)
        DCM_B_given_A = varargin{1};
        validateattributes(DCM_B_given_A, {'numeric', 'sym'},{'size', [3,3]});
        
        
        OBJ.DCM_B_given_A = DCM_B_given_A;
        [e_vec, theta_rad] = OBJ.calc_e_and_theta();
        OBJ.e_col          = e_vec(:);
        OBJ.theta_rad      = theta_rad;       
        
    else
        error('###_ERROR:  Unknown usage mode');
    end

    % populate the inherited property
    OBJ.vis_DCM_bRg = OBJ.DCM_B_given_A;
end
%--------------------------------------------------------------------------
function  theta_deg = get.theta_deg(OBJ)
          theta_deg = rad2deg(OBJ.theta_rad);
end
%--------------------------------------------------------------------------
function e_axis = get.e_axis(OBJ)
         e_axis = OBJ.e_col.' ; 
end
%--------------------------------------------------------------------------
function NEW_OBJ = convert_angle_to_pm_pi(OBJ)

     TH     = OBJ.theta_rad;
     TH_DEG = rad2deg(TH);
     
     TH_DEG_PM_180  = bh_rots_PKG.bh_wrap_DEG_angle(TH_DEG,"-180_TO_180");
     
     % take care of the outputs
     theta_rad = deg2rad(TH_DEG_PM_180);
     E_col     = OBJ.e_col;
     
     NEW_OBJ   =  bh_rots_PKG.bh_eul_eigenaxis_CLS(E_col, theta_rad);
     
end
%--------------------------------------------------------------------------
function e_dot_col = calc_e_rates_using_wb(OBJ, wb_col)
    
  % e_dot_col = [ DOT_theta; 
  %               DOT_Ex; 
  %               DOT_Ey; 
  %               DOT_Ez; ] 
  
  import bh_rots_PKG.bh_tf_is_value_zero    

  theta = OBJ.theta_rad;

  C   = cos(theta/2);
  S   = sin(theta/2);
  E_x = OBJ.e_col(1);
  E_y = OBJ.e_col(2);
  E_z = OBJ.e_col(3);
  
  % is sin(theta/2) too close to ZERO
  tf_is_zero = bh_tf_is_value_zero(S, "METHOD_A");
   
  assert(tf_is_zero==false, "ERR:  sin(THETA/2) is too close to ZERO");

  % *** PROOF: bh_explore_eigenaxis_AND_quat_rates.mlx ***
   
  Exx = -E_x*E_x*C/S;
  Eyy = -E_y*E_y*C/S;
  Ezz = -E_z*E_z*C/S;  
  
  Exy = -E_x*E_y*C/S;
  Exz = -E_x*E_z*C/S; 
  Eyz = -E_y*E_z*C/S;   
    
  A = 0.5 * [       2*E_x,        2*E_y,        2*E_z;
              (Exx + C/S),  (Exy - E_z),  (Exz + E_y);
              (Exy + E_z),  (Eyy + C/S),  (Eyz - E_x);
              (Exz - E_y),  (Eyz + E_x),  (Ezz + C/S);     ]  ;
          
 e_dot_col = A * wb_col(:);         
          
end
%--------------------------------------------------------------------------
function hax = plot_ee(OBJ)

     hax = OBJ.plot_pair();  % an inherted method from the bh_vis_DCM_passive_CLS class
    
     hold(hax(1),'on');  axes(hax(1));
     %mArrow3([0 0 0], 2*OBJ.e_axis, 'color', 'black',   'stemWidth', 0.05);
     mArrow3(-2*OBJ.e_axis, 2*OBJ.e_axis, 'color', 'black',   'stemWidth', 0.05);

     hold(hax(2),'on');  axes(hax(2));
     %mArrow3([0 0 0], 2*OBJ.e_axis, 'color', 'black',   'stemWidth', 0.05);
     mArrow3(-2*OBJ.e_axis, 2*OBJ.e_axis, 'color', 'black',   'stemWidth', 0.05);
end
%--------------------------------------------------------------------------
function animate(OBJ,hax)
   arguments
       OBJ
       hax = []
   end

   if(isempty(hax))
    figure;
    hax = axes;
   end

    import bh_rots_PKG.bh_vehicle_CLS
    import bh_rots_PKG.bh_eul_eigenaxis_CLS

    veh_OBJ = bh_vehicle_CLS();
    veh_OBJ.plot_3D(hax);

    hold(hax,'on');  axes(hax);
    mArrow3(-2*OBJ.e_axis, 2*OBJ.e_axis, 'color', 'black',   'stemWidth', 0.05);
    
    theta_rad  = OBJ.theta_rad;
    e_vec      = OBJ.e_col;
    
    NUM_STEPS  = 25;
    theta_list = linspace(0, theta_rad, NUM_STEPS);

    for theta_val = theta_list

        my_ee   = bh_eul_eigenaxis_CLS(e_vec, theta_val);
        DCM_bRg = my_ee.DCM_B_given_A;
        DCM_gRb = DCM_bRg.';    

        veh_OBJ = veh_OBJ.rotate_using_gRb(DCM_gRb);
    
        % plot stuff
        cla(hax);
        veh_OBJ.plot_3D(hax);

        hold(hax,'on');  axes(hax);
        mArrow3(-2*OBJ.e_axis, 2*OBJ.e_axis, 'color', 'black',   'stemWidth', 0.05);
        
        drawnow;
        pause(0.1)
        
    end

end
%--------------------------------------------------------------------------

end
%_#########################################################################
%   E N D   O F   M E T H O D S
%_#########################################################################
methods (Access = protected)
function my_DCM = calc_DCM_B_given_A(OBJ)
    %  BODY_vec = DCM * GROUND_vec
    
    % *** PROOF: bh_explore_eigenaxis_DCM_derivation.mlx ***
    
    cTH   = cos(OBJ.theta_rad);
    sTH   = sin(OBJ.theta_rad);
    e1    = OBJ.e_col(1);
    e2    = OBJ.e_col(2);
    e3    = OBJ.e_col(3);
    
    C_11 =  cTH + e1^2*(1-cTH);
    C_12 = e1*e2*(1-cTH) + e3*sTH;
    C_13 = e1*e3*(1-cTH) - e2*sTH;
       
    C_21 = e1*e2*(1-cTH) - e3*sTH;
    C_22 =  cTH + e2^2*(1-cTH);
    C_23 = e2*e3*(1-cTH) + e1*sTH;
    
    C_31 = e3*e1*(1-cTH) + e2*sTH;
    C_32 = e3*e2*(1-cTH) - e1*sTH;
    C_33 = cTH + e3^2*(1-cTH);
        
    my_DCM = [ C_11, C_12, C_13;
               C_21, C_22, C_23;
               C_31, C_32, C_33;   ];   
end
%--------------------------------------------------------------------------
function [e_col, theta_rad] = calc_e_and_theta(OBJ)
    % Compute the Eigenaxis parameters from the DCM
    
    import bh_rots_PKG.bh_tf_is_value_zero    
    
    C_11 = OBJ.DCM_B_given_A(1,1);
    C_22 = OBJ.DCM_B_given_A(2,2);
    C_33 = OBJ.DCM_B_given_A(3,3);
    
    % *** PROOF: bh_explore_eigenaxis_AND_quat_DCM_derivation.mlx ***
    %   C_11 + C_22 + C_33 = 2.cos(theta) + 1
    
    % compute theta_rad
    tmp_arg = 0.5*(C_11 + C_22 + C_33 - 1);
    assert( abs(tmp_arg) <= 1, '###_ERROR:  something seems strange with your DCM');
     
    % theta_rad will be in the interval [0 pi]
    theta_rad = acos(  tmp_arg  );
    
    % Establish if sin(THETA) is zero   
    sTH        = sin(theta_rad);
    tf_is_zero = bh_tf_is_value_zero(sTH, "METHOD_A");
    
    % compute the rotation axes
    if(tf_is_zero)
        e_col = [0;0;0];
        warning( 'bh_eul_eigenaxis:valueIsZERO', " ---> sin(THETA) = 0");
    else
        C_23 = OBJ.DCM_B_given_A(2,3);
        C_32 = OBJ.DCM_B_given_A(3,2);
        C_31 = OBJ.DCM_B_given_A(3,1);
        C_13 = OBJ.DCM_B_given_A(1,3);
        C_12 = OBJ.DCM_B_given_A(1,2);
        C_21 = OBJ.DCM_B_given_A(2,1);
    
        e_col = [ (C_23 - C_32);
                  (C_31 - C_13);
                  (C_12 - C_21);]/(2*sin(theta_rad));
    end
end
%--------------------------------------------------------------------------
end % methods(protected)
%_#########################################################################
%    E N D  O F  M E T H O D S (protected)
%_#########################################################################

end % class
%_#########################################################################
% L O C A L   S U B F U N C T I O N S   B E Y O N D   T H I S   P O I N T
%_#########################################################################

