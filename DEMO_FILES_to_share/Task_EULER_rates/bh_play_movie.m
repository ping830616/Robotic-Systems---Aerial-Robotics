function bh_play_movie

    p = mfilename('fullpath');
    [folder,name,ext] = fileparts(p);

    winopen([folder,filesep,'bh_rot_movie.mp4']);

end

