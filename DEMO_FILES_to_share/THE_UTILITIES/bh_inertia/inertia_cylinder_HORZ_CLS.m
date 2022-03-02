classdef inertia_cylinder_HORZ_CLS
       
    properties  (SetAccess = protected)
        Lx   = 1;
        R    = 1;
        MASS = 1;
    end
    
    methods
        function OBJ = inertia_cylinder_HORZ_CLS(the_LX, the_R, mass)
                 OBJ.Lx   =  the_LX;
                 OBJ.R    =  the_R;
                 OBJ.MASS =  mass;
        end
        %------------------------------------------------------------------
        function V = get_vol(OBJ)
                 V = OBJ.Lx * (pi * OBJ.R^2 );
        end
        %------------------------------------------------------------------
        function Ixx = get_Ixx(OBJ)
                 Ixx = OBJ.MASS*(OBJ.R^2)/2;
        end
        %------------------------------------------------------------------
        function Iyy = get_Iyy(OBJ)
                 Iyy = OBJ.MASS*(OBJ.Lx^2 + 3*OBJ.R^2)/12;
        end
        %------------------------------------------------------------------
        function Izz = get_Izz(OBJ)
                 Izz = OBJ.MASS*(OBJ.Lx^2 + 3*OBJ.R^2)/12;
        end
        %------------------------------------------------------------------
        function I = get_I(OBJ)
                 %I      = zeros(3);
                 I(1,1) = get_Ixx(OBJ);
                 I(2,2) = get_Iyy(OBJ);
                 I(3,3) = get_Izz(OBJ);
        end
        %------------------------------------------------------------------ 
    end
end
%_#########################################################################
%_ HELPER functions
%_#########################################################################
function CHECK_MASS(mass)
    if(1~=mass | bh_is_sym(mass) )
        return
    end
    
    % OK, if we got to here THEN we have a UNIT mass
    % so it sounds like MAYBE the OBJ.MASS hasn't been assigned by the user
    % so throw a warning
    warning('MASS:UNITY', 'Hey: mass=1. Have you set it ?')
end
%==========================================================================


