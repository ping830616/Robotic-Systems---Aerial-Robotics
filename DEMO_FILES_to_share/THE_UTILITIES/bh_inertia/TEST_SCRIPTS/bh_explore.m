%% create an example to be used with our tutorial on PRINCIPAL moments of inertia

%% Consider an ellipsoid
% REF: https://en.wikipedia.org/wiki/List_of_moments_of_inertia
ax =   1;  % semiaxes length in X direction
by = 0.5;  % semiaxes length in Y direction
cz = 0.25; % semiaxes length in Z direction

vol     = pi*(4/3)*ax*by*cz % volume of ellipsoid
m       = 1000; 
density = m/vol;


Ip = (m/5)*[ (by^2 + cz^2),           0,                  0;
                   0,           (ax^2 + cz^2),            0;
                   0,                 0,            (ax^2 + by^2);]
 
%% Plot the Ellipsoid:
[x, y, z] = ellipsoid(0,0,0,ax,by,cz,30);

figure
  surf(x, y, z)
    axis equal
    hold on
  % DOUBLE unit vectors for plots                 
     xu = [2;0;0];
     yu = [0;2;0];
     zu = [0;0;2];
  plot3([0;xu(1)], [0;xu(2)], [0;xu(3)], '-r', 'LineWidth', 2);  
  plot3([0;yu(1)], [0;yu(2)], [0;yu(3)], '-b', 'LineWidth', 2);  
  plot3([0;zu(1)], [0;zu(2)], [0;zu(3)], '-g', 'LineWidth', 2);  
    axis('equal'); grid('on'); xlabel('X'); ylabel('Y'); zlabel('Z');
    xlim([-1.5, 1.5]);  ylim([-1.5, 1.5]);  zlim([-1.5, 1.5]);
    title('ORIGINAL ellipse')  

%% cleanup
clear x y z

%% Calculate an APPROXIMATION  for the Inertia matrix

% generate a list of random data points
rng(0);
Nrand  = 20000;
x_list = -ax + (2*ax)*rand(Nrand,1);  %r = a + (b-a).*rand(N,1)
y_list = -by + (2*by)*rand(Nrand,1);
z_list = -cz + (2*cz)*rand(Nrand,1);

% only keep the points inside our ellipse
tmp   = (x_list.^2)/(ax^2) + (y_list.^2)/(by^2) + (z_list.^2)/(cz^2);
ind    = abs(tmp) <=1;

x_list = x_list(ind);
y_list = y_list(ind);
z_list = z_list(ind);

% create an INERTIA_FROM_CLOUD object
OBJ_IFC = inertia_from_cloud_CLS(x_list, y_list, z_list);
OBJ_IFC.Alpha = 0.2;

% plot it
OBJ_IFC.plot();

% calculate the approximations for the VOLUME, MASS and INERTIA matrix
[V,M,I] = OBJ_IFC.calc_I_at_cm(density)

% extract the actual CLOUD data points
x_cloud_col = OBJ_IFC.x_col;
y_cloud_col = OBJ_IFC.y_col;
z_cloud_col = OBJ_IFC.z_col;




