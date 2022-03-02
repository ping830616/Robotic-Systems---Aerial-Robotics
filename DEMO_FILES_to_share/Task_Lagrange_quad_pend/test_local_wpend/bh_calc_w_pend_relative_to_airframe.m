function w_pend_rel2air = bh_calc_w_pend_relative_to_airframe(  )

syms        Phi_pend(t)      Theta_pend(t)       Psi_pend(t)    
syms    THE_Phi_pend     THE_Theta_pend      THE_Psi_pend

syms    phi_dot_pend 
syms  theta_dot_pend 
syms    psi_dot_pend


OBJ_P = bh_rot_passive_G2B_CLS({'D1Z', 'D2Y', 'D3X'}, ...
                    [THE_Phi_pend, THE_Theta_pend, THE_Psi_pend], 'SYM');

R1Z = OBJ_P.get_R1;
R2Y = OBJ_P.get_R2;
R3X = OBJ_P.get_R3;

aRv = R1Z;
cRa = R2Y;
pRc = R3X;
wp_part_1 = pRc * cRa * aRv * [0;0;phi_dot_pend];  
wp_part_2 = pRc * cRa *       [0;theta_dot_pend;0]; 
wp_part_3 = pRc *             [psi_dot_pend;0;0];   
 
wp = wp_part_1 + wp_part_2 + wp_part_3;

% We can write the angular velocity vector  as a MATRIX equation
% Let's say that:  , we can write a matrix equation of the form A.x = b that 
% describes the relationship between the body rates  and the Euler rates:    
syms p q r

x = [   phi_dot_pend;
      theta_dot_pend; 
        psi_dot_pend];
    
[A,b] = equationsToMatrix(  wp(1)==p, ...
                            wp(2)==q, ...
                            wp(3)==r, ...
                            x            ); 

                % OLD_list          NEW_list
A     = subs(A, [THE_Phi_pend,    THE_Theta_pend,    THE_Psi_pend   ], ...
                [    Phi_pend(t),     Theta_pend(t),     Psi_pend(t)]   );

e_dot = [ diff(  Phi_pend(t),   t);
          diff(Theta_pend(t),   t); 
          diff(  Psi_pend(t),   t)  ];

w     = A * e_dot;   

w_pend_rel2air = w;

end % function

