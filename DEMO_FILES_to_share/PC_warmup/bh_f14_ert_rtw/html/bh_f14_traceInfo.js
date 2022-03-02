function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/u */
	this.urlHashMap["bh_f14:1"] = "ert_main.c:27&bh_f14.c:267";
	/* <Root>/Actuator */
	this.urlHashMap["bh_f14:2"] = "bh_f14.c:274,425,576&bh_f14.h:102,115,128";
	/* <Root>/Angle of 
Attack */
	this.urlHashMap["bh_f14:17"] = "bh_f14.h:85";
	/* <Root>/Gain */
	this.urlHashMap["bh_f14:39"] = "bh_f14.c:303";
	/* <Root>/Gain1 */
	this.urlHashMap["bh_f14:40"] = "bh_f14.c:311";
	/* <Root>/Gain2 */
	this.urlHashMap["bh_f14:41"] = "bh_f14.c:312";
	/* <Root>/Gain5 */
	this.urlHashMap["bh_f14:42"] = "bh_f14.c:181&bh_f14.h:60";
	/* <Root>/Pilot */
	this.urlHashMap["bh_f14:57"] = "bh_f14.c:256,264";
	/* <Root>/Pilot G force
Scope */
	this.urlHashMap["bh_f14:58"] = "bh_f14.h:89";
	/* <Root>/Stick Input */
	this.urlHashMap["bh_f14:59"] = "bh_f14.h:93";
	/* <Root>/Sum */
	this.urlHashMap["bh_f14:60"] = "bh_f14.c:315";
	/* <Root>/Sum1 */
	this.urlHashMap["bh_f14:61"] = "bh_f14.c:266&bh_f14.h:63";
	/* <Root>/alpha (rad) */
	this.urlHashMap["bh_f14:62"] = "ert_main.c:30&bh_f14.c:184";
	/* <Root>/Nz Pilot (g) */
	this.urlHashMap["bh_f14:63"] = "ert_main.c:33&bh_f14.c:250";
	/* <S1>/Alpha-sensor
Low-pass Filter */
	this.urlHashMap["bh_f14:22"] = "bh_f14.c:281,430,579&bh_f14.h:103,116,129";
	/* <S1>/Gain */
	this.urlHashMap["bh_f14:23"] = "bh_f14.c:291";
	/* <S1>/Gain2 */
	this.urlHashMap["bh_f14:24"] = "bh_f14.c:278";
	/* <S1>/Gain3 */
	this.urlHashMap["bh_f14:25"] = "bh_f14.c:279";
	/* <S1>/Pitch Rate
Lead Filter */
	this.urlHashMap["bh_f14:26"] = "bh_f14.c:282,441,585&bh_f14.h:105,118,131";
	/* <S1>/Proportional
plus integral
compensator */
	this.urlHashMap["bh_f14:27"] = "bh_f14.c:292,447,588&bh_f14.h:106,119,132";
	/* <S1>/Stick
Prefilter */
	this.urlHashMap["bh_f14:28"] = "bh_f14.c:283,436,582&bh_f14.h:104,117,130";
	/* <S1>/Sum */
	this.urlHashMap["bh_f14:29"] = "bh_f14.c:290&bh_f14.h:65";
	/* <S1>/Sum1 */
	this.urlHashMap["bh_f14:30"] = "bh_f14.c:280";
	/* <S1>/Sum2 */
	this.urlHashMap["bh_f14:31"] = "bh_f14.c:277&bh_f14.h:64";
	/* <S2>/Constant */
	this.urlHashMap["bh_f14:47"] = "bh_f14.c:242";
	/* <S2>/Derivative */
	this.urlHashMap["bh_f14:48"] = "bh_f14.c:187,210,335,352,565&bh_f14.h:74,75,76,77";
	/* <S2>/Derivative1 */
	this.urlHashMap["bh_f14:49"] = "bh_f14.c:216,239,354,371,572&bh_f14.h:78,79,80,81";
	/* <S2>/Gain1 */
	this.urlHashMap["bh_f14:50"] = "bh_f14.c:243";
	/* <S2>/Gain2 */
	this.urlHashMap["bh_f14:51"] = "bh_f14.c:241&bh_f14.h:62";
	/* <S2>/Product */
	this.urlHashMap["bh_f14:52"] = "bh_f14.c:244";
	/* <S2>/Sum1 */
	this.urlHashMap["bh_f14:53"] = "bh_f14.c:245";
	/* <S3>/Gain3 */
	this.urlHashMap["bh_f14:7"] = "bh_f14.c:304";
	/* <S3>/Gain4 */
	this.urlHashMap["bh_f14:8"] = "bh_f14.c:313";
	/* <S3>/Gain5 */
	this.urlHashMap["bh_f14:9"] = "bh_f14.c:305";
	/* <S3>/Gain6 */
	this.urlHashMap["bh_f14:10"] = "bh_f14.c:314";
	/* <S3>/Sum1 */
	this.urlHashMap["bh_f14:11"] = "bh_f14.c:302&bh_f14.h:67";
	/* <S3>/Sum2 */
	this.urlHashMap["bh_f14:12"] = "bh_f14.c:310&bh_f14.h:68";
	/* <S3>/Transfer Fcn.1 */
	this.urlHashMap["bh_f14:13"] = "bh_f14.c:212,420,569&bh_f14.h:61,101,114,127";
	/* <S3>/Transfer Fcn.2 */
	this.urlHashMap["bh_f14:14"] = "bh_f14.c:177,415,562&bh_f14.h:59,100,113,126";
	/* <S4>/Q-gust model */
	this.urlHashMap["bh_f14:35"] = "bh_f14.c:316,463,595&bh_f14.h:108,121,134";
	/* <S4>/W-gust model */
	this.urlHashMap["bh_f14:36"] = "bh_f14.c:297,453,591&bh_f14.h:66,107,120,133";
	/* <S5>/Output */
	this.urlHashMap["bh_f14:34:1"] = "bh_f14.c:325&bh_f14.h:69";
	/* <S5>/White Noise */
	this.urlHashMap["bh_f14:34:2"] = "bh_f14.c:326,374,598,622&bh_f14.h:82,95";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "bh_f14"};
	this.sidHashMap["bh_f14"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "bh_f14:18"};
	this.sidHashMap["bh_f14:18"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "bh_f14:44"};
	this.sidHashMap["bh_f14:44"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "bh_f14:3"};
	this.sidHashMap["bh_f14:3"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "bh_f14:33"};
	this.sidHashMap["bh_f14:33"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "bh_f14:34"};
	this.sidHashMap["bh_f14:34"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<Root>/u"] = {sid: "bh_f14:1"};
	this.sidHashMap["bh_f14:1"] = {rtwname: "<Root>/u"};
	this.rtwnameHashMap["<Root>/Actuator"] = {sid: "bh_f14:2"};
	this.sidHashMap["bh_f14:2"] = {rtwname: "<Root>/Actuator"};
	this.rtwnameHashMap["<Root>/Angle of  Attack"] = {sid: "bh_f14:17"};
	this.sidHashMap["bh_f14:17"] = {rtwname: "<Root>/Angle of  Attack"};
	this.rtwnameHashMap["<Root>/Controller"] = {sid: "bh_f14:18"};
	this.sidHashMap["bh_f14:18"] = {rtwname: "<Root>/Controller"};
	this.rtwnameHashMap["<Root>/Gain"] = {sid: "bh_f14:39"};
	this.sidHashMap["bh_f14:39"] = {rtwname: "<Root>/Gain"};
	this.rtwnameHashMap["<Root>/Gain1"] = {sid: "bh_f14:40"};
	this.sidHashMap["bh_f14:40"] = {rtwname: "<Root>/Gain1"};
	this.rtwnameHashMap["<Root>/Gain2"] = {sid: "bh_f14:41"};
	this.sidHashMap["bh_f14:41"] = {rtwname: "<Root>/Gain2"};
	this.rtwnameHashMap["<Root>/Gain5"] = {sid: "bh_f14:42"};
	this.sidHashMap["bh_f14:42"] = {rtwname: "<Root>/Gain5"};
	this.rtwnameHashMap["<Root>/Nz pilot calculation"] = {sid: "bh_f14:44"};
	this.sidHashMap["bh_f14:44"] = {rtwname: "<Root>/Nz pilot calculation"};
	this.rtwnameHashMap["<Root>/Pilot"] = {sid: "bh_f14:57"};
	this.sidHashMap["bh_f14:57"] = {rtwname: "<Root>/Pilot"};
	this.rtwnameHashMap["<Root>/Pilot G force Scope"] = {sid: "bh_f14:58"};
	this.sidHashMap["bh_f14:58"] = {rtwname: "<Root>/Pilot G force Scope"};
	this.rtwnameHashMap["<Root>/Plant"] = {sid: "bh_f14:3"};
	this.sidHashMap["bh_f14:3"] = {rtwname: "<Root>/Plant"};
	this.rtwnameHashMap["<Root>/Stick Input"] = {sid: "bh_f14:59"};
	this.sidHashMap["bh_f14:59"] = {rtwname: "<Root>/Stick Input"};
	this.rtwnameHashMap["<Root>/Sum"] = {sid: "bh_f14:60"};
	this.sidHashMap["bh_f14:60"] = {rtwname: "<Root>/Sum"};
	this.rtwnameHashMap["<Root>/Sum1"] = {sid: "bh_f14:61"};
	this.sidHashMap["bh_f14:61"] = {rtwname: "<Root>/Sum1"};
	this.rtwnameHashMap["<Root>/Wind"] = {sid: "bh_f14:33"};
	this.sidHashMap["bh_f14:33"] = {rtwname: "<Root>/Wind"};
	this.rtwnameHashMap["<Root>/alpha (rad)"] = {sid: "bh_f14:62"};
	this.sidHashMap["bh_f14:62"] = {rtwname: "<Root>/alpha (rad)"};
	this.rtwnameHashMap["<Root>/Nz Pilot (g)"] = {sid: "bh_f14:63"};
	this.sidHashMap["bh_f14:63"] = {rtwname: "<Root>/Nz Pilot (g)"};
	this.rtwnameHashMap["<S1>/Stick Input (in)"] = {sid: "bh_f14:19"};
	this.sidHashMap["bh_f14:19"] = {rtwname: "<S1>/Stick Input (in)"};
	this.rtwnameHashMap["<S1>/alpha (rad)"] = {sid: "bh_f14:20"};
	this.sidHashMap["bh_f14:20"] = {rtwname: "<S1>/alpha (rad)"};
	this.rtwnameHashMap["<S1>/q (rad//sec)"] = {sid: "bh_f14:21"};
	this.sidHashMap["bh_f14:21"] = {rtwname: "<S1>/q (rad//sec)"};
	this.rtwnameHashMap["<S1>/Alpha-sensor Low-pass Filter"] = {sid: "bh_f14:22"};
	this.sidHashMap["bh_f14:22"] = {rtwname: "<S1>/Alpha-sensor Low-pass Filter"};
	this.rtwnameHashMap["<S1>/Gain"] = {sid: "bh_f14:23"};
	this.sidHashMap["bh_f14:23"] = {rtwname: "<S1>/Gain"};
	this.rtwnameHashMap["<S1>/Gain2"] = {sid: "bh_f14:24"};
	this.sidHashMap["bh_f14:24"] = {rtwname: "<S1>/Gain2"};
	this.rtwnameHashMap["<S1>/Gain3"] = {sid: "bh_f14:25"};
	this.sidHashMap["bh_f14:25"] = {rtwname: "<S1>/Gain3"};
	this.rtwnameHashMap["<S1>/Pitch Rate Lead Filter"] = {sid: "bh_f14:26"};
	this.sidHashMap["bh_f14:26"] = {rtwname: "<S1>/Pitch Rate Lead Filter"};
	this.rtwnameHashMap["<S1>/Proportional plus integral compensator"] = {sid: "bh_f14:27"};
	this.sidHashMap["bh_f14:27"] = {rtwname: "<S1>/Proportional plus integral compensator"};
	this.rtwnameHashMap["<S1>/Stick Prefilter"] = {sid: "bh_f14:28"};
	this.sidHashMap["bh_f14:28"] = {rtwname: "<S1>/Stick Prefilter"};
	this.rtwnameHashMap["<S1>/Sum"] = {sid: "bh_f14:29"};
	this.sidHashMap["bh_f14:29"] = {rtwname: "<S1>/Sum"};
	this.rtwnameHashMap["<S1>/Sum1"] = {sid: "bh_f14:30"};
	this.sidHashMap["bh_f14:30"] = {rtwname: "<S1>/Sum1"};
	this.rtwnameHashMap["<S1>/Sum2"] = {sid: "bh_f14:31"};
	this.sidHashMap["bh_f14:31"] = {rtwname: "<S1>/Sum2"};
	this.rtwnameHashMap["<S1>/Elevator Command (deg)"] = {sid: "bh_f14:32"};
	this.sidHashMap["bh_f14:32"] = {rtwname: "<S1>/Elevator Command (deg)"};
	this.rtwnameHashMap["<S2>/w"] = {sid: "bh_f14:45"};
	this.sidHashMap["bh_f14:45"] = {rtwname: "<S2>/w"};
	this.rtwnameHashMap["<S2>/q"] = {sid: "bh_f14:46"};
	this.sidHashMap["bh_f14:46"] = {rtwname: "<S2>/q"};
	this.rtwnameHashMap["<S2>/Constant"] = {sid: "bh_f14:47"};
	this.sidHashMap["bh_f14:47"] = {rtwname: "<S2>/Constant"};
	this.rtwnameHashMap["<S2>/Derivative"] = {sid: "bh_f14:48"};
	this.sidHashMap["bh_f14:48"] = {rtwname: "<S2>/Derivative"};
	this.rtwnameHashMap["<S2>/Derivative1"] = {sid: "bh_f14:49"};
	this.sidHashMap["bh_f14:49"] = {rtwname: "<S2>/Derivative1"};
	this.rtwnameHashMap["<S2>/Gain1"] = {sid: "bh_f14:50"};
	this.sidHashMap["bh_f14:50"] = {rtwname: "<S2>/Gain1"};
	this.rtwnameHashMap["<S2>/Gain2"] = {sid: "bh_f14:51"};
	this.sidHashMap["bh_f14:51"] = {rtwname: "<S2>/Gain2"};
	this.rtwnameHashMap["<S2>/Product"] = {sid: "bh_f14:52"};
	this.sidHashMap["bh_f14:52"] = {rtwname: "<S2>/Product"};
	this.rtwnameHashMap["<S2>/Sum1"] = {sid: "bh_f14:53"};
	this.sidHashMap["bh_f14:53"] = {rtwname: "<S2>/Sum1"};
	this.rtwnameHashMap["<S2>/Pilot g force (g)"] = {sid: "bh_f14:54"};
	this.sidHashMap["bh_f14:54"] = {rtwname: "<S2>/Pilot g force (g)"};
	this.rtwnameHashMap["<S3>/Elevator Deflection d (deg)"] = {sid: "bh_f14:4"};
	this.sidHashMap["bh_f14:4"] = {rtwname: "<S3>/Elevator Deflection d (deg)"};
	this.rtwnameHashMap["<S3>/Vertical Gust wGust (ft//sec)"] = {sid: "bh_f14:5"};
	this.sidHashMap["bh_f14:5"] = {rtwname: "<S3>/Vertical Gust wGust (ft//sec)"};
	this.rtwnameHashMap["<S3>/Rotary Gust qGust (rad//sec)"] = {sid: "bh_f14:6"};
	this.sidHashMap["bh_f14:6"] = {rtwname: "<S3>/Rotary Gust qGust (rad//sec)"};
	this.rtwnameHashMap["<S3>/Gain3"] = {sid: "bh_f14:7"};
	this.sidHashMap["bh_f14:7"] = {rtwname: "<S3>/Gain3"};
	this.rtwnameHashMap["<S3>/Gain4"] = {sid: "bh_f14:8"};
	this.sidHashMap["bh_f14:8"] = {rtwname: "<S3>/Gain4"};
	this.rtwnameHashMap["<S3>/Gain5"] = {sid: "bh_f14:9"};
	this.sidHashMap["bh_f14:9"] = {rtwname: "<S3>/Gain5"};
	this.rtwnameHashMap["<S3>/Gain6"] = {sid: "bh_f14:10"};
	this.sidHashMap["bh_f14:10"] = {rtwname: "<S3>/Gain6"};
	this.rtwnameHashMap["<S3>/Sum1"] = {sid: "bh_f14:11"};
	this.sidHashMap["bh_f14:11"] = {rtwname: "<S3>/Sum1"};
	this.rtwnameHashMap["<S3>/Sum2"] = {sid: "bh_f14:12"};
	this.sidHashMap["bh_f14:12"] = {rtwname: "<S3>/Sum2"};
	this.rtwnameHashMap["<S3>/Transfer Fcn.1"] = {sid: "bh_f14:13"};
	this.sidHashMap["bh_f14:13"] = {rtwname: "<S3>/Transfer Fcn.1"};
	this.rtwnameHashMap["<S3>/Transfer Fcn.2"] = {sid: "bh_f14:14"};
	this.sidHashMap["bh_f14:14"] = {rtwname: "<S3>/Transfer Fcn.2"};
	this.rtwnameHashMap["<S3>/Vertical Velocity w (ft//sec)"] = {sid: "bh_f14:15"};
	this.sidHashMap["bh_f14:15"] = {rtwname: "<S3>/Vertical Velocity w (ft//sec)"};
	this.rtwnameHashMap["<S3>/Pitch Rate q (rad//sec)"] = {sid: "bh_f14:16"};
	this.sidHashMap["bh_f14:16"] = {rtwname: "<S3>/Pitch Rate q (rad//sec)"};
	this.rtwnameHashMap["<S4>/Band-Limited White Noise"] = {sid: "bh_f14:34"};
	this.sidHashMap["bh_f14:34"] = {rtwname: "<S4>/Band-Limited White Noise"};
	this.rtwnameHashMap["<S4>/Q-gust model"] = {sid: "bh_f14:35"};
	this.sidHashMap["bh_f14:35"] = {rtwname: "<S4>/Q-gust model"};
	this.rtwnameHashMap["<S4>/W-gust model"] = {sid: "bh_f14:36"};
	this.sidHashMap["bh_f14:36"] = {rtwname: "<S4>/W-gust model"};
	this.rtwnameHashMap["<S4>/Wg"] = {sid: "bh_f14:37"};
	this.sidHashMap["bh_f14:37"] = {rtwname: "<S4>/Wg"};
	this.rtwnameHashMap["<S4>/Qg"] = {sid: "bh_f14:38"};
	this.sidHashMap["bh_f14:38"] = {rtwname: "<S4>/Qg"};
	this.rtwnameHashMap["<S5>/Output"] = {sid: "bh_f14:34:1"};
	this.sidHashMap["bh_f14:34:1"] = {rtwname: "<S5>/Output"};
	this.rtwnameHashMap["<S5>/White Noise"] = {sid: "bh_f14:34:2"};
	this.sidHashMap["bh_f14:34:2"] = {rtwname: "<S5>/White Noise"};
	this.rtwnameHashMap["<S5>/y"] = {sid: "bh_f14:34:3"};
	this.sidHashMap["bh_f14:34:3"] = {rtwname: "<S5>/y"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
