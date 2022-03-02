classdef inertia_from_cloud_CLS
       
    properties (SetAccess = protected)
        x_col  = [];
        y_col  = [];
        z_col  = [];
        shp    = [];  % ALPHA shape
        cm_col = [];
    end
    
    properties
        Alpha = [];
    end
  
    methods
        function OBJ = inertia_from_cloud_CLS(x,y,z)
            
            % assert that each input is a 3 element vector
            validateattributes(x, {'numeric'}, {'vector',  'real'});
            validateattributes(y, {'numeric'}, {'vector',  'real'});
            validateattributes(z, {'numeric'}, {'vector',  'real'});
            Nx = numel(x);
            Ny = numel(y);
            Nz = numel(z);
            
            assert((Nx==Ny) & (Nx==Nz), 'HEY: your lists are different lengths !' )
            
            % remove any duplicates from the list
            tmp_A = [x(:), y(:), z(:)];
            tmp_S = num2str(tmp_A,'%.5f  ');
            tmp_C = cellstr(tmp_S);
            [~,tmp_ia,~] = unique(tmp_C);
            if( length(tmp_ia) > 0 )
               fprintf('\n ### ATTENTION: %d duplicte points were removed\n', length(tmp_ia));
               
               x = x(tmp_ia);
               y = y(tmp_ia);
               z = z(tmp_ia);
            end
            
            % OK 
            OBJ.x_col = x(:);
            OBJ.y_col = y(:);
            OBJ.z_col = z(:);
            
            % create an ALPHASHAPE
            OBJ.shp = alphaShape(x(:), y(:), z(:));
            
            OBJ.shp.Alpha = 0.1;
            OBJ.Alpha     = OBJ.shp.Alpha;
            
            % make sure we we have only 1 region
            assert(numRegions(OBJ.shp)==1, 'HEY!:  why more than 1 region');
            
            % compute the centre of mass of the cloud
            cm_x = sum(OBJ.x_col)/length(OBJ.x_col);
            cm_y = sum(OBJ.y_col)/length(OBJ.y_col);
            cm_z = sum(OBJ.z_col)/length(OBJ.z_col);
            OBJ.cm_col = [cm_x; cm_y; cm_z];
        end
        %------------------------------------------------------------------
        function OBJ = set.Alpha(OBJ, val)
            OBJ.shp.Alpha = val;
            OBJ.Alpha     = val;
        end
        %------------------------------------------------------------------
        function plot(OBJ)

            % plot it
            figure;
            subplot(1,2,1);
                scatter3(OBJ.x_col, OBJ.y_col, OBJ.z_col);
                axis equal; grid on; xlabel('X');ylabel('Y');zlabel('Z'); 

            subplot(1,2,2);
                plot(OBJ.shp);
                axis equal; grid on; xlabel('X');ylabel('Y');zlabel('Z'); 
        end
        %------------------------------------------------------------------   
        function [V,M,I] = calc_I_at_cm(OBJ, density)
             
            tri = alphaTriangulation(OBJ.shp); % a Nx4 matrix
            
            Nt = size(tri,1);             % number of tetrahedrons
            Np = size(OBJ.shp.Points,1);  % number of points
            
            cm_row = OBJ.cm_col' ; 
            
            % points relative to Centre of MASS
            Points_rel_to_CM = OBJ.shp.Points - repmat(cm_row, Np,1);
            
            % initialise Inertias so we can accumulate
            Ixx = 0;
            Iyy = 0;
            Izz = 0;
            Ixy = 0;
            Ixz = 0;
            Iyz = 0;
            V   = 0;
            M   = 0;
            
            for kk=1:Nt
                vert_IDs = tri(kk,:);
                
                v1_ID  = vert_IDs(1);  v1_col = Points_rel_to_CM(v1_ID, :)';
                v2_ID  = vert_IDs(2);  v2_col = Points_rel_to_CM(v2_ID, :)';
                v3_ID  = vert_IDs(3);  v3_col = Points_rel_to_CM(v3_ID, :)';
                v4_ID  = vert_IDs(4);  v4_col = Points_rel_to_CM(v4_ID, :)';
                
                tet_obj     = tetra_irreg_CLS(v1_col, v2_col, v3_col, v4_col); 
                cm_of_tet   = tet_obj.get_cm();
                vol_of_tet  = tet_obj.get_volume(); 
               
                dm  = vol_of_tet * density;
               
                V = V + vol_of_tet;
                M = M + dm;
                
                px = cm_of_tet(1);
                py = cm_of_tet(2);
                pz = cm_of_tet(3);
                
                Ixx = Ixx + (py^2 + pz^2)*dm;
                Iyy = Iyy + (px^2 + pz^2)*dm;
                Izz = Izz + (px^2 + py^2)*dm;
                
                Ixy = Ixy + (-1 * px * py * dm); % note the "-1"
                Ixz = Ixz + (-1 * px * pz * dm); % note the "-1"
                Iyz = Iyz + (-1 * py * pz * dm); % note the "-1"
            end % for kk
            
            I = [  Ixx, Ixy, Ixz;
                   Ixy, Iyy, Iyz;
                   Ixz, Iyz, Izz;  ];
               
        end % calc_I_at_cm
        %------------------------------------------------------------------           
    end
    
end % CLASSDEF
%_#########################################################################
%_ HELPER functions
%_#########################################################################

