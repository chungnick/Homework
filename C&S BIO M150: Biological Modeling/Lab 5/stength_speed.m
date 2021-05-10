% Run the model over 10 days
[t,y]=ode45(@(t,y) sir_model(t,y,pars),[0:1:10],[pars.S0 pars.I0 0]/pars.N);

% Find the slope
[p,s]=polyfit(t,log(y(:,2)),1);

% Plot the data and overlay the best-fit exponential 
tmph=semilogy(t,y(:,2),'ko'); 
set(tmph,'linewidth',3);
hold on
tmph=semilogy(t,exp(p(1)*t+p(2)),'r-'); 
set(tmph,'linewidth',3);

% Use solid points for the future k
[t,y]=ode45(@(t,y) sir_model(t,y,pars),[0:1:30],[pars.S0 pars.I0 0]/pars.N); 
tmpi=find(t>10);
tmph=semilogy(t(tmpi),y(tmpi,2),'ko'); 
set(tmph,'linewidth',3,'markerfacecolor','k');