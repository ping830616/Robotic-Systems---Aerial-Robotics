
%% test utility class for computing volume and CM of a tetrahedron

% check using the known formulae for a REGULAR tetrahedron: 
%  V = a^3 / (6*sqrt(2))
% REF:  https://en.wikipedia.org/wiki/Tetrahedron

% here are the co-ordinates of a tetrahedron with EDGE length a=2
v1 = [-1,  0, -1/sqrt(2) ];
v2 = [ 1,  0, -1/sqrt(2) ];
v3 = [ 0, -1,  1/sqrt(2) ];
v4 = [ 0,  1,  1/sqrt(2) ];

      
OBJ = tetra_irreg_CLS(v1, v2, v3, v4) 

cm = OBJ.get_cm()

vol = OBJ.get_volume()

% now compare with the known formulae
a         = 2;
check_vol = (a^3)/(6*sqrt(2))