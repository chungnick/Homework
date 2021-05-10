pars.c = 20; % Contacts per unit time (e.g., days) 
pars.p = 0.025; % Probability of infectious contact 
pars.beta = pars.c*pars.p; % Transmission rate
pars.gamma = 1/4; %
pars.tf = 60;
pars.R0 = pars.beta/pars.gamma;
pars.N = 1000;
pars.I0 = 10;
pars.S0 = pars.N-pars.I0;

% Run the ODE model
[t,y]=ode45(@(t,y) sir_model(t,y,pars),[0 pars.tf],[pars.S0 pars.I0 0]/pars.N); 
tmph=plot(t,pars.N*y);
set(tmph,'linewidth',3);
hold on

% Run the stochastic model
[tsim,ysim]=stochsim_SIR([0 pars.tf],[pars.S0 pars.I0 0],pars); 
tmphsim=plot(tsim,ysim,'--');
set(tmphsim,'linewidth',3);

% Color the lines the same way (where dashes are for stochastic)
for i=1:3,
  set(tmphsim(i),'color',get(tmph(i),'color'));
end