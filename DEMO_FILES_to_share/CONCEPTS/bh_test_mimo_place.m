A = [      0,  1,  0,  0;
      20.601,  0,  0,  0;
           0,  0,  0,  1;
      -0.4905, 0,  0,  0;  ];
  
B = [0,-1,0,0.5]';  

C = [0,0,1,0];

p_des_list = [ (-1 +j*1.732);
               (-1 -j*1.732);
               -5;
               -5.1;
               -5.2;  ];
           
[K_hat, THE_K, THE_Ki] = bh_place_mimo(A,B,C,p_des_list, true)           