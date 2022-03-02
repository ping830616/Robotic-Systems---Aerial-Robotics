%       O   A    B   C    D   E    F    G   H     I    J    K    L    O
X_WP = [0,  5,  25,  25   5,  5,  25,  25,  5,    5,  25,  25,   0,   0];
Y_WP = [0,  5,   5,  10, 10, 15,  15   20, 20,   25,  25,  30,  30,   0];
T_WP = [0,  7,  27,  32, 52, 57,  77,  82, 102, 107, 127, 132, 157, 187];

XBC_DOT = [0, 0];
YBC_DOT = [0, 0];
%% plot it

X = X_WP;
Y = Y_WP;
T = T_WP;
figure;
subplot(3,1,1); plot(X, Y, '.r-', 'LineWidth', 2);
                axis tight; grid on; xlabel('X (m)'); ylabel('Y (m)');
subplot(3,1,2); plot(T, X, '.r-', 'LineWidth', 2);
                axis tight; grid on; xlabel('time (secs)'); ylabel('X (m)'); 
subplot(3,1,3); plot(T, Y, '.r-', 'LineWidth', 2);
                axis tight; grid on; xlabel('time (secs)'); ylabel('Y (m)');                
                
%% a simple interp
t_vec = T_WP(1): 0.1:T_WP(end);

x_vec = interp1(T_WP, X_WP, t_vec, 'pchip');
y_vec = interp1(T_WP, Y_WP, t_vec, 'pchip');

X = x_vec;
Y = y_vec;
T = t_vec;

figure;
subplot(3,1,1); plot(X, Y, '.r-', 'LineWidth', 2);
                axis tight; grid on; xlabel('X (m)'); ylabel('Y (m)');
subplot(3,1,2); plot(T, X, '.r-', 'LineWidth', 2);
                axis tight; grid on; xlabel('time (secs)'); ylabel('X (m)'); 
subplot(3,1,3); plot(T, Y, '.r-', 'LineWidth', 2);
                axis tight; grid on; xlabel('time (secs)'); ylabel('Y (m)');                
                
                
                