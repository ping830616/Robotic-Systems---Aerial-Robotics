classdef tetra_irreg_CLS
       
    properties (SetAccess = protected)
        v_mat   = zeros(3,4);  % 4 columns of the xyx co-ordinates of each vertex
    end
    
    methods
        function OBJ = tetra_irreg_CLS(v1_pt, v2_pt, v3_pt, v4_pt)
            
            % assert that each input is a 3 element vector
            validateattributes(v1_pt, {'numeric'}, {'vector', 'numel', 3, 'real'});
            validateattributes(v2_pt, {'numeric'}, {'vector', 'numel', 3, 'real'});
            validateattributes(v3_pt, {'numeric'}, {'vector', 'numel', 3, 'real'});
            validateattributes(v4_pt, {'numeric'}, {'vector', 'numel', 3, 'real'});
            
            OBJ.v_mat   = [v1_pt(:), v2_pt(:), v3_pt(:), v4_pt(:),];
        end
        %------------------------------------------------------------------
        function cm_xyz_col = get_cm(OBJ)
                     N = size(OBJ.v_mat,2);
            cm_xyz_col = sum(OBJ.v_mat, 2)/N; % sum across the rows and average
            
            % should be a 3x1 column vector
            validateattributes(cm_xyz_col, {'numeric'}, {'column', 'numel', 3, 'real'});
        end
        %------------------------------------------------------------------   
        function the_vol = get_volume(OBJ)
             % volume formulae is HERE:
             %    https://en.wikipedia.org/wiki/Tetrahedron
             d12 = norm( OBJ.v_mat(:,1) -  OBJ.v_mat(:,2) );
             d13 = norm( OBJ.v_mat(:,1) -  OBJ.v_mat(:,3) );
             d14 = norm( OBJ.v_mat(:,1) -  OBJ.v_mat(:,4) );
             d23 = norm( OBJ.v_mat(:,2) -  OBJ.v_mat(:,3) );
             d24 = norm( OBJ.v_mat(:,2) -  OBJ.v_mat(:,4) );
             d34 = norm( OBJ.v_mat(:,3) -  OBJ.v_mat(:,4) );
             
             M = [    0,   1,       1,        1,        1;
                      1,   0,       d12^2,    d13^2,    d14^2 ;
                      1,   d12^2,   0,        d23^2,    d24^2 ;
                      1,   d13^2,   d23^2,    0,        d34^2 ;
                      1,   d14^2,   d24^2,    d34^2,    0;     
                  ];
             
             tmp_det = det(M);
             assert(tmp_det>0, 'ERROR:  your determinant is NOT positive !');
             
             the_vol = sqrt(tmp_det/288);
            % should be a scalar greater than ZERO         
            validateattributes(the_vol, {'numeric'}, {'scalar', '>', 0, 'real'});
        end
        %------------------------------------------------------------------           
    end
    
end % CLASSDEF
%_#########################################################################
%_ HELPER functions
%_#########################################################################

