% A script for HH models
%
% This simulates the HH model using parameters embedded in pars
% a stimulus current, and a time range over which
% the simulation should run
%
% Copyright 2016
% Joshua Weitz - BIOL 8804 - F16

% Parameters, including on/off functions
pars.gKbar= 36; 	% mS/cm^2
pars.gNabar=120; 	% mS/cm^2
pars.gL=0.3;		% mS/cm^2
pars.EK=-12; 		% mV
pars.ENa=120; 		% mV
pars.EL= 10.6; 		% mV
pars.C=1;		% muF/cm^2

% Correction to interpolate the original alpha_n and alpha_m 
% forms to ensure a smooth and non-divergent function
V=-100:0.1:200;
pars.V=V;
pars.Vmin=-100;
pars.Vmax=200;
pars.dV=0.1;

% Define the original functions, with piecewise smooth functions
pars.alphan = 0.01*(10-V)./(exp(1-V/10)-1);
pars.betan = @(V) 0.125*exp(-V/80);
pars.alpham = 0.1*(25-V)./(exp(2.5-V/10)-1);
pars.betam = @(V) 4*exp(-V/18);
pars.alphah = @(V) 0.07*exp(-V/20);
pars.betah = @(V) (exp(3-V/10)+1).^-1;

% Assign the l'Hopital limit to those values where
% MATLAB thinks the function is 'Not a Number' (NAN)
tmpi=find(isnan(pars.alphan));
pars.alphan(tmpi)=0.1;
tmpi=find(isnan(pars.alpham));
pars.alpham(tmpi)=1;

% Initial conditions
pars.V0=0;
pars.n0=0;
pars.m0=0;
pars.h0=0;

% Run the model
y0 = [pars.V0 pars.n0 pars.m0 pars.h0];
[t,y]=ode15s(@model_alt_hh,[0:0.01:20],y0,[],pars);

% Store results
dyn.t=t;
dyn.V=y(:,1);
dyn.n=y(:,2);
dyn.m=y(:,3);
dyn.h=y(:,4);
dyn.gK=pars.gKbar*...
dyn.gNa=pars.gNabar*...
dyn.gL=pars.gL*...
dyn.IK=...
dyn.INa=...
dyn.IL=...
dyn.appliedI = impulse_t(dyn.t);

