function dydt = model_hh(t,y,pars)
% Joshua Weitz - BIOL 8814 - Neuron excitation - Fall 2018
%
% function dydt = model_hh(t,y,pars)
% This simulates the HH model using parameters embedded in pars
% and requires a separate function termed impluse_t which
% has information on the time-dependent applied current
% Variables
V=y(1);
n=y(2);
m=y(3);
h=y(4);
% Impulses
I=impulse_t(t); % Specified in a function
% Dynamics
Vdot = (1/pars.C)*(I-pars.gKbar*(n^4)*(V-pars.EK)-pars.gNabar*(m^3)*h*(V-pars.ENa)-pars.gL*(V-pars.EL));
ndot = pars.alphan(V)*(1-n)-pars.betan(V)*n;
mdot = pars.alpham(V)*(1-m)-pars.betam(V)*m;
hdot = pars.alphah(V)*(1-h)-pars.betah(V)*h;

% Return the changes
dydt = [Vdot; ndot; mdot; hdot];

