function  bh_plot_tfm( TFM_TAB )

T    = @()(TFM_TAB.Time);
Fb_X = @()(TFM_TAB.Fb_X);
Fb_Y = @()(TFM_TAB.Fb_Y);
Fb_Z = @()(TFM_TAB.Fb_Z);
Mb_X = @()(TFM_TAB.Mb_X);
Mb_Y = @()(TFM_TAB.Mb_Y);
Mb_Z = @()(TFM_TAB.Mb_Z);

hax(1) = subplot(3,2,1); plot(T(),Fb_X(),'-r'); title('Fb_X'); ylabel('(N)');
hax(2) = subplot(3,2,3); plot(T(),Fb_Y(),'-r'); title('Fb_Y'); ylabel('(N)');
hax(3) = subplot(3,2,5); plot(T(),Fb_Z(),'-r'); title('Fb_Z'); ylabel('(N)');
hax(4) = subplot(3,2,2); plot(T(),Mb_X(),'-b'); title('Mb_X'); ylabel('(N.m)');
hax(5) = subplot(3,2,4); plot(T(),Mb_Y(),'-b'); title('Mb_Y'); ylabel('(N.m)');
hax(6) = subplot(3,2,6); plot(T(),Mb_Z(),'-b'); title('Mb_Z'); ylabel('(N.m)');

axis(hax,'tight'); 

arrayfun( @(ax)(grid(ax,'on')),            hax  );
arrayfun( @(ax)(xlabel(ax,'time (secs)')), hax  );
%arrayfun( @(ax)(legend(ax,'Location', 'northeast')), hax  );
end

