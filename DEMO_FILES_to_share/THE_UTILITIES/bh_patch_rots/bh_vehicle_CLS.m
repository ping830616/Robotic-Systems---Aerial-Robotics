classdef bh_vehicle_CLS
% BH_VEHICLE_CLS 
%   A simple class for drawing a "vehicle" to explore ROTATION sequences
%
% Example USAGE:
%
%    OBJ = bh_vehicle_CLS()
%
%    figure();
%       hax(1) = subplot(2,2,1);  OBJ.plot_3D(hax(1));
%       hax(2) = subplot(2,2,2);  OBJ.plot_XY(hax(2));  
%       hax(3) = subplot(2,2,3);  OBJ.plot_XZ(hax(3));  
%       hax(4) = subplot(2,2,4);  OBJ.plot_YZ(hax(4));  
%--------------------------------------------------------------------------
%    [X,Y,Z] = OBJ.get_B_XYZ();
%    
%    a = 45*pi/180;
%
%  gRb = [cos(a),  -sin(a),  0;
%         sin(a),   cos(a),  0;
%              0,        0,  1; ];
%
%    new_XYZ = agRb * [X';
%                      Y';
%                      Z' ];
%
%    OBJ = OBJ.set_G_XYZ(new_XYZ(1,:)', new_XYZ(2,:)', new_XYZ(3,:)');
%-------------------------------------------------------------------------- 
%    figure();
%       hax(1) = subplot(2,2,1);  OBJ.plot_3D(hax(1));
%       hax(2) = subplot(2,2,2);  OBJ.plot_XY(hax(2));  
%       hax(3) = subplot(2,2,3);  OBJ.plot_XZ(hax(3));  
%       hax(4) = subplot(2,2,4);  OBJ.plot_YZ(hax(4));  
%--------------------------------------------------------------------------
    properties
        FaceAlpha = 1;
        gRb       = eye(3); % vG=gRb*vB, DCM for plotting unit vec arrows
        XL        = [-2, 2];
        YL        = [-2, 2];
        ZL        = [-2, 2];
    end
  
    properties (SetAccess = protected)
       X_b_col = [];
       Y_b_col = [];
       Z_b_col = [];
       %------------
       X_g_col = [];
       Y_g_col = [];
       Z_g_col = [];
    end
    
    properties (SetAccess = protected, GetAccess = protected)
       X_b_floor_col   = []; 
       X_b_rear_col    = [];
       X_b_side_A_col  = [];
       X_b_side_B_col  = [];
       X_b_roof_col    = []; 
       %-----------------------
       Y_b_floor_col   = []; 
       Y_b_rear_col    = [];
       Y_b_side_A_col  = [];
       Y_b_side_B_col  = [];
       Y_b_roof_col    = []; 
       %-----------------------
       Z_b_floor_col   = []; 
       Z_b_rear_col    = [];
       Z_b_side_A_col  = [];
       Z_b_side_B_col  = [];
       Z_b_roof_col    = []; 
       %-----------------------
       X_g_floor_col   = []; 
       X_g_rear_col    = [];
       X_g_side_A_col  = [];
       X_g_side_B_col  = [];
       X_g_roof_col    = []; 
       %-----------------------
       Y_g_floor_col   = []; 
       Y_g_rear_col    = [];
       Y_g_side_A_col  = [];
       Y_g_side_B_col  = [];
       Y_g_roof_col    = []; 
       %-----------------------
       Z_g_floor_col   = []; 
       Z_g_rear_col    = [];
       Z_g_side_A_col  = [];
       Z_g_side_B_col  = [];
       Z_g_roof_col    = []; 
       %-----------------------
    end
    
    methods
        function OBJ = bh_vehicle_CLS()
            OBJ = PROT_define_birth_body_XYZ(OBJ);
            OBJ = set_G_XYZ(OBJ, OBJ.X_b_col, OBJ.Y_b_col, OBJ.Z_b_col);
        end
        %------------------------------------------------------------------
        function [X,Y,Z] = get_B_XYZ(OBJ)
                  X = OBJ.X_b_col;
                  Y = OBJ.Y_b_col;
                  Z = OBJ.Z_b_col;
        end
        %------------------------------------------------------------------
        function [X,Y,Z] = get_G_XYZ(OBJ)
                  X = OBJ.X_g_col;
                  Y = OBJ.Y_g_col;
                  Z = OBJ.Z_g_col;
        end
        %------------------------------------------------------------------   
        function V_3xN = get_G_XYZ_3xN(OBJ)
                  X = OBJ.X_g_col;
                  Y = OBJ.Y_g_col;
                  Z = OBJ.Z_g_col;
                  
                  V_3xN = [X';
                           Y';
                           Z'];
        end
        %------------------------------------------------------------------
        function V_3xN = get_B_XYZ_3xN(OBJ)
                  X = OBJ.X_b_col;
                  Y = OBJ.Y_b_col;
                  Z = OBJ.Z_b_col;
                  
                  V_3xN = [X';
                           Y';
                           Z'];
        end
        %------------------------------------------------------------------    
        function OBJ = set_G_XYZ(OBJ, Xg, Yg, Zg)
                 OBJ = PROT_set_G_XYZ(OBJ, Xg, Yg, Zg);
        end
        %------------------------------------------------------------------
        function hax = plot_3D(OBJ, hax)
                 hax = PROT_plot_3D(OBJ, hax);
        end
        %------------------------------------------------------------------
        function hax = plot_XY(OBJ, hax)
              hax = PROT_plot_3D(OBJ, hax);
              % set camera view
              az = 0;  el = 90; 
              view(hax, az, el);
        end
        %------------------------------------------------------------------                    
        function hax = plot_XZ(OBJ, hax)
              hax = PROT_plot_3D(OBJ, hax);
              % set camera view
              az = 180;  el = 0; 
              view(hax, az, el);
        end
        %------------------------------------------------------------------        
        function hax = plot_YZ(OBJ, hax)
              hax = PROT_plot_3D(OBJ, hax);
              % set camera view
              az = 90;  el = 0; 
              view(hax, az, el);
        end
        %------------------------------------------------------------------ 
        function [OBJ, hax] = rotate_and_animate(OBJ, arot_OBJ, hax)
            ANG_1st_FULL = arot_OBJ.ang_1st;
            ANG_2nd_FULL = arot_OBJ.ang_2nd;
            ANG_3rd_FULL = arot_OBJ.ang_3rd;

            ANG_UNITS    = char(arot_OBJ.ang_units);
            
            NUM_STEPS    = 25;

            ANG_1st_step = ANG_1st_FULL / NUM_STEPS;
            ANG_2nd_step = ANG_2nd_FULL / NUM_STEPS;
            ANG_3rd_step = ANG_3rd_FULL / NUM_STEPS;

            % animate the 1st rotation
            for kk=0:NUM_STEPS
                inc_arot_OBJ  = bh_rot_active_B2G_CLS(    ...
                                       {char(arot_OBJ.dir_1st)},...
                                       [kk*ANG_1st_step], ...
                                       ANG_UNITS);
                                   
                V_3xN   = OBJ.get_B_XYZ_3xN();       
                new_XYZ = inc_arot_OBJ.apply_active_R1(V_3xN); % apply the rotation
                OBJ     = OBJ.set_G_XYZ(new_XYZ(1,:)',new_XYZ(2,:)',new_XYZ(3,:)');
                gRb     = inc_arot_OBJ.get_active_R1();    % get and store the DCM 
                OBJ.gRb = gRb;
                % update the vehicle's PLOT
                cla(hax);
                OBJ.plot_3D(hax);
                pause(0.1)
                %drawnow
            end % for kk=0:NUM_STEPS
            
            % animate the 2nd rotation
            for kk=0:NUM_STEPS
                inc_arot_OBJ  = bh_rot_active_B2G_CLS( ...
                                       {char(arot_OBJ.dir_1st), ...
                                          char(arot_OBJ.dir_2nd)}, ...
                                       [ANG_1st_FULL, kk*ANG_2nd_step], ...
                                       ANG_UNITS);
                                   
                V_3xN   =  OBJ.get_B_XYZ_3xN();       
                new_XYZ = inc_arot_OBJ.apply_active_R1R2(V_3xN); % apply the rotation
                OBJ = OBJ.set_G_XYZ(new_XYZ(1,:)',new_XYZ(2,:)',new_XYZ(3,:)');
                gRb     = inc_arot_OBJ.get_active_R1R2();   % get and store the DCM 
                OBJ.gRb = gRb;
                % update the vehicle's PLOT
                cla(hax);
                OBJ.plot_3D(hax);
                pause(0.1)
            end % for kk=
            
            % animate the 3rd rotation
            for kk=0:NUM_STEPS
                inc_arot_OBJ  = bh_rot_active_B2G_CLS(   ...
                                       {char(arot_OBJ.dir_1st), ...
                                          char(arot_OBJ.dir_2nd), ...
                                          char(arot_OBJ.dir_3rd)}, ...
                                       [ANG_1st_FULL, ANG_2nd_FULL, ...
                                          kk*ANG_3rd_step], ...
                                       ANG_UNITS);
                                   
                V_3xN   =  OBJ.get_B_XYZ_3xN();       
                new_XYZ = inc_arot_OBJ.apply_active_R1R2R3(V_3xN); % apply the rotation
                OBJ = OBJ.set_G_XYZ(new_XYZ(1,:)',new_XYZ(2,:)',new_XYZ(3,:)');
                gRb     = inc_arot_OBJ.get_active_R1R2R3();     
                OBJ.gRb = gRb;
                % update the vehicle's PLOT
                cla(hax);
                OBJ.plot_3D(hax);
                pause(0.1)
            end % for kk=           
            
        end % rotate_then_plot_3D()
    end
    %_*********************************************************************
    % END METHODS(Access=public)
    %_*********************************************************************
    methods (Access = protected)
        function OBJ = PROT_define_birth_body_XYZ(OBJ)
            % floor of car, 4 points, overall: 1:4
            XYZ_dat = [];
            XYZ_dat = [ -1, -0.5, -0.25;
                         1, -0.5, -0.25;
                         1,  0.5, -0.25;
                        -1,  0.5, -0.25;
                        ];

             OBJ.X_b_floor_col = XYZ_dat(:,1);
             OBJ.Y_b_floor_col = XYZ_dat(:,2);
             OBJ.Z_b_floor_col = XYZ_dat(:,3);

             % rear of car, 4 points, overall 5:8
             XYZ_dat = [];
             XYZ_dat = [ -1, -0.5, -0.25;
                         -1, -0.5,  0.25;
                         -1,  0.5,  0.25;
                         -1,  0.5, -0.25;
                       ];
             OBJ.X_b_rear_col = XYZ_dat(:,1);
             OBJ.Y_b_rear_col = XYZ_dat(:,2);
             OBJ.Z_b_rear_col = XYZ_dat(:,3);

             % side A, 3 points, overall 9:11
             XYZ_dat = [];
             XYZ_dat = [ -1, -0.5,  0.25;
                         -1, -0.5, -0.25;
                          1, -0.5, -0.25;
                       ];
             OBJ.X_b_side_A_col = XYZ_dat(:,1);
             OBJ.Y_b_side_A_col = XYZ_dat(:,2);
             OBJ.Z_b_side_A_col = XYZ_dat(:,3);

             % side B, 3 points, overall 12:14
             XYZ_dat = [];
             XYZ_dat = [ -1, 0.5,  0.25;
                         -1, 0.5, -0.25;
                          1, 0.5, -0.25;
                       ];
             OBJ.X_b_side_B_col = XYZ_dat(:,1);
             OBJ.Y_b_side_B_col = XYZ_dat(:,2);
             OBJ.Z_b_side_B_col = XYZ_dat(:,3);

            % roof of car, 4 points, overall 15:18
            XYZ_dat = [ -1, -0.5,  0.25;
                        -1,  0.5,  0.25;
                         1,  0.5, -0.25;
                         1, -0.5, -0.25;
                        ];
              
             OBJ.X_b_roof_col = XYZ_dat(:,1);
             OBJ.Y_b_roof_col = XYZ_dat(:,2);
             OBJ.Z_b_roof_col = XYZ_dat(:,3);

             % define the flat list of X,Y,Z
             OBJ.X_b_col = [ 
                               OBJ.X_b_floor_col; 
                               OBJ.X_b_rear_col;
                               OBJ.X_b_side_A_col;
                               OBJ.X_b_side_B_col;
                               OBJ.X_b_roof_col; 
                           ];
             OBJ.Y_b_col = [ 
                               OBJ.Y_b_floor_col; 
                               OBJ.Y_b_rear_col;
                               OBJ.Y_b_side_A_col;
                               OBJ.Y_b_side_B_col;
                               OBJ.Y_b_roof_col; 
                           ];
             OBJ.Z_b_col = [ 
                               OBJ.Z_b_floor_col; 
                               OBJ.Z_b_rear_col;
                               OBJ.Z_b_side_A_col;
                               OBJ.Z_b_side_B_col;
                               OBJ.Z_b_roof_col; 
                           ];                
        end
        %------------------------------------------------------------------ 
        function OBJ = PROT_set_G_XYZ(OBJ, Xg, Yg, Zg)
            Xg = Xg(:);
            Yg = Yg(:);
            Zg = Zg(:);
            
            tf_test_a =(length(Xg)==length(Yg)) && (length(Xg)==length(Yg));
            tf_test_b =(length(Xg)==length(OBJ.X_b_col));
            
            assert(tf_test_a, 'ERROR: your Xg,Yg,Zg have different lengths');
            assert(tf_test_b, 'ERROR: your G lengths are different to the B lengths');
            
            OBJ.X_g_col = Xg;
            OBJ.Y_g_col = Yg;
            OBJ.Z_g_col = Zg;
            
            OBJ.X_g_floor_col   = Xg( 1:4); 
            OBJ.X_g_rear_col    = Xg( 5:8);
            OBJ.X_g_side_A_col  = Xg( 9:11);
            OBJ.X_g_side_B_col  = Xg(12:14);
            OBJ.X_g_roof_col    = Xg(15:18); 
            %-----------------------
            OBJ.Y_g_floor_col   = Yg( 1:4); 
            OBJ.Y_g_rear_col    = Yg( 5:8);
            OBJ.Y_g_side_A_col  = Yg( 9:11);
            OBJ.Y_g_side_B_col  = Yg(12:14);
            OBJ.Y_g_roof_col    = Yg(15:18); 
            %-----------------------
            OBJ.Z_g_floor_col   = Zg( 1:4); 
            OBJ.Z_g_rear_col    = Zg( 5:8);
            OBJ.Z_g_side_A_col  = Zg( 9:11);
            OBJ.Z_g_side_B_col  = Zg(12:14);
            OBJ.Z_g_roof_col    = Zg(15:18);     
        end
        %------------------------------------------------------------------ 
        function hax = PROT_plot_3D(OBJ, hax)
             if(isempty(hax))
                hax = axes;
             end
            
             axes(hax);
             
             % floor of car
             X = OBJ.X_g_floor_col;
             Y = OBJ.Y_g_floor_col;
             Z = OBJ.Z_g_floor_col;

             C(1,1,:) = [0,1,0];
             hp(1) = patch(  X,Y, Z, C, 'FaceAlpha', OBJ.FaceAlpha); 

             % rear
             X = OBJ.X_g_rear_col;
             Y = OBJ.Y_g_rear_col;
             Z = OBJ.Z_g_rear_col;

             C(1,1,:) = [1,0,0];
             hp(2) = patch(  X,Y, Z, C, 'FaceAlpha', OBJ.FaceAlpha); 

             % side A
             X = OBJ.X_g_side_A_col;
             Y = OBJ.Y_g_side_A_col;
             Z = OBJ.Z_g_side_A_col;

             C(1,1,:) = [0,0,1];
             hp(3) = patch(  X,Y, Z, C, 'FaceAlpha', OBJ.FaceAlpha);
             
             % side B
             X = OBJ.X_g_side_B_col;
             Y = OBJ.Y_g_side_B_col;
             Z = OBJ.Z_g_side_B_col;

             C(1,1,:) = [1,1,0];
             hp(4) = patch(  X,Y, Z, C, 'FaceAlpha', OBJ.FaceAlpha); 

             % roof of car
             X = OBJ.X_g_roof_col;
             Y = OBJ.Y_g_roof_col;
             Z = OBJ.Z_g_roof_col;

             C(1,1,:) = [0,1,1];
             hp(5) = patch(  X,Y, Z, C, 'FaceAlpha', OBJ.FaceAlpha); 
             
             axis equal
             grid on

             xlabel('X', 'FontWeight', 'Bold');
             ylabel('Y', 'FontWeight', 'Bold');
             zlabel('Z', 'FontWeight', 'Bold');
             
             % draw BODY fixed axes arrows
             arrow_xB = OBJ.gRb * [2,0,0]';
             arrow_yB = OBJ.gRb * [0,2,0]';
             arrow_zB = OBJ.gRb * [0,0,2]';
             
             mArrow3([0 0 0], arrow_xB, 'color', 'red', 'stemWidth', 0.05);
             mArrow3([0 0 0], arrow_yB, 'color', 'blue', 'stemWidth', 0.05);
             mArrow3([0 0 0], arrow_zB, 'color', 'green', 'stemWidth', 0.05);
             
             text(arrow_xB(1), arrow_xB(2), arrow_xB(3),'X_b')
             text(arrow_yB(1), arrow_yB(2), arrow_yB(3),'Y_b')
             text(arrow_zB(1), arrow_zB(2), arrow_zB(3),'Z_b')
             
             % set camera view
             az = 54;  el = 30; 
             view(az, el)

             %axis tight
             axis equal
          
             % set limits
             xlim(OBJ.XL);
             ylim(OBJ.YL);
             zlim(OBJ.ZL);
             
        end
        %------------------------------------------------------------------ 
    end %(Access = protected)
    %
end
%_#########################################################################
% END of CLASSDEF
%_#########################################################################


