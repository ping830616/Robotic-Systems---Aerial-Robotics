
w_pend_A = bh_calc_w_pend_relative_to_airframe(  );

w_pend_B =LOC_calc_w_pend_relative_to_airframe(  );

the_diff = w_pend_A - w_pend_B

simplify(the_diff)