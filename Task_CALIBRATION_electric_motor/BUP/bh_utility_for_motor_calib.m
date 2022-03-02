function bh_utility_for_motor_calib( action_str )

switch(upper(action_str))
    case ('LOAD_INIT_AND_STAIRS')
                                  bh_utility_for_motor_calib('LOAD_INIT_MOTOR_PARAMS');
                                  bh_utility_for_motor_calib('LOAD_STAIRS_TS_MEASUREMENT_DATA');
    case ('LOAD_INIT_AND_RAMPS')
                                  bh_utility_for_motor_calib('LOAD_INIT_MOTOR_PARAMS');
                                  bh_utility_for_motor_calib('LOAD_RAMPS_TS_MEASUREMENT_DATA');
    case ('LOAD_FINAL_AND_STAIRS')
                                  bh_utility_for_motor_calib('LOAD_FINAL_MOTOR_PARAMS');
                                  bh_utility_for_motor_calib('LOAD_STAIRS_TS_MEASUREMENT_DATA');
    case ('LOAD_FINAL_AND_RAMPS')
                                  bh_utility_for_motor_calib('LOAD_FINAL_MOTOR_PARAMS');
                                  bh_utility_for_motor_calib('LOAD_RAMPS_TS_MEASUREMENT_DATA');
    case ('LOAD_INIT_MOTOR_PARAMS')
           mot_params_TAB = readtable('bh_MEAS_DATA_MOTOR.xlsx', ...
                                      'Sheet', 'INITIAL_MOTOR_PARAMS', ...
                                      'ReadRowNames',true);
           LOC_send_MOT_params_to_BASE(mot_params_TAB);
           
    case ('LOAD_FINAL_MOTOR_PARAMS')
           mot_params_TAB = readtable('bh_MEAS_DATA_MOTOR.xlsx', ...
                                      'Sheet', 'FINAL_MOTOR_PARAMS', ...
                                      'ReadRowNames',true);
           LOC_send_MOT_params_to_BASE(mot_params_TAB);
           
    case ('LOAD_STAIRS_TS_MEASUREMENT_DATA')
            MOTOR_MEAS_DATA = readtable('bh_MEAS_DATA_MOTOR.xlsx', ...
                                       'Sheet', 'MOTOR_ONLY_STAIRS');
            LOC_send_TS_to_BASE(MOTOR_MEAS_DATA)

    case ('LOAD_RAMPS_TS_MEASUREMENT_DATA')
            MOTOR_MEAS_DATA = readtable('bh_MEAS_DATA_MOTOR.xlsx', ...
                                       'Sheet', 'MOTOR_ONLY_RAMPS');
            LOC_send_TS_to_BASE(MOTOR_MEAS_DATA)
    otherwise
        error('UNKNOWN action string !!');
end
end
%_#########################################################################
% END of MAIN function
%_#########################################################################
function LOC_send_MOT_params_to_BASE(mot_params_TAB)

    b  = mot_params_TAB{'b', 'Value'};
    J  = mot_params_TAB{'J', 'Value'};
    R  = mot_params_TAB{'R', 'Value'};
    L  = mot_params_TAB{'L', 'Value'};
    Ke = mot_params_TAB{'Ke','Value'};
    Ka = mot_params_TAB{'Ka','Value'};

    assignin('base', 'b', b);
    assignin('base', 'J', J);
    assignin('base', 'R', R);
    assignin('base', 'L', L);
    assignin('base', 'Ke', Ke);
    assignin('base', 'Ka', Ka);
end
%==========================================================================
function LOC_send_TS_to_BASE(MOTOR_MEAS_DATA)
    T    = MOTOR_MEAS_DATA.time_secs; 
    V    = MOTOR_MEAS_DATA.IN_VOLTS;
    W    = MOTOR_MEAS_DATA.OUT_W_RAD_PER_SEC;    
    ts   = T(2) - T(1);
    
    V_TS = timeseries(V,T);
    W_TS = timeseries(W,T);
    
    assignin('base', 'V_TS', V_TS);
    assignin('base', 'W_TS', W_TS);
    assignin('base', 'ts',     ts);
end
%==========================================================================


