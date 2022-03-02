
hax = axes;
xlim([-2.5 2.5])
ylim([-2.5 2.5])
zlim([-2.5 2.5])

axis equal
grid on

xlabel('X', 'FontWeight', 'Bold');
ylabel('Y', 'FontWeight', 'Bold');
zlabel('Z', 'FontWeight', 'Bold');
AlphaColor = 1;

% floor of car
XYZ_dat = [ -1, -0.5, -0.25;
             1, -0.5, -0.25;
             1,  0.5, -0.25;
            -1,  0.5, -0.25;
            ];
        
 X = XYZ_dat(:,1);
 Y = XYZ_dat(:,2);
 Z = XYZ_dat(:,3);
 
 C(1,1,:) = [0,1,0]
 hp(1) = patch(  X,Y, Z, C, 'FaceAlpha', AlphaColor) 
 
 % rear
 XYZ_dat = [ -1, -0.5, -0.25;
             -1, -0.5,  0.25;
             -1,  0.5,  0.25;
             -1,  0.5, -0.25;
           ];
 X = XYZ_dat(:,1);
 Y = XYZ_dat(:,2);
 Z = XYZ_dat(:,3);

 C(1,1,:) = [1,0,0]
 hp(2) = patch(  X,Y, Z, C, 'FaceAlpha', AlphaColor) 

  % side 1
 XYZ_dat = [ -1, -0.5,  0.25;
             -1, -0.5, -0.25;
              1, -0.5, -0.25;
           ];
 X = XYZ_dat(:,1);
 Y = XYZ_dat(:,2);
 Z = XYZ_dat(:,3);

 C(1,1,:) = [0,0,1]
 hp(3) = patch(  X,Y, Z, C, 'FaceAlpha', AlphaColor) 
  % side 2
 XYZ_dat = [ -1, 0.5,  0.25;
             -1, 0.5, -0.25;
              1, 0.5, -0.25;
           ];
 X = XYZ_dat(:,1);
 Y = XYZ_dat(:,2);
 Z = XYZ_dat(:,3);

 C(1,1,:) = [1,1,0]
 hp(4) = patch(  X,Y, Z, C, 'FaceAlpha', AlphaColor) 
 
 % roof of car
XYZ_dat = [ -1, -0.5,  0.25;
            -1,  0.5,  0.25;
             1,  0.5, -0.25;
             1, -0.5, -0.25;
            ];
        
 X = XYZ_dat(:,1);
 Y = XYZ_dat(:,2);
 Z = XYZ_dat(:,3);
 
 C(1,1,:) = [0,1,1]
 hp(5) = patch(  X,Y, Z, C, 'FaceAlpha', AlphaColor) 
 axis equal

 % draw UNIT VECTORS
 mArrow3([0 0 0], [2,0,0], 'color', 'red', 'stemWidth', 0.05);
 mArrow3([0 0 0], [0,2,0], 'color', 'blue', 'stemWidth', 0.05);
 mArrow3([0 0 0], [0,0,2], 'color', 'green', 'stemWidth', 0.05);
 