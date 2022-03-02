classdef inertia_slender_rod_CLS
       
    properties (SetAccess = protected)
        Lx   = 1;
        MASS = 1;
    end
    
    methods
        function OBJ = inertia_slender_rod_CLS(the_LX, mass)
                 OBJ.Lx   = the_LX;
                 OBJ.MASS = mass;
        end
        %------------------------------------------------------------------
        function V = get_vol(OBJ)
                 V = [];
        end
        %------------------------------------------------------------------
        function Ixx = get_Ixx(OBJ)
                 Ixx = 0;
        end
        %------------------------------------------------------------------
        function Iyy = get_Iyy(OBJ)
                 Iyy = OBJ.MASS*(OBJ.Lx^2)/12;
        end
        %------------------------------------------------------------------
        function Izz = get_Izz(OBJ)
                 Izz = OBJ.MASS*(OBJ.Lx^2)/12;
        end
        %------------------------------------------------------------------
        function I = get_I(OBJ)
                 %I      = zeros(3);
                 I(1,1) = get_Ixx();
                 I(2,2) = get_Iyy();
                 I(3,3) = get_Izz();
        end
        %------------------------------------------------------------------        
    end
    
end % CLASSDEF
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
