function q_dot_col = bh_api_for_SL_model_calc_QDOT(q_col, wb_col)
%coder.extrinsic('bh_rots_PKG.bh_quat_rot_CLS') 

OBJ = bh_rots_PKG.bh_quat_rot_CLS();

q_dot_col = OBJ.calc_qdot_from_wb(q_col, wb_col);

end

