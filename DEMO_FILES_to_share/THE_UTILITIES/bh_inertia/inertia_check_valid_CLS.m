classdef inertia_check_valid_CLS
    
    properties  (SetAccess = protected)
        I_mat          = [];
    end
    
    methods
        function  OBJ = inertia_check_valid_CLS(I)
            OBJ.I_mat          = I;
        end
        %------------------------------------------------------------------
        function assert_is_valid(OBJ)
            Ixx = OBJ.I_mat(1,1);
            Iyy = OBJ.I_mat(2,2);
            Izz = OBJ.I_mat(3,3);
            
            Ixy = OBJ.I_mat(1,2);
            Ixz = OBJ.I_mat(1,3);
            Iyz = OBJ.I_mat(2,3);
            
            % 1st confirm that I is a SYMMETRIC matrix
            assert_is_symmetric( OBJ.I_mat );

            % 2nd, check the element relationships
            assert( (Ixx + Iyy) >= Izz , 'FAILED test ---> (Ixx + Iyy) >= Izz');
            assert( (Ixx + Izz) >= Iyy , 'FAILED test ---> (Ixx + Izz) >= Iyy');
            assert( (Iyy + Izz) >= Ixx , 'FAILED test ---> (Iyy + Izz) >= Ixx');
            
            assert( (Ixx) >= (2*Iyz) , 'FAILED test ---> (Ixx) >= (2*Iyz)');
            assert( (Iyy) >= (2*Ixz) , 'FAILED test ---> (Iyy) >= (2*Ixz)');
            assert( (Izz) >= (2*Ixy) , 'FAILED test ---> (Izz) >= (2*Ixy)');
                      
        end
        %------------------------------------------------------------------        
    end
    
end
%_#########################################################################
%_ HELPER functions
%_#########################################################################
function assert_is_symmetric(I_mat)
   diff_mat = I_mat - I_mat.' ; 
   diff_mat =  abs(diff_mat);
   diff_row = sum(diff_mat);
   
   tf_row   = diff_row < (1e-6 * min( I_mat(:)) );
   
   assert(all(tf_row), 'ERROR: your INERTIA matrix is NOT symmetric ?' );
end
%==========================================================================

