function w_pend_rel2air = LOC_calc_w_pend_relative_to_airframe(  )

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

% now the symbols that I want my final result to have are:
%   Phi_pend(t)      Theta_pend(t)       Psi_pend(t)
% and their derivatives wrt time

OLD_LIST_pos = [THE_Phi_pend,    THE_Theta_pend,    THE_Psi_pend    ];
NEW_LIST_pos = [    Phi_pend(t),     Theta_pend(t),     Psi_pend(t) ];

OLD_LIST_vel = [     phi_dot_pend,           theta_dot_pend,        psi_dot_pend  ];
NEW_LIST_vel = [diff(Phi_pend(t),t),    diff(Theta_pend(t),t), diff(Psi_pend(t),t)];

OLD_LIST     = [ OLD_LIST_pos, OLD_LIST_vel ];
NEW_LIST     = [ NEW_LIST_pos, NEW_LIST_vel ];

w_pend_rel2air = wp;

w_pend_rel2air = subs(w_pend_rel2air, OLD_LIST, NEW_LIST);


end % function
