% main data goes here
pars.c = 15; % Contacts per unit time (e.g., days) 
pars.p = 0.3; % Probability of infectious contact 
pars.beta = pars.c*pars.p; % Transmission rate
pars.gamma = 0.8; % Recovery rate (days^-1)
pars.R0 = pars.beta/pars.gamma;
pars.N = 100000000;
pars.I0 = 3;
pars.S0 = pars.N-pars.I0;

% Run the model
[t,y]=ode45(@(t,y) sir_model(t,y,pars),[0 100],[pars.S0 pars.I0 0]/pars.N);

% Plot the results
tmph = plot(t,y);
set(tmph,'linewidth',3);
xlabel('Time (days)');
ylabel('Population fraction');
tmplh = legend('Susceptible','Infectious','Recovered');
legend('boxoff');

pars.R0