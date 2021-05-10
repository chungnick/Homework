function dydt = model_alt_hh(t,y,pars)
% function dydt = model_hh(t,y,pars)
% This simulates the HH model using parameters embedded in pars
% a stimulus current in pars.Idrive.
%
% Copyright 2018
% Joshua Weitz - BIOL 8814 - F18

% Pulse
% Units of muA/cm^2 
% Equivalent to mSmV/cm^2

% Variables
V=y(1);
n=y(2);
m=y(3);
h=y(4);

% Impulses
I=impulse_t(t); 	% Specified in a function

% Fixes the issue with the singularity in the alphan/alpham
% The intuition here is to find the right index for
% the current V value, and then interpolate to make it piecewise
% smooth.  This method also avoids using ``find'' and ``if'' commands 
% to ensure reasonable speed.
vmin_ind=1+(V-pars.Vmin)/pars.dV;
tmpi=floor(vmin_ind);
dev_ind=vmin_ind-tmpi;
alphan = pars.alphan(tmpi)+(pars.alphan(tmpi+1)-pars.alphan(tmpi))*dev_ind;
alpham = pars.alpham(tmpi)+(pars.alpham(tmpi+1)-pars.alpham(tmpi))*dev_ind;

% Dynamics
Vdot = (1/pars.C)*(I- ...); % Fill in
ndot = ...                  % Fill in
mdot = ...                  % Fill in
hdot = ...                  % Fill in

% Return the changes
dydt = [Vdot; ndot; mdot; hdot];
