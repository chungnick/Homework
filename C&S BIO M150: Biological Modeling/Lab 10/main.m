% Main simulation code
pars.G = 10;
pars.C = 16;
pars.A=[(pars.G - pars.C)/2, pars.G; 0, pars.G/2]; % Fill in here 
pars.x0 = 0.1; % Initial fraction of hawks 
pars.tmax = 4;
[t,x]=ode45(@hd_model,[0 pars.tmax],pars.x0,[],pars); 

% Plot the results
tmph=plot(t,x,'k-');
set(tmph,'linewidth',3);
xlabel('Time, t');
ylabel('Hawk fraction, x');


hold on
pars.G = 10;
pars.C = 16;
pars.A=[(pars.G - pars.C)/2, pars.G; 0, pars.G/2]; % Fill in here 
pars.x0 = 0.4; % Initial fraction of hawks 
pars.tmax = 4;
[t,x]=ode45(@hd_model,[0 pars.tmax],pars.x0,[],pars); 
tmph=plot(t,x,'g-');
set(tmph,'linewidth',3);
hold off

hold on 
pars.G = 10;
pars.C = 16;
pars.A=[(pars.G - pars.C)/2, pars.G; 0, pars.G/2]; % Fill in here 
pars.x0 = 0.8; % Initial fraction of hawks 
pars.tmax = 4;
[t,x]=ode45(@hd_model,[0 pars.tmax],pars.x0,[],pars); 
tmph=plot(t,x,'b-');
set(tmph,'linewidth',3);
legend({'x0 = 0.1','x0 = 0.4','x0 = 0.8'},'FontName','Times','FontSize',12);

hold off

10/16
