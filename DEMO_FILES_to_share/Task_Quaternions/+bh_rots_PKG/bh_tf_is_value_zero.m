function tf_is_zero = bh_tf_is_value_zero(value, method_str)
    arguments 
        value
        method_str (1,1) string  {mustBeMember(method_str,["METHOD_A"])} = "METHOD_A"
    end

    % If the input is SYMBOLIC ... then return a false
    if("sym"==class(value))
        tf_is_zero = false;
        return
    end

    tf_is_zero = false;

    switch(method_str)
        case "METHOD_A"
              tol = 1e-8;
              if(abs(value) < tol)
                 tf_is_zero = true;
              end
        otherwise
            error("###_ERR:  UNknown method ---> LOC_tf_is_theta_zero() ");
    end

end
%--------------------------------------------------------------------------