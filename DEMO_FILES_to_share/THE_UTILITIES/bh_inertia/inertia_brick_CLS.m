classdef inertia_brick_CLS
       
    properties (SetAccess = protected)
        Lx   = 1;
        Ly   = 1;
        Lz   = 1;
        MASS = 1;
    end
    
    methods
        function OBJ = inertia_brick_CLS(the_LX, the_LY, the_LZ, mass)
                 OBJ.Lx   = the_LX;
                 OBJ.Ly   = the_LY;
                 OBJ.Lz   = the_LZ;
                 OBJ.MASS = mass;
        end
        %------------------------------------------------------------------
        function V = get_vol(OBJ)
                 V = OBJ.Lx * OBJ.Ly * OBJ.Lz;
        end
        %------------------------------------------------------------------
        function Ixx = get_Ixx(OBJ)
                 Ixx = OBJ.MASS*(OBJ.Ly^2 + OBJ.Lz^2)/12;
        end
        %------------------------------------------------------------------
        function Iyy = get_Iyy(OBJ)
                 Iyy = OBJ.MASS*(OBJ.Lx^2 + OBJ.Lz^2)/12;
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
    if(1~=mass)
        return
    end
    
    % OK, if we got to here THEN we have a UNIT mass
    % so it sounds like MAYBE the OBJ.MASS hasn't been assigned by the user
    % so through a warning
    warning('MASS:UNITY', 'Hey: mass=1. Have you set it ?')
end
%==========================================================================
