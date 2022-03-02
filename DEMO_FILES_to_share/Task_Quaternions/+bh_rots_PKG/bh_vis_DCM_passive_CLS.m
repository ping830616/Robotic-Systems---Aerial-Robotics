classdef bh_vis_DCM_passive_CLS
% BH_VIS_DCM_PASSIVE_CLS - Visualize a passive rotation matrix
%
% The DCM defines the relationship between the components of a vector in 
% the G-frame and the corresponding vector in the B-frame.  The B-frame is 
% rotated relative to the G-frame.
% 
%        bV = bRg * gV
%
% In this context we say that the PASSIVE rotation matrix bRg is the DCM
%
%--------------------------------------------------------------------------
%  ATTENTION:
%     This class has been designed to be a SUPERCLASS(parent) for the 
%     following SUBCLASSES(child)
% 
%        a.)  bh_eul_eigenaxis_CLS
%        b.)  bh_rot_passive_G2B_CLS
%--------------------------------------------------------------------------       

    properties (SetAccess = protected)
        vis_DCM_bRg = zeros(3,3)
    end

    methods
        function OBJ = bh_vis_DCM_passive_CLS(bRg)
            arguments 
                bRg (3,3)  = zeros(3,3) % allows ZERO argument calling
            end

            OBJ.vis_DCM_bRg = bRg;
        end
        %------------------------------------------------------------------
        function hax = plot(OBJ,opts)
           arguments
              OBJ
              opts.hax = []
              opts.tf_showcar (1,1) logical = true
              opts.tf_show_gframe (1,1) logical = false
           end

           if(isempty(opts.hax))
               figure;
               opts.hax = axes;
           end
               
           import bh_rots_PKG.bh_vehicle_CLS
 
           % get the PASSIVE rotation matrix:  bRg
           DCM_bRg = OBJ.vis_DCM_bRg; 

           % create the ACTIVE rotation matrix:  gRb
           DCM_gRb = DCM_bRg.';    
    
           veh_OBJ = bh_vehicle_CLS();

           if(false == opts.tf_showcar)
              veh_OBJ.FaceAlpha = 0;
              veh_OBJ.EdgeAlpha = 0;
           end

           veh_OBJ = veh_OBJ.rotate_using_gRb(DCM_gRb);
    
           % plot stuff
           veh_OBJ.plot_3D(opts.hax);

           % should I also show the G-frame ?
           if(true==opts.tf_show_gframe)
             mArrow3([0 0 0], [1 0 0], 'color', 'black',   'stemWidth', 0.02);
             mArrow3([0 0 0], [0 1 0], 'color', 'black', 'stemWidth', 0.02);
             mArrow3([0 0 0], [0 0 1], 'color', 'black',  'stemWidth', 0.02);
             
             text(1,0,0,'X_g')
             text(0,1,0,'Y_g')
             text(0,0,1,'Z_g')          
           end

           % take care of the output
           hax = opts.hax;
        end
        %------------------------------------------------------------------
        function hax = plot_pair(OBJ,opts)
           arguments
              OBJ
              opts.hax  = []     %(:,2) = double.empty(0,2)
           end

           if(isempty(opts.hax))
               figure;
               opts.hax(1) = subplot(1,2,1);
               opts.hax(2) = subplot(1,2,2);
           end

          import bh_rots_PKG.bh_vehicle_CLS
 
          % PLOT the car in it's BIRTH pose
          DCM_bRg = eye(3);
          DCM_gRb = DCM_bRg.';        
          veh_OBJ = bh_vehicle_CLS();  
          veh_OBJ = veh_OBJ.rotate_using_gRb(DCM_gRb);
          veh_OBJ.plot_3D(opts.hax(1));
          title(opts.hax(1), "ORIGINAL")

          % plot the car in it's NEW pose
          plot(OBJ,"hax",opts.hax(2) )
          title(opts.hax(2), "FINAL")

          % take care of any (optional) outputs
          hax = opts.hax;
        end
    %------------------------------------------------------------------ 
    end
end