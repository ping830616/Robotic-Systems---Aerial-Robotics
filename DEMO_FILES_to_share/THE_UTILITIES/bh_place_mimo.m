function [K_hat, THE_K, THE_Ki] = bh_place_mimo(A,B,C,desired_poles_list, tf_do_plots)
% POLE PLACEMENT using Full state Feedback
%   u = -K.x  + Ki.eta
%
%   u = -[ K,  -Ki].[x  ]
%                   [eta] 
%
%   u = -K_hat     .e
%
%--------------------------------------------------------------------------
% REF:  "Ogata" - Design of type 1 servo system
% 
%    x_dot   = A.x   +   B.u
%    y       = C.x  
% 
%    u       = -K.x  +   Ki.eta
% 
%    eta_dot = r - y 
%            = r - C.x
%
%  So combine these into the system
% 
% [x_dot  ]  = [ (A-B.K),  B.Ki ].[x  ]  +  [0].r
% [eta_dot]    [  -C,      0    ] [eta]     [I]
% 
%        y   =            [C,  0].[x  ]  +  [0].r
%                                 [eta]     [0]
%--------------------------------------------------------------------------

if(nargin==4)
    tf_do_plots = false;
end

Nx = size(A,1);
Nu = size(B,2);
Ny = size(C,1);

% New system has the form:
%
%   e_dot = A_hat.e  +  B_hat.u
%
%       e =  [ x   ]
%            [ eta ] 
%
% Look at contoller of the form:
%
%   u = -K.x  + Ki.eta
%
%   u = -[ K,  -Ki].[x  ]
%                   [eta] 
%   u = -K_hat.e
%

A_hat = [  A,   zeros(Nx,Ny);
          -C,   zeros(Ny,Ny) ];
      
B_hat = [ B;
          zeros(Ny,Nu) ];


% confirm that system is FSFB controllable      
Co = ctrb(A,B); 
if(  rank(Co) ~= Nx )
    error('###_ERROR:  system is rank defficient');
end

% use POLE placement to design a FSFB controller:
%
%     K_hat = [K, -Ki]
%

desired_poles_list = esort(desired_poles_list);

[K_hat, tmp_prec, tmp_message] = place(A_hat, B_hat, desired_poles_list);

% how close did we get ?
actual_poles = pole( ss((A_hat - B_hat*K_hat),[],[],[])  );
actual_poles = esort(actual_poles);

[desired_poles_list,  actual_poles]


% take care of the outputs
THE_K  =    K_hat(:,         1:Nx   );  %  Nu_x_Nx
THE_Ki = -1*K_hat(:,   [(Nx+1):end] );  %  Nu_x_Ny

% should I make plots of the systems STEP response
if(false==tf_do_plots)
    return
end

% so if I'm here ... then YES do some plots
z_wn_list = real(desired_poles_list);
z_wn_list = abs(z_wn_list);

min_z_wn  = min( z_wn_list );
T_final   = 50*  min_z_wn/(2*pi);

% The system that we want to simulate and plot is:
% 
% [x_dot  ]  = [ (A-B.K),  B.Ki ].[x  ]  +  [0].r
% [eta_dot]    [  -C,      0    ] [eta]     [I]
% 
%        y   =            [C,  0].[x  ]  +  [0].r
%                                 [eta]     

A_new     = [(A- B*THE_K),   B*THE_Ki ;
                       -C,    zeros(Ny,Ny) ];
               
B_new     = [ zeros(Nx,Ny);
              eye(Ny)         ];
      
C_new     = [ C, zeros(Ny,Ny) ];

D_new     = [    zeros(Ny,Ny) ] ;

THE_SYS   = ss(A_new, B_new, C_new, D_new);

% this will plot the STEP responses
step( THE_SYS, T_final )

% Do it again to get the T,X arrays
[Ys,Ts,Xs] = step( THE_SYS, T_final );

end % function