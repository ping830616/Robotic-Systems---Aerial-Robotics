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

%% Recall our discussion on PASSIVE rotations
% Say we start with a G-frame.  We're going to apply 3 LOCAL axes rotations
% which will result in a newly orientated frame called the B-frame.
%
% Assume that we apply these 3 successive rotations in the following order:
%
% # R1Z occurs 1st about the LOCAL *Z* body axis $(\phi)$, aka *YAW*
% # R2Y occurs 2nd about the LOCAL *Y* body axis $(\theta)$, aka *PITCH*
% # R3X occurs 3rd about the LOCAL *X* body axis $(\psi)$, aka *ROLL*
%
% We can express a vector defined in the G axis into it's corresponding 
% description in the B axis, using a *PASSIVE* rotation matrix, ie:
%
% *|vB = R3X($\psi_x$) * R2Y($\theta_y$) * R1Z($\phi_z$) * vG|* 
% 
% OR, in a more compact form as:
%
% *|vB = bRg * vG|*
%

%% Now define what we mean by ACTIVE rotations
% Continuing on from the previous section, we can now write:
%
% *|vG = $R1Z(\phi_z)^{-1}$  *  $R2Y(\theta_y)^{-1}$  *  $R3X(\psi_x)^{-1}$ * vB|*
%
% *|vG = $R1Z(\phi_z)^{T}$  *  $R2Y(\theta_y)^{T}$  *  $R3X(\psi_x)^{T}$ * vB|*
%
% *|vG = $R1Z(-\phi_z)$  *  $R2Y(-\theta_y)$ *  $R3X(-\psi_x)$ * vB|*
%
% If we now define the following *ACTIVE* rotation matrices:
% 
% # *|a_R1Z($\phi_z$)   = $R1Z(\phi_z)^{-1}$ = $R1Z(- \phi_z)$|*
% # *|a_R2Y($\theta_y$) = $R2Y(\theta_y)^{-1}$ = $R2Y(- \theta_y)$|*
% # *|a_R3X($\psi_x$) = $R3X(\psi_x)^{-1}$ = $R3X(- \psi_x)$|*
%
% Then we can write:
%
% *|vG =  a_R1Z($\phi_z$)  *  a_R2Y($\theta_y$) *  a_R3($\psi_x$) * vB|*
%
% Or in a more compact form:
%
% *|vG =  gRb * vB|*
%
% where it should be clear that:
%
% *|gRb == $(bRg)^{-1}$ == $(bRg)^{T}$|*
%

%% Let's explore these ACTIVE rotations
OBJ_A = bh_rot_active_B2G_CLS({'D1Z', 'D2Y', 'D3X'}, [sym('phi'), sym('theta'), sym('psi')], 'SYM')

%% Here are the ACTIVE rotation matrices
aR1     = OBJ_A.get_active_R1
aR2     = OBJ_A.get_active_R2
aR3     = OBJ_A.get_active_R3

%% Here are some compound ACTIVE rotation matrices - part 1
aR1R2    = aR1*aR2

diff_mat = aR1R2 - OBJ_A.get_active_R1R2 % this should be a ZERO matrix

%% Here are some compound ACTIVE rotation matrices - part 2
aR1R2R3 = aR1*aR2*aR3

diff_mat = aR1R2R3 - OBJ_A.get_active_R1R2R3 % this should be a ZERO matrix

%% Here is ACTIVE rotation matrix $gRb$ 
% Here is the compound ACTIVE rotation matrix:

gRb = aR1*aR2*aR3
%% Recall the PASSIVE rotation matrix $bRg$ 
% Note how the inverse of the *ACTIVE* $gRb$ is just the *PASSIVE* $bRg$ 
% which we computed during our discussion on PASSIVE rotations

bRg = inv(gRb);
simplify(bRg)

%% Define some geometry(co-ordinates) of a vehicle

% this will be the "toy" system that we'll rotate in space
veh_OBJ = bh_vehicle_CLS()

%% Show the vehicle in it's original pose
figure();
hax(1) = subplot(2,2,1);  veh_OBJ.plot_3D(hax(1));
hax(2) = subplot(2,2,2);  veh_OBJ.plot_XY(hax(2));  
hax(3) = subplot(2,2,3);  veh_OBJ.plot_XZ(hax(3));  
hax(4) = subplot(2,2,4);  veh_OBJ.plot_YZ(hax(4));  
  
%% Define the ACTIVE rotation sequence and angles
% We'd like to subject the vehicle to a series of rotations applied to
% a body fixed co-ordinate frame attached to the vehicle.
%
% Assume that we apply these 3 successive rotations in the following order:
%
% # R1Z occurs 1st about the LOCAL *Z* body axis $(\phi)$, aka *YAW*
% # R2Y occurs 2nd about the LOCAL *Y* body axis $(\theta)$, aka *PITCH*
% # R3X occurs 3rd about the LOCAL *X* body axis $(\psi)$, aka *ROLL*
%

degs_yaw  = 90; 
degs_pitch= 30;
degs_roll = 60;
arot_OBJ  = bh_rot_active_B2G_CLS({'D1Z','D2Y','D3X'}, ...
                                  [degs_yaw, degs_pitch, degs_roll], ...
                                  'DEGREES')

%% Now apply this ACTIVE rotation sequence to the vehicle

% get each of the active rotation matrices
aR1 = arot_OBJ.get_active_R1();
aR2 = arot_OBJ.get_active_R2();
aR3 = arot_OBJ.get_active_R3();

% chain them together in the correct ACTIVE order
aR1R2R3 = aR1 * aR2 * aR3;

% get the B frame geometry data of the vehicle
[X,Y,Z] = veh_OBJ.get_B_XYZ();
v_mat   = [ X(:), Y(:), Z(:) ]';  % a 3xN matrix

% now apply the complete ACTIVE rotation matrix to our vehicle data
new_XYZ = aR1R2R3 * v_mat;

% store this new rotated vehicle data
veh_OBJ       =  veh_OBJ.set_G_XYZ(new_XYZ(1,:)', new_XYZ(2,:)', new_XYZ(3,:)');

% store the DCM so that we can draw the body fixed frame
veh_OBJ.gRb = arot_OBJ.get_active_R;

% plot the new rotated vehicle
figure();
hax(1) = subplot(2,2,1);  veh_OBJ.plot_3D(hax(1));
hax(2) = subplot(2,2,2);  veh_OBJ.plot_XY(hax(2));  
hax(3) = subplot(2,2,3);  veh_OBJ.plot_XZ(hax(3));  
hax(4) = subplot(2,2,4);  veh_OBJ.plot_YZ(hax(4));  
title(hax(1), 'THE FINAL pose after active rotations')

%% REPEAT what we just did ... *BUT* let's show the progressive rotations 
veh_OBJ = bh_vehicle_CLS();
figure();
clear hax

% Here's the vehicle in its ORIGINAL pose
hax(1) = subplot(2,2,1);  veh_OBJ.plot_3D(hax(1));
title(hax(1),'Initial VEHICLE pose')

% apply the 1st active rotation
clear veh_OBJ
veh_OBJ = bh_vehicle_CLS();                % ORIG pose is starting point
V_3xN   =  veh_OBJ.get_B_XYZ_3xN();        % get current vehicle data
new_XYZ = arot_OBJ.apply_active_R1(V_3xN); % apply the rotation
veh_OBJ =  veh_OBJ.set_G_XYZ(new_XYZ(1,:)', new_XYZ(2,:)', new_XYZ(3,:)');
gRb     = arot_OBJ.get_active_R1();        % get and store the DCM 
veh_OBJ.gRb = gRb;
% update the vehicle's PLOT
hax(2)  = subplot(2,2,2);  veh_OBJ.plot_3D(hax(2));
str     = sprintf('VEHICLE after yaw R1Z(\\phi = %d^o)',degs_yaw);
title(hax(2),str)

% apply the 2nd active multiplication
clear veh_OBJ
veh_OBJ = bh_vehicle_CLS();                  % ORIG pose is starting point
V_3xN   =  veh_OBJ.get_B_XYZ_3xN();          % get current vehicle data
new_XYZ = arot_OBJ.apply_active_R1R2(V_3xN); % apply the rotation
veh_OBJ =  veh_OBJ.set_G_XYZ(new_XYZ(1,:)', new_XYZ(2,:)', new_XYZ(3,:)');
gRb     = arot_OBJ.get_active_R1R2();
veh_OBJ.gRb = gRb;
% update the vehicle's PLOT
hax(3)  = subplot(2,2,3);  veh_OBJ.plot_3D(hax(3));
str     = sprintf('VEHICLE after pitch R2Y(\\theta = %d^o)',degs_pitch);
title(hax(3),str)

% apply the 3rd active multiplication
clear veh_OBJ
veh_OBJ = bh_vehicle_CLS();                    % ORIG pose is starting point
V_3xN   =  veh_OBJ.get_B_XYZ_3xN();            % get current vehicle data
new_XYZ = arot_OBJ.apply_active_R1R2R3(V_3xN); % apply the rotation
veh_OBJ =  veh_OBJ.set_G_XYZ(new_XYZ(1,:)', new_XYZ(2,:)', new_XYZ(3,:)');
gRb     = arot_OBJ.get_active_R1R2R3();
veh_OBJ.gRb = gRb;   
% update the vehicle's PLOT
hax(4)  = subplot(2,2,4);   veh_OBJ.plot_3D(hax(4));
str     = sprintf('VEHICLE after roll R3X(\\psi = %d^o)',degs_roll);
title(hax(4),str)

%% Let's ANIMATE - part 1
% Let's animate the 3 rotations that we've been playing with.
% In this section you'll *see* the low level steps of how we do this.

veh_OBJ = bh_vehicle_CLS();
figure();
clear hax
hax = axes;

desc_str     = arot_OBJ.get_description();

ANG_1st_FULL = arot_OBJ.ang_1st;
ANG_2nd_FULL = arot_OBJ.ang_2nd;
ANG_3rd_FULL = arot_OBJ.ang_3rd;

% num steps used in animation for each rotation
NUM_STEPS    = 20; 

% angular increments for animation
ANG_1st_step = ANG_1st_FULL / NUM_STEPS; 
ANG_2nd_step = ANG_2nd_FULL / NUM_STEPS; 
ANG_3rd_step = ANG_3rd_FULL / NUM_STEPS ;

% animate the 1st rotation
for kk=0:NUM_STEPS
    inc_arot_OBJ  = bh_rot_active_B2G_CLS(    ...
                           {'D1Z'},           ...
                           [kk*ANG_1st_step], ...
                           'DEGREES');
    clear veh_OBJ
    veh_OBJ = bh_vehicle_CLS();               % ORIG pose is starting point

    V_3xN   =  veh_OBJ.get_B_XYZ_3xN();       % get current vehicle data
    new_XYZ = inc_arot_OBJ.apply_active_R1(V_3xN); % apply the rotation
    veh_OBJ = veh_OBJ.set_G_XYZ(new_XYZ(1,:)',new_XYZ(2,:)',new_XYZ(3,:)');
    gRb     = inc_arot_OBJ.get_active_R1();    % get and store the DCM 
    veh_OBJ.gRb = gRb;
    % update the vehicle's PLOT
    cla(hax);
    veh_OBJ.plot_3D(hax);
    pause(0.1)
end

% animate the 2nd rotation
for kk=0:NUM_STEPS
    inc_arot_OBJ  = bh_rot_active_B2G_CLS( ...
                           {'D1Z','D2Y'}, ...
                           [degs_yaw, kk*ANG_2nd_step], ...
                           'DEGREES');
    clear veh_OBJ
    veh_OBJ = bh_vehicle_CLS();               % ORIG pose is starting point

    V_3xN   =  veh_OBJ.get_B_XYZ_3xN();       % get current vehicle data
    new_XYZ = inc_arot_OBJ.apply_active_R1R2(V_3xN); % apply the rotation
    veh_OBJ = veh_OBJ.set_G_XYZ(new_XYZ(1,:)',new_XYZ(2,:)',new_XYZ(3,:)');
    gRb     = inc_arot_OBJ.get_active_R1R2();   % get and store the DCM 
    veh_OBJ.gRb = gRb;
    % update the vehicle's PLOT
    cla(hax);
    veh_OBJ.plot_3D(hax);
    pause(0.1)
end

% animate the 3rd rotation
for kk=0:NUM_STEPS
    inc_arot_OBJ  = bh_rot_active_B2G_CLS(   ...
                           {'D1Z','D2Y','D3X'}, ...
                           [degs_yaw, degs_pitch, kk*ANG_3rd_step], ...
                           'DEGREES');
    clear veh_OBJ
    veh_OBJ = bh_vehicle_CLS();               % ORIG pose is starting point

    V_3xN   =  veh_OBJ.get_B_XYZ_3xN();       % get current vehicle data
    new_XYZ = inc_arot_OBJ.apply_active_R1R2R3(V_3xN); % apply the rotation
    veh_OBJ = veh_OBJ.set_G_XYZ(new_XYZ(1,:)',new_XYZ(2,:)',new_XYZ(3,:)');
    gRb     = inc_arot_OBJ.get_active_R1R2R3();     % get and store the DCM 
    veh_OBJ.gRb = gRb;
    % update the vehicle's PLOT
    cla(hax);
    veh_OBJ.plot_3D(hax);
    pause(0.1)
end

title(hax, desc_str);

%% Let's ANIMATE - part 2
% Let's animate the 3 rotations that we've been playing with.
% In this section we've concelaed the low level details of the animation
% and coded them into the VEHICLE object.

degs_yaw  = 90; 
degs_pitch= 30;
degs_roll = 60;
arot_OBJ  = bh_rot_active_B2G_CLS({'D1Z','D2Y','D3X'}, ...
                                  [degs_yaw, degs_pitch, degs_roll], ...
                                  'DEGREES');
                              
desc_str     = arot_OBJ.get_description();

% this will be the "toy" system that we'll rotate in space
veh_OBJ = bh_vehicle_CLS();

% now animate it
figure();  hax = axes;

veh_OBJ = veh_OBJ.rotate_and_animate(arot_OBJ, hax);

title(hax, desc_str);
