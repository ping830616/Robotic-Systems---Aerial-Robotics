function bRg = bh_autogen_bRg(phi,theta,psi)
%BH_AUTOGEN_BRG
%    BRG = BH_AUTOGEN_BRG(PHI,THETA,PSI)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    06-Jun-2016 11:26:45

bRg = reshape([cos(phi).*cos(theta),-cos(psi).*sin(phi)+cos(phi).*sin(psi).*sin(theta),sin(phi).*sin(psi)+cos(phi).*cos(psi).*sin(theta),cos(theta).*sin(phi),cos(phi).*cos(psi)+sin(phi).*sin(psi).*sin(theta),-cos(phi).*sin(psi)+cos(psi).*sin(phi).*sin(theta),-sin(theta),cos(theta).*sin(psi),cos(psi).*cos(theta)],[3,3]);
