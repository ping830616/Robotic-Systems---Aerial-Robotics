classdef bh_quad_pendulum_demo_selector_CLS
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        ROOT_FOLDER = '';
        REF_FOLDER  = '';
    end
    
    methods
        function OBJ = bh_quad_pendulum_demo_selector_CLS()
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
        function plot_app_logo_pic(OBJ, hax, ID_STR)
           ID_STR = string(ID_STR);
              if(ID_STR == "PEND")
                  fname = 'bh_QP_3D_pend.JPG';
           elseif(ID_STR == "QUAD")
                  fname = 'bh_QP_quad_SM.JPG';
           elseif(ID_STR == "QUAD_AND_PEND")
                  fname = 'bh_QP_quad_and_pend.JPG';
           else
               error('###_ERROR:  UNknown logo ID string');
           end
                     
           I = imread(fname);
           image(hax,I);
           hax.Visible = 'off';
        end
        %------------------------------------------------------------------        
        function task_button_play_movie(OBJ,ID_STR)
            ID_STR = string(ID_STR);
            ID_STR = upper(ID_STR);
            
            switch(ID_STR)
                case "PEND"
                    fname = 'bh_clip_3d_pend.mp4';
                case "QUAD"
                    %fname = ;
                case "QUAD_AND_PEND"
                    fname = 'bh_clip_quad_and_pend.mp4';
                otherwise
                    error('###_ERROR: UNknown ID_STR !');
            end
                        
            % now play it using Image proc tbox function
            implay(fname);
        end
        
        %_#################################################################
        %    P E N D U L U M     T A B
        %_#################################################################
        function task_PEND_script_derive_eom(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Pend']);
                 edit('bh_derive_LAG_eom_for_3D_pend.mlx');
        end
        %------------------------------------------------------------------
        function task_PEND_script_do_control_design(OBJ)
                 LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Pend']);
                 edit('bh_3d_pend_do_control_design.mlx');
        end
        %------------------------------------------------------------------        
        function task_PEND_model_component(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Pend']);
                 % load some parameters into the workspace
                 evalin('base', 'bh_params_for_3D_pend_control_linearise')
                 
                 % open the model
                 MODEL = 'bh_3d_pend_COMPONENT_MODEL'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
        end
        %------------------------------------------------------------------ 
        function task_PEND_model_for_linearise(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Pend']);
                 % load some parameters into the workspace
                 evalin('base', 'bh_params_for_3D_pend_control_linearise')
                 
                 % open the model
                 MODEL = 'bh_3d_pend_LINEARIZE_harness'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
        end
        %------------------------------------------------------------------ 
        function task_PEND_model_for_simulation(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Pend']);
                 % load some parameters into the workspace
                 evalin('base', 'bh_params_for_3D_pend_sim_CONTROLLED')
                 
                 % open the model
                 MODEL = 'bh_3d_pend_sim_CONTROLLED'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
        end
        %------------------------------------------------------------------ 
        %_#################################################################
        %    Q U A D C O P T E R    T A B
        %_#################################################################
        function task_QUAD_script_derive_eom(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange']);
                 edit('bh_explore_LAG_eom_for_quad_include_spin_props.mlx');
        end
        %------------------------------------------------------------------ 
        function task_QUAD_model_component(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange']);
                 % load some parameters into the workspace
                 evalin('base', 'bh_create_local_params')
                 
                 % open the model
                 MODEL = 'COMPONENT_MDL_Lag_with_spin_rotors'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
        end
        %------------------------------------------------------------------ 
        function task_QUAD_model_LAG_vs_NEWT(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange']);
                 % load some parameters into the workspace
                 evalin('base', 'bh_create_local_params')
                 
                 % open the model
                 MODEL = 'bh_6dof_NEWTON_vs_LAGRANGE'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
        end
        %------------------------------------------------------------------ 
        function task_QUAD_script_do_control_design(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange']);
                 edit('bh_lag_quad_do_control_design.mlx');
        end
        %------------------------------------------------------------------ 
        function task_QUAD_model_LAG_with_LQI(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange']);
                 % load some parameters into the workspace
                 % evalin('base', 'bh_create_local_params');
                 % evalin('base', 'load bh_CONT_DES_RESULTS_LQI_quadcopter.mat');
                 
                 % load some parameters into the workspace
                 evalin('base', 'bh_create_local_params_for_model_LAG_with_LQI');
                 
                 % open the model
                 MODEL = 'bh_lag_LQI_eom_quad_include_spin_props'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
        end
        %------------------------------------------------------------------ 
        function task_QUAD_model_simscape(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange']);
                 % load some parameters into the workspace
                 evalin('base', 'bh_create_local_params');
                 
                 % open the model
                 MODEL = 'bh_SM_quad_and_spin_props'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
        end
        %------------------------------------------------------------------ 
        function task_QUAD_model_LAG_vs_simscape(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange']);
                 % load some parameters into the workspace
                 evalin('base', 'bh_create_local_params');
                 
                 % open the model
                 MODEL = 'bh_compare_SM_vs_HAND_quad_and_spin_props'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
        end
        %------------------------------------------------------------------
        %_#################################################################
        %    Q U A D C O P T E R    A N D     P E N D      T A B
        %_#################################################################
        function task_QP_script_derive_eom(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange_quad_pend']);
                 edit('bh_explore_LAG_eom_for_quad_with_PEND.mlx');
        end
        %------------------------------------------------------------------ 
        function task_QP_model_component(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange_quad_pend']);
                 % load some parameters into the workspace
                 evalin('base', 'bh_create_local_params_QP')
                 
                 % open the model
                 MODEL = 'COMPONENT_MDL_Lag_QUAD_and_PEND_with_spin_rotors'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
        end
        %------------------------------------------------------------------
        function task_QP_script_do_control_design(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange_quad_pend']);
                 edit('bh_lag_quad_and_PEND_do_control_design.mlx');
        end
        %------------------------------------------------------------------ 
        function task_QP_script_do_control_design_DISCRETE(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange_quad_pend']);
                 edit('bh_lag_quad_and_PEND_do_control_design_DISCRETE.mlx');
        end
        %------------------------------------------------------------------ 
        function task_QP_model_LAG_with_LQI(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange_quad_pend']);
                 % load some parameters into the workspace
                 %evalin('base', 'bh_create_local_params_QP');
                 %evalin('base', 'load CONFIRMED_bh_CONT_DES_RESULTS.mat');                
                 
                 % load some parameters into the workspace
                 evalin('base', 'bh_create_local_params_QP_and_CONTROL_LAW');
                                
                 % open the model
                 MODEL = 'bh_lag_LQI_eom_quad_and_PEND_with_spin_props'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
        end
        %------------------------------------------------------------------ 
        function task_QP_model_simscape(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange_quad_pend']);
                 % load some parameters into the workspace
                 %evalin('base', 'bh_create_local_params_QP');
                 %evalin('base', 'load CONFIRMED_bh_CONT_DES_RESULTS.mat');                
                 
                 % load some parameters into the workspace
                 evalin('base', 'bh_create_local_params_QP_and_CONTROL_LAW');
                                                 
                 % open the model
                 MODEL = 'bh_SM_quad_and_PEND'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
        end
        %------------------------------------------------------------------ 
       function task_QP_model_simscape_DISCRETE(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange_quad_pend']);
                 % load some parameters into the workspace
                 %evalin('base', 'bh_create_local_params_QP');
                 %evalin('base', 'load CONFIRMED_bh_CONT_DES_RESULTS.mat');                
                 
                 % load some parameters into the workspace
                 evalin('base', 'bh_create_local_params_QP_and_CONTROL_LAW_DISCRETE');
                                                 
                 % open the model
                 MODEL = 'bh_SM_quad_and_PEND_discrete_CONT'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
       end
       %------------------------------------------------------------------
        function task_QP_model_LAG_vs_simscape(OBJ)
                 %LOC_clear_base();   %LOC_close_M_editor
                 
                 cd([OBJ.ROOT_FOLDER, filesep, 'Task_Lagrange_quad_pend']);
                 % load some parameters into the workspace
                 %evalin('base', 'bh_create_local_params_QP');
                 %evalin('base', 'load CONFIRMED_bh_CONT_DES_RESULTS.mat');                
                 
                 % load some parameters into the workspace
                 evalin('base', 'bh_create_local_params_QP_and_CONTROL_LAW');
                                
                 % open the model
                 MODEL = 'bh_compare_hand_to_SM_quad_pend'; % *.slx
                 open_system(MODEL);
                 h_MD = bdroot;
                 
                 % position model on screen
                 LOC_place_SLMODEL_onscreen(h_MD)               
        end
        %------------------------------------------------------------------
        
        
        
        %_#################################################################
        %    H E L P     T A B
        %_#################################################################
        function task_HELP_open_guide_pres(OBJ)
            PPT_FILE = [OBJ.ROOT_FOLDER, filesep, 'bh_quad_PENDULUM_demo_GUIDE.pptx'];
            PDF_FILE = [OBJ.ROOT_FOLDER, filesep, 'bh_quad_PENDULUM_demo_GUIDE.pdf'];
            
            if exist(PPT_FILE)
                open(PPT_FILE);
                return
            end
            if exist(PDF_FILE)
                open(PDF_FILE);
                return
            end
        end
        %------------------------------------------------------------------
        function task_HELP_open_seminar_pres(OBJ)
            PPT_FILE = [OBJ.ROOT_FOLDER, filesep, 'bh_EDU_Tour_Quad_pend.pptx'];
            PDF_FILE = [OBJ.ROOT_FOLDER, filesep, 'bh_EDU_Tour_Quad_pend.pdf'];
            
            if exist(PPT_FILE)
                open(PPT_FILE);
                return
            end
            if exist(PDF_FILE)
                open(PDF_FILE);
                return
            end
        end
        %------------------------------------------------------------------        
        %_#################################################################
        %    U T I L S     T A B
        %_#################################################################
        function UTILS_open_smd_derivation(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_Lagrange_concept']);
                 
                 edit('bh_smd_model_derivation.mlx')
        end
        %------------------------------------------------------------------
        function UTILS_open_smd_model(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 cd([OBJ.ROOT_FOLDER,filesep,'Task_Lagrange_concept']);
                 
                 open_system('bh_a_spring_mass_model')
        end
        %------------------------------------------------------------------
        function UTILS_show_classes(OBJ)
                 LOC_clear_base();   LOC_close_M_editor
                 
                 edit('bh_lagr4manips_CLS.m', ...
                      'bh_genF4manips_CLS.m');
                  
                 edit('bh_lagr4manips_CLS.m');
        end            
        %------------------------------------------------------------------ 
    end % METHODS
    
end  % CLASSDEF
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

