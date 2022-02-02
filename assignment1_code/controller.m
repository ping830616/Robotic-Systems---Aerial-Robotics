function [ u ] = pd_controller(~, s, s_des, params)
%PD_CONTROLLER  PD controller for the height
%
%   s: 2x1 vector containing the current state [z; v_z]
%   s_des: 2x1 vector containing desired state [z; v_z]
%   params: robot parameters

kp = 130;
kv = 20;
u = 0;

z = s(1);
vz = s(2);
z_des = s_des(1);
vz_des = s_des(2);

e = z_des - z;
dot_e = vz_des - vz;
zddot_des = 0;
u = params.mass*(zddot_des + kp*e + kv*dot_e + params.gravity);

end

