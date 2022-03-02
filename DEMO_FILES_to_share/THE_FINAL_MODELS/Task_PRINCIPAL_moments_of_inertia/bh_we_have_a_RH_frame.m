function V_mat = bh_we_have_a_RH_frame(V_mat)

    tmp_3 = cross( V_mat(:,1), V_mat(:,2) );
    % CHECK RH co-ordinate frame - part 1
    tmp_diff = tmp_3 - V_mat(:,3);
    tmp_mag  = norm(tmp_diff);

    if( tmp_mag < 1e-7 )
        fprintf('\n ... yep V gives us a RH rule frame !');
    else
        warning('HEY!: I am modifying V, so I have a RH frame');
        V_mat(:,3) = tmp_3;
    end

    % CHECK RH co-ordinate frame - part 2
    VT = V_mat';
    tmp_3 = cross(VT(:,1), VT(:,2) );
    tmp_diff = tmp_3 - VT(:,3);
    tmp_mag  = norm(tmp_diff);
    if( tmp_mag > 1e-7 )
        error('HEY!: I do not think you have a RH co-ordinate frame ?');
    end    
      
end

