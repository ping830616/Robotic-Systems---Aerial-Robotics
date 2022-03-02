function bh_plot_6dof_solution(T, Z_mat)

Xe     = Z_mat(:,10);
Ye     = Z_mat(:,11);
Ze     = Z_mat(:,12);

phi   = Z_mat(:,7)  * 180/pi;
theta = Z_mat(:,8)  * 180/pi;
psi   = Z_mat(:,9)  * 180/pi;


hax(1) = subplot(3,2,1); plot(T, Xe,'-r'); title('Xe'); ylabel('(m)');
hax(2) = subplot(3,2,3); plot(T, Ye,'-r'); title('Ye'); ylabel('(m)');
hax(3) = subplot(3,2,5); plot(T, Ze,'-r'); title('Ze'); ylabel('(m)');
hax(4) = subplot(3,2,2); plot(T, phi,'-b'); title('phi (YAW)'); ylabel('(deg)');
hax(5) = subplot(3,2,4); plot(T, theta,'-b'); title('theta (PITCH)'); ylabel('(deg)');
hax(6) = subplot(3,2,6); plot(T, psi,'-b'); title('psi (ROLL)'); ylabel('(deg)');

axis(hax,'tight'); 

arrayfun( @(ax)(grid(ax,'on')),            hax  );
arrayfun( @(ax)(xlabel(ax,'time (secs)')), hax  );
%arrayfun( @(ax)(legend(ax,'Location', 'northeast')), hax  );

end
