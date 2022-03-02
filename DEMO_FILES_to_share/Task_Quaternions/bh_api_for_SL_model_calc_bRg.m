function bRg = bh_api_for_SL_model_calc_bRg(q_col)
    OBJ  = bh_rots_PKG.bh_quat_rot_CLS();
    bRg  = OBJ.calc_dcm_from_q(q_col);
end

