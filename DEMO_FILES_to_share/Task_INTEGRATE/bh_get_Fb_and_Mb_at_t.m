function [Fb_and_Mb] = bh_get_Fb_and_Mb_at_t( t, TFM_TAB )

    T    = @()(TFM_TAB.Time);
    Fb_X = @()(TFM_TAB.Fb_X);
    Fb_Y = @()(TFM_TAB.Fb_Y);
    Fb_Z = @()(TFM_TAB.Fb_Z);
    Mb_X = @()(TFM_TAB.Mb_X);
    Mb_Y = @()(TFM_TAB.Mb_Y);
    Mb_Z = @()(TFM_TAB.Mb_Z);


    Fb = zeros(3,1);
    Mb = zeros(3,1);

    method = 'linear'; %'linear';  % 'pchip'
    
    Fb(1) = interp1( T(), Fb_X(), t, method);
    Fb(2) = interp1( T(), Fb_Y(), t, method);
    Fb(3) = interp1( T(), Fb_Z(), t, method);

    Mb(1) = interp1( T(), Mb_X(), t, method);
    Mb(2) = interp1( T(), Mb_Y(), t, method);
    Mb(3) = interp1( T(), Mb_Z(), t, method);

    Fb_and_Mb = [ Fb;
                  Mb ];   
end

