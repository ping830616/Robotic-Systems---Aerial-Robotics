classdef inertia_3bladed_trp_propeller_CLS
       
    properties (SetAccess = protected)
        LEN_blade    = 1;
        WIDTH_blade  = 1;
        MASS_blade    = 1;
    end
    
    methods
        function OBJ = inertia_3bladed_trp_propeller_CLS(LEN_blade, WIDTH_blade, MASS_blade)
                 OBJ.LEN_blade   = LEN_blade;
                 OBJ.WIDTH_blade = WIDTH_blade;
                 OBJ.MASS_blade   = MASS_blade;
        end
        %------------------------------------------------------------------
        function Ixx = get_Ixx(OBJ)
                 Lx = OBJ.LEN_blade;
                 Ly = OBJ.WIDTH_blade;
                 Ixx = OBJ.MASS_blade*(4*Lx^2 + Ly^2)/8;
        end
        %------------------------------------------------------------------
        function Iyy = get_Iyy(OBJ)
                 Lx = OBJ.LEN_blade;
                 Ly = OBJ.WIDTH_blade;
                 Iyy = OBJ.MASS_blade*(4*Lx^2 + Ly^2)/8;
        end
        %------------------------------------------------------------------
        function Izz = get_Izz(OBJ)
                 Lx = OBJ.LEN_blade;
                 Ly = OBJ.WIDTH_blade;
                 Izz = OBJ.MASS_blade*(4*Lx^2 + Ly^2)/4;
        end
        %------------------------------------------------------------------
        function I = get_I(OBJ)
                 %I      = zeros(3);
                 I(1,1) = OBJ.get_Ixx();
                 I(2,2) = OBJ.get_Iyy();
                 I(3,3) = OBJ.get_Izz();
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
