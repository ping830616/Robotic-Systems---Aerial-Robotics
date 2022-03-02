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

OBJ_A = bh_rot_active_B2G_CLS({'D1Z', 'D2Y', 'D3X'}, [sym('phi'), sym('theta'), sym('psi')], 'SYM')

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

