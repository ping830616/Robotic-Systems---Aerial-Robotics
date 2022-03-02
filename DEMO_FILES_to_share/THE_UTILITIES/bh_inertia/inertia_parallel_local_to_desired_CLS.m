classdef inertia_parallel_local_to_desired_CLS
    
    properties  (SetAccess = protected)
        I_local          = [];
        mass             = [];
        pos_CM_in_desired = []; 
    end
    
    methods
        function  OBJ = inertia_parallel_local_to_desired_CLS( ...
                                     pos_CM_rel_to_desired, I_LOC, mass)
            OBJ.I_local           = I_LOC;
            OBJ.mass              = mass;
            OBJ.pos_CM_in_desired = pos_CM_rel_to_desired;
        end
        %------------------------------------------------------------------
        function I_desired = calc_I_GLOB(OBJ)
            x_c  =  OBJ.pos_CM_in_desired(1);
            y_c  =  OBJ.pos_CM_in_desired(2);
            z_c  =  OBJ.pos_CM_in_desired(3);
                    
           A     =  [ (y_c^2 + z_c^2),         -x_c*y_c,         -x_c*z_c;
                             -x_c*y_c,  (x_c^2 + z_c^2),         -y_c*z_c;
                             -x_c*z_c,         -y_c*z_c,  (x_c^2 + y_c^2);
                    ];
                
            I_desired = OBJ.I_local + (OBJ.mass * A );
        end
        %------------------------------------------------------------------        
    end
    
end

