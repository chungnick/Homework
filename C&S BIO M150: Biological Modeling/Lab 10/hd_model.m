function dxdt = hd_model(t,x,pars)
% function dxdt = hd_model(t,x,pars)
%
% Hawk-Dove Replicator Dynamics Model
% Returns dxdt for a 1D replicator model with hawk-dove parameters, 
% pars.G and pars.C denoting gain and cost, in the matrix pars.A.

r1=x*pars.A(1,1)+(1-x)*pars.A(1,2); 
r2=x*pars.A(2,1)+(1-x)*pars.A(2,2); 
r_avg = r1*x+r2*(1-x);

dxdt = r1*x-r_avg*x;