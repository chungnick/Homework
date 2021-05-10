
pars.a = 10; % nM/hr
pars.b = 1; % /hr
pars.r = 30; % proteins/(mRNA*hr)
x0 = [0 0]; % Initial values (m,p)
t0 = 0; % Initial time of 0 hours
tf = 24; % Final time of 24 hours
[t,x] = ode45(@(t,x) proteinproduction(t,x,pars),[t0 tf],x0); 

% plotting code
plot(t,x,'LineWidth',3)
xlabel('time (hr)','FontSize',20) 
ylabel('nMol','FontSize',20)
legend('mRNA','Protein')
set(gca,'FontSize',20)

% simulate for (m,p) initial conditions: (0,0), (7,25), (1,150)