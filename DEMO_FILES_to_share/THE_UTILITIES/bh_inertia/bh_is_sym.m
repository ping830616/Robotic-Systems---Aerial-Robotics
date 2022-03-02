function tf_is_sym = bh_is_sym( A )

    tf_is_sym = false;

    if( strcmp('sym',  class(A))   )
        tf_is_sym = true;
    end

end

