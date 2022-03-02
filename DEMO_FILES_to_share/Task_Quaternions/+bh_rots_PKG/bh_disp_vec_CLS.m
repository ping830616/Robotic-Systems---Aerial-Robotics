classdef bh_disp_vec_CLS
% BH_VEHICLE_CLS 
%   A simple class for plotting a "vector" to explore PASSIVE rotation sequences
%--------------------------------------------------------------------------
    properties
        bRg     = eye(3); % vB=bRg*vG, DCM for plotting unit vec arrows
    end
  
    properties (SetAccess = protected)
       vB_col = []
       vG_col = [];
    end
%==========================================================================
% End of Properties
%==========================================================================
    methods
        function OBJ = bh_disp_vec_CLS(vG, bRg)
            validateattributes(vG,{'double'},{'vector', 'numel',3});
            validateattributes(bRg,{'double'},{'2d', 'nrows',3,'ncols',3});

             vG         = vG(:);
             OBJ.vG_col = vG(:);
             OBJ.vB_col = bRg * vG(:);
             
             OBJ.bRg  = bRg;
        end
        %------------------------------------------------------------------
        function vB = get_B_XYZ(OBJ)
                 vB = OBJ.vB_col;
        end
        %------------------------------------------------------------------
        function vG = get_G_XYZ(OBJ)
                 vG = OBJ.vG_col;
        end
        %------------------------------------------------------------------   
        function hax = plot_3D(OBJ, hax)
                 hax = PROT_plot_3D(OBJ, hax);
        end
        %------------------------------------------------------------------
        function hax = plot_3D_with_PROJ(OBJ, hax)
              hax = PROT_plot_3D(OBJ, hax);

              gRb    = OBJ.bRg.';

              % put a dot on the XB axis
              xb_in_G = gRb * [OBJ.vB_col(1);0;0]; 
              axes(hax);
              hold(hax,'on');
              plot3(hax, xb_in_G(1), xb_in_G(2), xb_in_G(3), 'o', ...
                   'MarkerSize', 10, ...
                   'MarkerEdgeColor','k',...
                   'MarkerFaceColor',[1,1,0]);
              
              % draw a line down to the xB axis
              x = [xb_in_G(1), OBJ.vG_col(1)];
              y = [xb_in_G(2), OBJ.vG_col(2)];
              z = [xb_in_G(3), OBJ.vG_col(3)];
              
              plot3(hax, x,y,z, '-r'); 
              
              % put a dot on the YB axis
              yb_in_G = gRb * [0;OBJ.vB_col(2);0]; 
              axes(hax);
              hold(hax,'on');
              plot3(hax, yb_in_G(1), yb_in_G(2), yb_in_G(3), 'o', ...
                   'MarkerSize', 10, ...
                   'MarkerEdgeColor','k',...
                   'MarkerFaceColor',[1,1,0]);
              
              % draw a line down to the yB axis
              x = [yb_in_G(1), OBJ.vG_col(1)];
              y = [yb_in_G(2), OBJ.vG_col(2)];
              z = [yb_in_G(3), OBJ.vG_col(3)];
              
              plot3(hax, x,y,z, '-r'); 
              
              % put a dot on the ZB axis
              zb_in_G = gRb * [0;0;OBJ.vB_col(3)]; 
              axes(hax);
              hold(hax,'on');
              plot3(hax, zb_in_G(1), zb_in_G(2), zb_in_G(3), 'o', ...
                   'MarkerSize', 10, ...
                   'MarkerEdgeColor','k',...
                   'MarkerFaceColor',[1,1,0]);
              
              % draw a line down to the zB axis
              x = [zb_in_G(1), OBJ.vG_col(1)];
              y = [zb_in_G(2), OBJ.vG_col(2)];
              z = [zb_in_G(3), OBJ.vG_col(3)];
              
              plot3(hax, x,y,z, '-r'); 
              hold(hax,'off');
              axis tight
              axis equal
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
    end
    %_*********************************************************************
    % END METHODS(Access=public)
    %_*********************************************************************
    methods (Access = protected)
        %------------------------------------------------------------------ 
        function hax = PROT_plot_3D(OBJ, hax)
             if(isempty(hax))
                hax = axes;
             end
            
             axes(hax);
             
             % plot our vector
             xG = OBJ.vG_col(1);
             yG = OBJ.vG_col(2);
             zG = OBJ.vG_col(3);
             
             plot3(hax, xG, yG, zG, '.k', 'MarkerSize', 30);
             mArrow3([0 0 0], OBJ.vG_col, 'color', 'black', 'stemWidth', 0.02, 'tipWidth', 0.07);
            
             axis equal
             grid on

             xlabel('X', 'FontWeight', 'Bold');
             ylabel('Y', 'FontWeight', 'Bold');
             zlabel('Z', 'FontWeight', 'Bold');
             
             % draw BODY axes arrows
             gRb    = OBJ.bRg.';
             arrow_xB = gRb * [1,0,0]';
             arrow_yB = gRb * [0,1,0]';
             arrow_zB = gRb * [0,0,1]';
             
             mArrow3([0 0 0], arrow_xB, 'color', 'red', 'stemWidth',    0.02, 'tipWidth', 0.07);
             mArrow3([0 0 0], arrow_yB, 'color', 'blue', 'stemWidth',   0.02, 'tipWidth', 0.07);
             mArrow3([0 0 0], arrow_zB, 'color', 'green', 'stemWidth',  0.02, 'tipWidth', 0.07);

             text(arrow_xB(1), arrow_xB(2), arrow_xB(3),'X_b','FontSize',14)
             text(arrow_yB(1), arrow_yB(2), arrow_yB(3),'Y_b','FontSize',14)
             text(arrow_zB(1), arrow_zB(2), arrow_zB(3),'Z_b','FontSize',14)
             
             % set camera view
             az = 54;  el = 30; 
             view(az, el)
             
             axis tight
             axis equal
        end
        %------------------------------------------------------------------ 
    end %(Access = protected)
    %
end
%_#########################################################################
% END of CLASSDEF
%_#########################################################################


