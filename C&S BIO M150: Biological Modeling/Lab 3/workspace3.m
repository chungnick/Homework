[t,x] = ode45(@returnn,[t0 tf],x0,[],pars); % plot pertubation above equilibrium
plot(t,x(:,2),'b','LineWidth',3) 