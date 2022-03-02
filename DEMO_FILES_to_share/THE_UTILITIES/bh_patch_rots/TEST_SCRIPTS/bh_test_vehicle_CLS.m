OBJ = bh_vehicle_CLS()

%% 1st test figure
figure();
hax(1) = subplot(2,2,1);  OBJ.plot_3D(hax(1));
hax(2) = subplot(2,2,2);  OBJ.plot_XY(hax(2));  
hax(3) = subplot(2,2,3);  OBJ.plot_XZ(hax(3));  
hax(4) = subplot(2,2,4);  OBJ.plot_YZ(hax(4));  
  
%% 2nd test figure
[X,Y,Z] = OBJ.get_G_XYZ();
a = 45*pi/180;
R_B2G = [cos(a),  -sin(a),  0;
         sin(a),   cos(a),  0;
              0,        0,  1; ];
          
new_XYZ = R_B2G * [X';
                   Y';
                   Z' ];

OBJ = OBJ.set_G_XYZ(new_XYZ(1,:)', new_XYZ(2,:)', new_XYZ(3,:)');

figure();
hax(1) = subplot(2,2,1);  OBJ.plot_3D(hax(1));
hax(2) = subplot(2,2,2);  OBJ.plot_XY(hax(2));  
hax(3) = subplot(2,2,3);  OBJ.plot_XZ(hax(3));  
hax(4) = subplot(2,2,4);  OBJ.plot_YZ(hax(4));  

