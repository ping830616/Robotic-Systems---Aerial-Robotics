classdef inertia_b_from_g_CLS

% We know the inerta matrix gI, relative to the G-frame
% We know that the B-frame was initially co-incident with the G-frame.
% The B-frame is rotated relative to the G-frame. And this rotation
% relationship is characterised by the PASSIVE rotation matrix:
%   bV =  b_R_g * gV
% We now want to know bI, ie: the inertia relative to the B-frame.
    
    properties (SetAccess = protected)
        bRg = []; % passive rotation matrix
                      % bV =  bRg * gV
                      
        gI  = []; % inertia matrix in G-frame
    end
    
    methods
        function OBJ = inertia_b_from_g_CLS( gI, bRg)
                 OBJ.gI  =  gI;
                 OBJ.bRg =  bRg;
        end
        %------------------------------------------------------------------
        function bI = calc_bI(OBJ)
            
                 bRg = OBJ.bRg;         
                 gI  = OBJ.gI;
                 
                 bI  = bRg * gI * bRg.' ;
        end
        %------------------------------------------------------------------
        
    end
    
end

