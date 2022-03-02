function CodeDefine() { 
this.def = new Array();
this.def["CLAW_M_"] = {file: "ert_main_c.html",line:21,type:"var"};this.def["CLAW_MPtr"] = {file: "ert_main_c.html",line:22,type:"var"};this.def["CLAW_B"] = {file: "ert_main_c.html",line:23,type:"var"};this.def["CLAW_DW"] = {file: "ert_main_c.html",line:24,type:"var"};this.def["CLAW_U_XYZ_CMD"] = {file: "ert_main_c.html",line:27,type:"var"};this.def["CLAW_U_SUT_BUS"] = {file: "ert_main_c.html",line:30,type:"var"};this.def["CLAW_Y_Tbz_signed"] = {file: "ert_main_c.html",line:33,type:"var"};this.def["CLAW_Y_Mbz_signed"] = {file: "ert_main_c.html",line:36,type:"var"};this.def["CLAW_Y_wMOT_signed"] = {file: "ert_main_c.html",line:39,type:"var"};this.def["CLAW_Y_CLAW_out"] = {file: "ert_main_c.html",line:42,type:"var"};this.def["rt_OneStep"] = {file: "ert_main_c.html",line:56,type:"fcn"};this.def["main"] = {file: "ert_main_c.html",line:94,type:"fcn"};this.def["CLAW_rtZVEH_AND_PEND_BUS"] = {file: "CLAW_c.html",line:19,type:"var"};this.def["CLAW_prefilter1"] = {file: "CLAW_c.html",line:40,type:"fcn"};this.def["CLAW_prefilter1_Update"] = {file: "CLAW_c.html",line:103,type:"fcn"};this.def["CLAW_step"] = {file: "CLAW_c.html",line:156,type:"fcn"};this.def["CLAW_initialize"] = {file: "CLAW_c.html",line:368,type:"fcn"};this.def["CLAW_terminate"] = {file: "CLAW_c.html",line:412,type:"fcn"};this.def["B_prefilter1_CLAW_T"] = {file: "CLAW_h.html",line:43,type:"type"};this.def["DW_prefilter1_CLAW_T"] = {file: "CLAW_h.html",line:49,type:"type"};this.def["B_CLAW_T"] = {file: "CLAW_h.html",line:55,type:"type"};this.def["DW_CLAW_T"] = {file: "CLAW_h.html",line:66,type:"type"};this.def["ConstB_CLAW_T"] = {file: "CLAW_h.html",line:73,type:"type"};this.def["PEND_BUS"] = {file: "CLAW_types_h.html",line:27,type:"type"};this.def["VEH_AND_PEND_BUS"] = {file: "CLAW_types_h.html",line:45,type:"type"};this.def["RT_MODEL_CLAW_T"] = {file: "CLAW_types_h.html",line:50,type:"type"};this.def["CLAW_ConstB"] = {file: "CLAW_data_c.html",line:20,type:"var"};this.def["_assert"] = {file: "rt_assert_h.html",line:30,type:"fcn"};this.def["int8_T"] = {file: "rtwtypes_h.html",line:47,type:"type"};this.def["uint8_T"] = {file: "rtwtypes_h.html",line:48,type:"type"};this.def["int16_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};this.def["uint16_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};this.def["int32_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};this.def["uint32_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};this.def["real32_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};this.def["real64_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};this.def["real_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};this.def["time_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};this.def["boolean_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};this.def["int_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};this.def["uint_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};this.def["ulong_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};this.def["char_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};this.def["uchar_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};this.def["byte_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};this.def["creal32_T"] = {file: "rtwtypes_h.html",line:78,type:"type"};this.def["creal64_T"] = {file: "rtwtypes_h.html",line:83,type:"type"};this.def["creal_T"] = {file: "rtwtypes_h.html",line:88,type:"type"};this.def["cint8_T"] = {file: "rtwtypes_h.html",line:95,type:"type"};this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:102,type:"type"};this.def["cint16_T"] = {file: "rtwtypes_h.html",line:109,type:"type"};this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:116,type:"type"};this.def["cint32_T"] = {file: "rtwtypes_h.html",line:123,type:"type"};this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:130,type:"type"};this.def["pointer_T"] = {file: "rtwtypes_h.html",line:148,type:"type"};}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["CLAW_c.html"] = "../CLAW.c";
	this.html2Root["CLAW_c.html"] = "CLAW_c.html";
	this.html2SrcPath["CLAW_h.html"] = "../CLAW.h";
	this.html2Root["CLAW_h.html"] = "CLAW_h.html";
	this.html2SrcPath["CLAW_private_h.html"] = "../CLAW_private.h";
	this.html2Root["CLAW_private_h.html"] = "CLAW_private_h.html";
	this.html2SrcPath["CLAW_types_h.html"] = "../CLAW_types.h";
	this.html2Root["CLAW_types_h.html"] = "CLAW_types_h.html";
	this.html2SrcPath["CLAW_data_c.html"] = "../CLAW_data.c";
	this.html2Root["CLAW_data_c.html"] = "CLAW_data_c.html";
	this.html2SrcPath["rt_assert_h.html"] = "../rt_assert.h";
	this.html2Root["rt_assert_h.html"] = "rt_assert_h.html";
	this.html2SrcPath["rt_defines_h.html"] = "../rt_defines.h";
	this.html2Root["rt_defines_h.html"] = "rt_defines_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","CLAW_c.html","CLAW_h.html","CLAW_private_h.html","CLAW_types_h.html","CLAW_data_c.html","rt_assert_h.html","rt_defines_h.html","rtwtypes_h.html"];
