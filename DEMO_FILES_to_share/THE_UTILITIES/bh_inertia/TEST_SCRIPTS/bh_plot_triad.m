function bh_plot_triad( hax, x_u, y_u, z_u )
    
   if(isempty(hax))
       hax = axes;
   end

   hold('on');
   plot3([0;x_u(1)], [0;x_u(2)], [0;x_u(3)], '-r', 'LineWidth', 2);  
   plot3([0;y_u(1)], [0;y_u(2)], [0;y_u(3)], '-b', 'LineWidth', 2);  
   plot3([0;z_u(1)], [0;z_u(2)], [0;z_u(3)], '-g', 'LineWidth', 2);
   
   axis('equal'); grid('on'); xlabel('Xb'); ylabel('Yb'); zlabel('Zb');
       xlim([-1.5, 1.5]);  ylim([-1.5, 1.5]);  zlim([-1.5, 1.5]);
end

