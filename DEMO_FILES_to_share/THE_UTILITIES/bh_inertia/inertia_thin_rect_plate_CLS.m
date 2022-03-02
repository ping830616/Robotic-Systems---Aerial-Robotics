classdef inertia_thin_rect_plate_CLS
       
    properties (SetAccess = protected)
        Lx   = 1;
        Ly   = 1;
        MASS = 1;
    end
    
    methods
        function OBJ = inertia_thin_rect_plate_CLS(the_LX, the_LY, mass)
                 OBJ.Lx   = the_LX;
                 OBJ.Ly   = the_LY;
                 OBJ.MASS = mass;
        end
        %------------------------------------------------------------------
        function Ixx = get_Ixx(OBJ)
                 Ixx = OBJ.MASS*(OBJ.Ly^2)/12;
        end
        %------------------------------------------------------------------
        function Iyy = get_Iyy(OBJ)
                 Iyy = OBJ.MASS*(OBJ.Lx^2)/12;
        end
        %------------------------------------------------------------------
        function Izz = get_Izz(OBJ)
                 Izz = OBJ.MASS*(OBJ.Lx^2 + OBJ.Ly^2)/12;
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
