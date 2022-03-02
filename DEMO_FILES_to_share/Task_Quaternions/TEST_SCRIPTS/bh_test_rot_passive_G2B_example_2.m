%% Explore PASSIVE rotations which convert a G vec into a B vec
%
% |Bradley Horton : 01-Mar-2016, bradley.horton@mathworks.com.au|

%% Introduction:
% A Passive rotation matrix, converts the co-ordinates of a point expressed
% in a fixed *G-frame*, into the co-ordinates of the same point expressed in
% the new *B-frame*. 
%
% An example of this concept is shown below
% 
% <<../PICS_DO_NOT_DELETE/bh_PIC_passive_rot_z.PNG>>
% 

%% An example of 3 successive PASSIVE rotations
% Say we start with a G-frame.  We're going to apply 3 local axes rotations
% which will result in a newly orientated frame called the B-frame.
%
% Assume that we apply these 3 successive rotations in the following order:
%
%   a.) R1 occurs 1st about some LOCAL body axis
%   b.) R2 occurs 2nd about some LOCAL body axis
%   c.) R3 occurs 3rd about some LOCAL body axis
%
% We can convert a vector defined in the G axis to it's corresponding 
% description in the B axis, using a PASSIVE rotation matrix, ie:
%
%    vB = R3 * R2 * R1 * vG
%    vB = R * vG

%% Create a passive rotation object
%OBJ_A = bh_rot_passive_G2B_CLS({'D1Z', 'D2Y', 'D3X'}, [30 20 10],'DEGREES')
OBJ_A = bh_rot_passive_G2B_CLS({'D1Z'}, [30 ],'DEGREES')

%% Here are the PASSIVE rotation matrices
R1 = OBJ_A.get_R1
R2 = OBJ_A.get_R2
R3 = OBJ_A.get_R3

%% Convert a vector in G, into its components in B
vG    = [1,0,0]';
vB    = R3*R2*R1* vG

%% Let's visualize this
R_G2B = R3*R2*R1;
OBJ_disp = bh_disp_vec_CLS(vG, R_G2B);
figure; 
hax(1) = axes;  OBJ_disp.plot_3D_with_PROJ(hax(1));

