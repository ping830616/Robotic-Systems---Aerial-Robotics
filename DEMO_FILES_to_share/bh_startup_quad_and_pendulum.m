function bh_startup_quad_and_pendulum()

    % run standard 6-DOF startup
    bh_startup_6dof("NO_DEMO_APP")

    % launch the demo app
    bh_quad_pendulum_app

    fprintf('\n ... we are finished HERE ---> %s\n',mfilename);

end