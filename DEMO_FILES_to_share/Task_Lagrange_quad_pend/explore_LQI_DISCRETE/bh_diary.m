===================================================================
    tmp        = g_Q*[ones(1, Nx+Ny)];
    tmp(19:21) = [0.6,0.6,1400];
    %tmp(21) = 1300;
    Q = diag(tmp); 
    tmp = g_R*[1,1,1,1];  %18b
    R = diag(tmp);     


OK - flys on NON-linear model .... bit wobbly   
WORK_list(1)

ans = 

  struct with fields:

            tf_is_good: 1
                     K: [4×21 double]
                     p: [21×1 double]
    tf_all_inside_unit: 1
               p_first: 1.0000 + 0.0000i
                  K_av: 0.0643
                   g_Q: 0.4000
                   g_R: 66999
-------------------------------------------------------
    tmp        = g_Q*[ones(1, Nx+Ny)];
    tmp(19:21) =     [10,10,100 0];
    Q = diag(tmp); 
    
    tmp  = g_R*[1,1,1,1]; % 19b - LQI uses icare() ... NEW SIMPLICIT SOLVER rolled out in 19a
    R = diag(tmp); 

            tf_is_good: 1
                     K: [4×21 double]
                     p: [21×1 double]
    tf_all_inside_unit: 1
               p_first: 1.0000 + 0.0000i
                  K_av: 0.0697
                   g_Q: 1
                   g_R: 260985