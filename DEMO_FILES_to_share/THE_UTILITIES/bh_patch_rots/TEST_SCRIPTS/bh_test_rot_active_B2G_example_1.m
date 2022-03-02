%% Explore ACTIVE rotations applied to a BODY-FIXED frame
%
% |Bradley Horton : 01-Mar-2016, bradley.horton@mathworks.com.au|

%% Introduction:
% An *ACTIVE* rotation matrix, moves a point initially defined in it's local *B-frame*,
% to a new location.  This new data point is expressed in the co-ordinates of
% the *G-frame*
%
% An example of this concept is shown below
% 
% <<../PICS_DO_NOT_DELETE/bh_PIC_active_rot_z.PNG>>
% 

%% Define the ACTIVE rotation sequence and angles
% We'd like to subject the vehicle to a series of rotations applied to
% a body fixed co-ordinate frame attached to the vehicle.
%
% The sequence of rotations that we'll apply is:
%
%   a.) R1 occurs 1st about the Z body axis
%   b.) R2 occurs 2nd about the Y body axis
%   c.) R3 occurs 3rd about the X body axis

OBJ_A = bh_rot_active_B2G_CLS({'D1Z','D2Y','D3X'},[90 30 60],'DEGREES')

%% get each of the active rotation matrices
aR1     = OBJ_A.get_active_R1
aR2     = OBJ_A.get_active_R2
aR3     = OBJ_A.get_active_R3

%% here are some compound rotation matrices
aR1R2    = OBJ_A.get_active_R1R2

diff_mat = aR1R2 - aR1*aR2 % this should be a ZERO matrix

%% here are some compound rotation matrices
aR1R2R3 = OBJ_A.get_active_R1R2R3

diff_mat = aR1R2R3 - aR1*aR2*aR3 % this should be a ZERO matrix

%% actively rotate a vector from an initial B position into a final G position
vB    = [1,0,0]';
vG = OBJ_A.apply_active_R1R2R3(vB)

diff_vec = vG - aR1R2R3*vB % this should be a ZERO vector

%% Let's visualize the rotation of the G-frame UNIT vectors

% here are 3 data points in the initial body frame(==the G frame)
point_1_col = [1;0;0];
point_2_col = [0;1;0];
point_3_col = [0;0;1];

vB_init     = [point_1_col,  point_2_col, point_3_col];

% let's rotate each of these data points
vG_result = aR1R2R3 * vB_init;

arrow_xB = vG_result(:,1);
arrow_yB = vG_result(:,2);
arrow_zB = vG_result(:,3);

% and let's visualise the results
hax = axes
axis equal
mArrow3([0 0 0], arrow_xB, 'color', 'red', 'stemWidth',    0.02, 'tipWidth', 0.07);
mArrow3([0 0 0], arrow_yB, 'color', 'blue', 'stemWidth',   0.02, 'tipWidth', 0.07);
mArrow3([0 0 0], arrow_zB, 'color', 'green', 'stemWidth',  0.02, 'tipWidth', 0.07);

text(arrow_xB(1), arrow_xB(2), arrow_xB(3),'X_b')
text(arrow_yB(1), arrow_yB(2), arrow_yB(3),'Y_b')
text(arrow_zB(1), arrow_zB(2), arrow_zB(3),'Z_b')

grid on
xlim([-1 1]);
ylim([-1 1]);
zlim([-1 1]);
xlabel('X', 'FontWeight', 'Bold')
ylabel('Y', 'FontWeight', 'Bold')
zlabel('Z', 'FontWeight', 'Bold')

% set camera view
az = 54;  el = 30; 
view(az, el)
