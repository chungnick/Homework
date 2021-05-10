pstar = pars.r*pars.a/pars.b^2; 
mstar = pars.a/pars.b;
pperturb = pstar.*.01; 
mperturb = mstar.*.01;

x0 = [mstar+mperturb pstar+pperturb]; % pertubation above equilibrium
y0 = [mstar-mperturb pstar-pperturb]; % pertrubation under equilibrium
t0 = 0; % initial time 0 hours
tf = 10; % final time 10 hours

[t,x] = ode45(@proteinproduction,[t0 tf],x0,[],pars); % plot pertubation above equilibrium
plot(t,x(:,2),'b','LineWidth',3) 
hold on
[t,x] = ode45(@proteinproduction,[t0 tf],y0,[],pars); % plot pertubation under equilibrium
plot(t,x(:,2),'b','LineWidth',3)
hold off

xlabel('time (hr)','FontSize',20)
ylabel('Concentration (nMol)','FontSize',20)
legend('Protein')
set(gca,'FontSize',20)

% the shape of the return of the concentration of proteins to equilibrium
% follows a sigmoidal curve. As section 3.1 states, the solutions are
% expected to be exponential even though the dynamical system is linear

% quantitatively, both eigenvalues for the resulting Jacobian matrix of
% this dynamical system = -b, therefore quantitatively describing tje
% equiplibrium point as a stable equilibrium point.