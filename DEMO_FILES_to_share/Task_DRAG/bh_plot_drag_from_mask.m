function bh_plot_drag_from_mask( the_GCB )

% ATTENTION:
% we expect the Mask to have parameters callde  A,Cd,rho

OBJ = Simulink.Mask.get(the_GCB);

a_struct = OBJ.getWorkspaceVariables;

name_list = {a_struct.Name};
value_list= {a_struct.Value};

% convert name_list to a STRING array ..they're easier to manipulate
STR_list = string(name_list);

ind = find("Cd"==STR_list);
Cd  = value_list{ind};

ind = find("rho"==STR_list);
rho = value_list{ind};

ind = find("A"==STR_list);
A   = value_list{ind};

% construct a func handle
F_fh = @(v) (0.5*A*rho*Cd*v.^2);

% now do the plot
figure
subplot(2,1,1);
    v = [0:0.1:2];
    F = F_fh(v);
    plot(v,F,'.r-');
    axis('tight'); grid('on');
    xlabel('VEL (m/sec)');
    ylabel('Drag FORCE (N)');
subplot(2,1,2);
    v = [2:0.1:10];
    F = F_fh(v);
    plot(v,F,'.b-');
    axis('tight'); grid('on');
    xlabel('VEL (m/sec)');
    ylabel('Drag FORCE (N)');


fprintf('\n ... done !');

end

