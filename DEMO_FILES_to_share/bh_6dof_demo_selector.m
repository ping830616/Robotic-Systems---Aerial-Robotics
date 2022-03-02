classdef bh_6dof_demo_selector
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        ROOT_FOLDER = '';
        REF_FOLDER  = '';
    end
    
    methods
        function OBJ = bh_6dof_demo_selector()
            p = mfilename('fullpath');
            [pathstr,~,~] = fileparts(p);
            OBJ.ROOT_FOLDER = pathstr;
            OBJ.REF_FOLDER  = pathstr;
        end
        %------------------------------------------------------------------
        function clear_base(OBJ)
            LOC_clear_base();
        end
        %------------------------------------------------------------------
        function close_editor(OBJ)
            LOC_close_M_editor();
        end
        %------------------------------------------------------------------
        function open_pres(OBJ)
            PPT_FILE = [OBJ.ROOT_FOLDER, filesep, 'bh_quadcopt_pres.pptx'];
            PDF_FILE = [OBJ.ROOT_FOLDER, filesep, 'bh_quadcopt_pres.pdf'];
            
            if exist(PPT_FILE)
                open(PPT_FILE);
                return
            end
            if exist(PDF_FILE)
                open(PDF_FILE);
                return
            end
                       
        end % open_pres
        %------------------------------------------------------------------
        function do_pc_warmup(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'PC_warmup']);
                 
                 bh_pc_warmup_test % run warmup script
                 
                 bdclose('bh_f14')
                 helpdlg('WARMUP done !');
                 
                 LOC_clear_base();
        end
        %------------------------------------------------------------------    
        function open_resources(OBJ, action_str);
        
            switch(upper(action_str))
                case {'COURSEWARES_WEB'}
                     web('http://au.mathworks.com/academia/courseware/', '-browser');
                case {'COURSEWARES_LOCAL'}
                     system('explorer C:\Users\bhorton\Desktop\COURSEWARES');
                case {'ONRAMP'}
                     web('https://matlabacademy.mathworks.com/', '-browser');
                case {'HARDWARE_SUPPORT'}
                     web('http://au.mathworks.com/hardware-support/home.html', '-browser');
                     %web('http://makerzone.mathworks.com/', '-browser');
                case {'HELLO'}
                    % do nothing
                otherwise
                     error('###_UNKNOWN action string !');
            end
                    
        end
        %------------------------------------------------------------------    
        function position_all_MD_on_screen(OBJ)
            h_MD_list = find_system('type','block_diagram');
            % don't preocess library blockdiagrams
            isLib     = bdIsLibrary(h_MD_list);
            h_MD_list = h_MD_list(~isLib);
            %OK, so we should only have models (NOT libraries) left.
            for kk=1:length(h_MD_list)
                hMD = h_MD_list(kk);
                if(iscell(hMD))
                    hMD = hMD{1};
                end
                LOC_place_SLMODEL_onscreen(hMD)
            end
        end
        %------------------------------------------------------------------
        function task_begin_at_end(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'THE_FINAL_MODELS']);
                 
                 load_system('bh_6dof_LIBRARY')
                 evalin('base', 'bh_quad_params;')
                 MODEL = 'bh_6dof_with_motors_CONFIG_3';
                 
                 % open the model
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)
                 
                 % if the model had any opened TABS ... then close them
                 LOC_close_all_but_root_level_of_model(h_MD)
                 
                 sys_1  = sprintf('%s/CONT_SYS\nForce_Moment_CMDS',MODEL);
                 sys_2  = sprintf('%s/CONT_SYS\nW_MOT_CMDS',MODEL);
                 sys_3  = sprintf('%s/Gyroscopic\nmoments',MODEL);
                 sys_4  = sprintf('%s/PLANT\nVEHICLE_SYS/bh_6DOF (Euler Angles)',MODEL);
                 sys_5f = sprintf('%s/PLANT\nVEHICLE_SYS/bh_6DOF (Euler Angles)',MODEL);
                 sys_6 = sprintf('%s/EYES',MODEL);
                 
                 open_system(MODEL, 'tab');
                 open_system(sys_1, 'tab');
                 open_system(sys_2, 'tab');
                 open_system(sys_3, 'tab');
                 open_system(sys_4, 'tab');
                 open_system(sys_5f, 'force');
                 open_system(sys_6, 'tab');
                 open_system([sys_6,'/EYES_ONE']);
                 LOC_place_scope_on_screen( 'EYES_ONE' );
                 
                 open_system(MODEL, 'tab'); % bring Model tab into focus              
        end
        %------------------------------------------------------------------
        function task_principal_inertias(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_PRINCIPAL_moments_of_inertia']);
                 edit('bh_task_principal_I.mlx')
        end
        %------------------------------------------------------------------
        function task_euler_rates(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_EULER_rates']);
                 edit('bh_task_explore_euler_rates_CONCEPT.mlx')
        end
        %------------------------------------------------------------------    
        function task_dcm_derivative(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_DCM_derivative']);
                 edit('bh_task_DCM_derivative.mlx')
        end
        %------------------------------------------------------------------    
        function task_quaternion(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_Quaternions']);
                 edit('bh_task_quaternions.mlx');
        end
        %------------------------------------------------------------------    
        function task_integrate_ode(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_INTEGRATE']);
                 edit('bh_task_integrate_6dof_MATLAB.mlx', ...
                      'bh_the_6dof_eoms.m', ...
                      'bh_ode4.m');
                 edit('bh_task_integrate_6dof_MATLAB.mlx'); 
        end
        %------------------------------------------------------------------           
        function task_calibrate_F_and_TQ(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_CALLIBRATION_FORCE_TORQUE']);
                 edit('bh_task_do_F_and_TQ_calibration.mlx');
        end
        %------------------------------------------------------------------        
        function task_CALIBRATION_electric_motor(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_CALIBRATION_electric_motor']);
                 edit('bh_task_do_motor_calibration.mlx');
                 
                 %hMD = 'bh_motor_for_param_estimation.slx';
                 hMD = 'bh_motor_for_param_estimation';
                 open_system(hMD);
                 LOC_place_SLMODEL_onscreen(hMD)
        end
        %------------------------------------------------------------------ 
        function task_linearize_and_control(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_LINEARISE']);
                 %edit('bh_task_find_trim_and_linearise.mlx', ...
                 %     'bh_task_siso_control_design.mlx');
                 edit('bh_task_find_trim_and_linearise_and_contDESIGN.mlx');
                 
                  evalin('base', 'bh_quad_params;')
                  open_system('bh_linearise_6dof_multiple_PORTS')
        end        
        %------------------------------------------------------------------ 
        function task_final_models(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'THE_FINAL_MODELS']);
                 
                 evalin('base', 'bh_quad_params;')
                 open_system('bh_6dof_with_motors_CONFIG_3');
        end
        %------------------------------------------------------------------ 
        function task_code_generation(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_DISCRETISE_and_CODE_GEN']);
                 
                 evalin('base', 'bh_quad_params;');
                 evalin('base', 'THE_MEAS_BUS_DEF');
                 open_system('bh_6DOF_DISC_codegen');
        end
        %------------------------------------------------------------------ 
        function open_report(OBJ, ID_str)
           
           % my database
           LUP_CE = ...
            {'PRINCIPAL_INERTIA', 'bh_task_principal_I.pdf', [OBJ.ROOT_FOLDER, filesep, 'Task_PRINCIPAL_moments_of_inertia'];
             'EULER_RATES',       'bh_task_explore_euler_rates_CONCEPT.pdf', [OBJ.ROOT_FOLDER, filesep, 'Task_EULER_rates'];
             'DCM_DERIVATIVE',    'bh_task_DCM_derivative.pdf', [OBJ.ROOT_FOLDER, filesep, 'Task_DCM_derivative'];
             'CALIBRATE_TQ_F',    'bh_task_do_F_and_TQ_calibration.pdf', [OBJ.ROOT_FOLDER, filesep,'Task_CALLIBRATION_FORCE_TORQUE'];
             'CALIBRATE_MOTOR',   'bh_task_do_motor_calibration.pdf', [OBJ.ROOT_FOLDER, filesep,'Task_CALIBRATION_electric_motor'];
             'SOLVING_ODES',      'bh_task_integrate_6dof_MATLAB.pdf',[OBJ.ROOT_FOLDER, filesep,'Task_INTEGRATE'];
             'CONTROL_LINEARIZE', 'bh_task_find_trim_and_linearise.pdf',[OBJ.ROOT_FOLDER, filesep,'Task_LINEARISE'];
             'CONTROL_DESIGN',    'bh_task_siso_control_design.pdf', [OBJ.ROOT_FOLDER, filesep,'Task_LINEARISE'];
             'PASSIVE_ROTATIONS', 'bhLIVE_TUT_rot_passive_G2B_example_1_CONCEPT.pdf', [OBJ.ROOT_FOLDER, filesep,'THE_UTILITIES',filesep,'bh_patch_rots',filesep,'TEST_SCRIPTS'];
             'ACTIVE_ROTATIONS',  'bhLIVE_TUT_rot_ACTIVE_B2G_example_1_CONCEPT.pdf', [OBJ.ROOT_FOLDER, filesep,'THE_UTILITIES',filesep,'bh_patch_rots',filesep,'TEST_SCRIPTS'];
             'PARALLEL_AXIS',     'bh_TUT_parallel_I.pdf', [OBJ.ROOT_FOLDER, filesep,'THE_UTILITIES',filesep,'bh_inertia',filesep,'TEST_SCRIPTS'];
             '3_BLADED_PROPELLER','bh_TUT_3blade_propeller.pdf', [OBJ.ROOT_FOLDER, filesep,'THE_UTILITIES',filesep,'bh_inertia',filesep,'TEST_SCRIPTS'];
            };
            % does ID_str exist in the database
            ID_tf_list = strcmp(LUP_CE(:,1), ID_str);
            
            if( ~any(ID_tf_list) )
                tmp_str = fprintf('Could NOT find report ID --->\n %s',ID_str);
                warndlg(tmp_str);
                return
            end
            
            % get file and folder
            kidx         = find(ID_tf_list);
            file_str     = LUP_CE{kidx, 2};
            folder_str   = LUP_CE{kidx, 3};
            fullfile_str = [folder_str, filesep, file_str];
            
            % try and open the file
            try
                  open(fullfile_str);
            catch
                  tmp_str = fprintf('Could NOT open FILE --->\n %s',file_str);
                  warndlg(tmp_str);
                  return
            end
        end % open_report
        %------------------------------------------------------------------ 
    end
    
end
%_#########################################################################
function LOC_clear_base()
   evalin('base', 'clear all; clc')
end
%**************************************************************************
function LOC_close_M_editor
%close the M-file Editor
  evalin('base',['com.mathworks.mlservices.MatlabDesktopServices.getDesktop().closeGroup(''Editor'')']);
end
%**************************************************************************
function LOC_place_SLMODEL_onscreen(hMD)

    % what is the maxscreensize of the COMPUTER
    scr_max_pos    = get(0,'ScreenSize');
    scr_max_width  = scr_max_pos(3);
    scr_max_height = scr_max_pos(4);

    tgt_md_width  = 0.8*scr_max_width;
    tgt_md_height = 0.8*scr_max_height;

    % what is current MODEL window location
    md_Loc = get_param(hMD,'Location');

    % set the new MODEl location
    set_param(hMD,'Location',[20 20 tgt_md_width tgt_md_height]);
end
%**************************************************************************
function  LOC_place_scope_on_screen( scope_name )
    h = findall(0,'Type', 'figure', 'Name', scope_name);
    if(isempty(h))
        return
    end
    
    h(1).Position = [2 41 647 634];   
end
%**************************************************************************
function  LOC_close_all_but_root_level_of_model(THE_MODEL)
    Blocks_List = find_system(THE_MODEL);
    Blocks_To_Close = Blocks_List;

    for III=length(Blocks_List):-1:1
        if isempty(strfind(Blocks_List{III},'/'))
            Blocks_To_Close(III)=[];
        end
    end

    close_system(Blocks_To_Close)
end
%**************************************************************************

