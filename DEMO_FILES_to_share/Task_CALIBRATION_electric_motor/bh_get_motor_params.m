function [Ka,b,I,R,L,Ke] = bh_get_motor_params( action_str )


switch(upper(action_str))
    case {'INITIAL'}
                    sheet_name = 'INITIAL_MOTOR_PARAMS';
    case {'FINALE'}
                    sheet_name = 'FINAL_MOTOR_PARAMS';
    otherwise
        error('ERROR:  UNknown action string !');
end

mot_params_TAB = readtable('bh_MEAS_DATA_MOTOR.xlsx',  ...
                           'Sheet',        sheet_name, ...
                           'ReadRowNames', true);
                            
% Create separate variables for each parameter:
Ka = mot_params_TAB{'Ka','Value'};
b  = mot_params_TAB{'b', 'Value'};
I  = mot_params_TAB{'I', 'Value'};
R  = mot_params_TAB{'R', 'Value'};
L  = mot_params_TAB{'L', 'Value'};
Ke = mot_params_TAB{'Ke','Value'};

end

