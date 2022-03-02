function [t_col, y_mat] = bh_ode4(f,tspan,y0,options,h)

    t_end      = tspan(2);
    N_steps    = round(t_end/h);
    N          = 1 + N_steps;
    
    t_col      = h * [0:(N-1)]'       ;
    y_mat      = zeros(N, length(y0) );

    y_mat(1,:) = [y0(:)]' ;
    t_col(1)   = 0;
    
    for kk=1:N_steps
        t_kk           =  t_col(kk);
        y_kk           =  y_mat(kk,:)';
        y_next         =  LOC_rk4(f, t_kk, y_kk, h);
        
        y_mat(kk+1, :) = y_next';
    end

end % MAIN function

function y_next = LOC_rk4(f,t,y,h)
    s1 = f(t      ,  y);
    s2 = f(t + h/2,  y + h*s1/2 );
    s3 = f(t + h/2,  y + h*s2/2 );
    s4 = f(t + h  ,  y + h*s3   );

    y_next = y +  (h/6)*( s1 + 2*s2 + 2*s3 + s4);
end











