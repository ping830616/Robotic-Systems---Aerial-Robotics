
%% create an example to be used with our tutorial on PRINCIPAL moments of inertia

%% Consider an ellipsoid
% REF: https://en.wikipedia.org/wiki/List_of_moments_of_inertia
m  = 1000; 
ax =   1;  % semiaxes length in X direction
by = 0.5;  % semiaxes length in Y direction
cz = 0.25; % semiaxes length in Z direction

Ip = (m/5)*[ (by^2 + cz^2),           0,                  0;
                   0,           (ax^2 + cz^2),            0;
                   0,                 0,            (ax^2 + by^2);]
 
%% plot it:
[x, y, z] = ellipsoid(0,0,0,ax,by,cz,30);

figure
surf(x, y, z)
axis equal
  hold on
    plot3([0;2], [0;0], [0;0], '-r', 'LineWidth', 2);  hold on
    plot3([0;0], [0;2], [0;0], '-b', 'LineWidth', 2);
    plot3([0;0], [0;0], [0;2], '-g', 'LineWidth', 2);
    axis('equal'); grid('on'); xlabel('X'); ylabel('Y'); zlabel('Z');
    %xlim([-1.5, 1.5]);  ylim([-1.5, 1.5]);  zlim([-1.5, 1.5]);
    title('The B-frame')  

%% Construct a PASSIVE rotation matrix:
%
%  vp = pRb * vb
degs_yaw  = 30; 
degs_pitch= 23;
degs_roll = 45;
apas_OBJ  = bh_rot_passive_G2B_CLS({'D1Z','D2Y','D3X'}, ...
                                   [degs_yaw, degs_pitch, degs_roll], ...
                                   'DEGREES')                                                       
pRb = apas_OBJ.get_R3R2R1();
bRp = pRb.' ;

new_xyz_mat = bRp * [ x(:)' ;
                      y(:)' ;
                      z(:)' ;];
            
N  = size(x,1);                 
nX = reshape(new_xyz_mat(1,:)', N, N);
nY = reshape(new_xyz_mat(2,:)', N, N);      
nZ = reshape(new_xyz_mat(3,:)', N, N);     

 xx = bRp * [2;0;0];
 yy = bRp * [0;2;0];
 zz = bRp * [0;0;2];

figure
  surf(nX, nY, nZ)
  axis equal
  hold on
    plot3([0;xx(1)], [0;xx(2)], [0;xx(3)], '-r', 'LineWidth', 2);  
    plot3([0;yy(1)], [0;yy(2)], [0;yy(3)], '-b', 'LineWidth', 2);  
    plot3([0;zz(1)], [0;zz(2)], [0;zz(3)], '-g', 'LineWidth', 2);  
    axis('equal'); grid('on'); xlabel('X'); ylabel('Y'); zlabel('Z');
    xlim([-1.5, 1.5]);  ylim([-1.5, 1.5]);  zlim([-1.5, 1.5]);
    title('-----')
  
%% So working backwards:
%             Ip = pRb * Ib * pRb.'
%
% therefore:
%             Ib =  pRb' * Ip * pRb
%
format shortG
pRb = bRp';
Ib  = pRb' * Ip * pRb

%% do eigen decomposition

[V, D] = eig(Ib)

%% sort eigenvalues in ASCENDING order
[~,ind] = sort( diag(D) );

D = D(:,ind)
V = V(:,ind)

%% check ORTHONORMALITY

V * V'
%% Construct rotations from eigenvectors
pRb_again = V';

%pRb_again(:,3) = cross(pRb_again(:,1), pRb_again(:,2))

Ip_again = pRb_again * Ib * pRb_again.'

bRp = pRb_again.' ;

%% PLOT it
b_xi_p = bRp * [2;0;0];
b_yi_p = bRp * [0;2;0];
b_zi_p = bRp * [0;0;2];
 
figure
  surf(nX, nY, nZ)
  axis equal
  hold on
    plot3([0;b_xi_p(1)], [0;b_xi_p(2)], [0;b_xi_p(3)], '-r', 'LineWidth', 2);  hold('on');
    plot3([0;b_yi_p(1)], [0;b_yi_p(2)], [0;b_yi_p(3)], '-b', 'LineWidth', 2);  
    plot3([0;b_zi_p(1)], [0;b_zi_p(2)], [0;b_zi_p(3)], '-g', 'LineWidth', 2);  
    axis('equal'); grid('on'); xlabel('X'); ylabel('Y'); zlabel('Z');
    xlim([-1.5, 1.5]);  ylim([-1.5, 1.5]);  zlim([-1.5, 1.5]);
    title('The P-frame')

%% Ensure that our P-frame makes a RIGHT handed co-ordinate frame

bRp(:,3) = cross(bRp(:,1), bRp(:,2))

b_xi_p = bRp * [2;0;0];
b_yi_p = bRp * [0;2;0];
b_zi_p = bRp * [0;0;2];
 
figure
  surf(nX, nY, nZ)
  axis equal
  hold on
    plot3([0;b_xi_p(1)], [0;b_xi_p(2)], [0;b_xi_p(3)], '-r', 'LineWidth', 2);  hold('on');
    plot3([0;b_yi_p(1)], [0;b_yi_p(2)], [0;b_yi_p(3)], '-b', 'LineWidth', 2);  
    plot3([0;b_zi_p(1)], [0;b_zi_p(2)], [0;b_zi_p(3)], '-g', 'LineWidth', 2);  
    axis('equal'); grid('on'); xlabel('X'); ylabel('Y'); zlabel('Z');
    xlim([-1.5, 1.5]);  ylim([-1.5, 1.5]);  zlim([-1.5, 1.5]);
    title('The P-frame')
