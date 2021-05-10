% Joshua Weitz - BIOL 8814 - Neuron excitation - Fall 2018
%
% This simulates the HH model using parameters embedded in pars
% a stimulus current, and a time range over which
% the simulation should run
% Parameters, including on/off functions
pars.gKbar= 36; % mS/cm^2
pars.gNabar=120; % mS/cm^2
pars.gL=0.3; % mS/cm^2
pars.EK=-12; % mV
pars.ENa=120; % mV
pars.EL= 10.6; % mV
pars.C=1; % muF/cm^2
pars.alphan = @(V) 0.01*(10-V)./(exp(1-V/10)-1);
pars.betan = @(V) 0.125*exp(-V/80);
pars.alpham = @(V) 0.1*(25-V)./(exp(2.5-V/10)-1);
pars.betam = @(V) 4*exp(-V/18);
pars.alphah = @(V) 0.07*exp(-V/20);
pars.betah = @(V) (exp(3-V/10)+1).^-1;
% Initial conditions

%pars.V0=0;
%pars.n0=0;
%pars.m0=0;
%pars.h0=0;

pars.V0=0;
pars.n0= pars.alphan(pars.V0)/(pars.alphan(pars.V0)+pars.betan(pars.V0));
pars.m0= pars.alpham(pars.V0)/(pars.alpham(pars.V0)+pars.betam(pars.V0));
pars.h0= pars.alphah(pars.V0)/(pars.alphah(pars.V0)+pars.betah(pars.V0));

% Run the model
y0 = [pars.V0 pars.n0 pars.m0 pars.h0];
[t,y]=ode45(@model_hh,[0:0.02:20],y0,[],pars);

% y0 = [y(end,1),y(end,2),y(end,3),y(end,4)];
% [t,y]=ode45(@model_hh,[0:0.02:20],y0,[],pars);
% Store results
% FILL IN WHEREVER YOU SEE ...
dyn.t=t;
dyn.V=y(:,1);
dyn.n=y(:,2);
dyn.m=y(:,3);
dyn.h=y(:,4);
dyn.gK=pars.gKbar.*((dyn.n).^4);
dyn.gNa=pars.gNabar.*((dyn.m).^3).*dyn.h;
dyn.gL=pars.gL;
dyn.IK=dyn.gK.*(dyn.V-pars.EK);
dyn.INa=dyn.gNa.*(dyn.V-pars.ENa);
dyn.IL=dyn.gL.*(dyn.V-pars.EL);
dyn.appliedI = impulse_t(dyn.t);

plot_hh(dyn,pars);
