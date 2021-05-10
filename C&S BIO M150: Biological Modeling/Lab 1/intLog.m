% Numerical solution of the logistic equation
t0 =0; % Initial time
tf =50; %Final time
N0 =1; %Initial population size
[T, vNint] = ode45(@logGrowth, [t0 tf], N0); %Numerically integrate
% Actual solution
r = 0.5
K =1000;
vNact =(N0*exp(r*T))./(1+N0*(exp(r*T)-1)/K); %Actual solution
% Plot results
figure;
hold on
plot(T,vNint) % Plot numerically intregrated solution plot(T,vNact,’ro’) %Plot actual solution
xlabel('Time'), ylabel('Population size'),title('Logistic model') 
print -dpdf logPlot.pdf