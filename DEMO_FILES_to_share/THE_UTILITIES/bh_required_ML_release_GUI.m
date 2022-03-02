function varargout = bh_required_ML_release_GUI(varargin)
% BH_REQUIRED_ML_RELEASE_GUI MATLAB code for bh_required_ML_release_GUI.fig
%      BH_REQUIRED_ML_RELEASE_GUI, by itself, creates a new BH_REQUIRED_ML_RELEASE_GUI or raises the existing
%      singleton*.
%
%      H = BH_REQUIRED_ML_RELEASE_GUI returns the handle to a new BH_REQUIRED_ML_RELEASE_GUI or the handle to
%      the existing singleton*.
%
%      BH_REQUIRED_ML_RELEASE_GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in BH_REQUIRED_ML_RELEASE_GUI.M with the given input arguments.
%
%      BH_REQUIRED_ML_RELEASE_GUI('Property','Value',...) creates a new BH_REQUIRED_ML_RELEASE_GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before bh_required_ML_release_GUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to bh_required_ML_release_GUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help bh_required_ML_release_GUI

% Last Modified by GUIDE v2.5 13-Dec-2016 14:31:48

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @bh_required_ML_release_GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @bh_required_ML_release_GUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before bh_required_ML_release_GUI is made visible.
function bh_required_ML_release_GUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to bh_required_ML_release_GUI (see VARARGIN)

% Choose default command line output for bh_required_ML_release_GUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% BH_ADDITIONS:
hax = handles.TAG_AX_RELEASE;
I = imread('R2016b_LOGO.JPG');
imshow(I,'Parent',hax);

hax = handles.TAG_AX_GREEN;
I = imread('bh_GREEN_ARROW.JPG');
imshow(I,'Parent',hax);

hax = handles.TAG_AX_RED;
I = imread('bh_red_ARROW.JPG');
imshow(I,'Parent',hax);

h_txt = handles.TAG_TXT_RELEASE;
try
     this_rel = version('-release'); 
    
      set(h_txt,'String',this_rel);  
catch
     set(h_txt,'String','???');
end

% UIWAIT makes bh_required_ML_release_GUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = bh_required_ML_release_GUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;
