% THIS SCRIPT SIMULATES MICHAELIS-MENTEN ENZYME DYNAMICS 
% Standard Quasi Steady State Approximation sQSSA
% Calls QSSA_func.m which implements the differential eqns
% Reactions
%     R1: S + E -- k1 --> ES
%     R2: ES    -- kminus1 --> E + S 
%     R3: ES    -- k2 --> E + P 
%
% Also, solves for set of equations with sQSSA applied.
% Constraints
%     e(t) + c(t) = e0
% Assumption
%     dcdt ~ 0

% Converted to minutes
K1      = 600;  
K1MINUS = 120;  
K2      = 1.2;  

% Initial conditions x0.
s0   = 1; 
e0   = 1; 
c0   = 0;
p0   = 0;

% First 4 elements are for the original set of equations
% Last 2 elements are for sQSSA. 
% [s_ori e_ori c_ori p_ori s_qssa p_qssa]
x0 = [s0; e0; c0; p0];  % ICs 

% Calculate QSSA metrics
Km = (K1MINUS+K2)./K1;
tc = 1./(K1*(s0+Km));
ts = (s0+Km)./(e0*K2);
epsilon = e0/(Km+s0);

disp(sprintf('\n----------Running MM Script-----------\n'));
disp(sprintf('Intial substrate: %f\nInitial Enzyme: %f\n',s0,e0));
disp(sprintf('KM: %f\nFast time tc: %f\nSlow time ts: %f\n',Km,tc,ts));
disp(sprintf('tc/ts= %f\n',tc/ts));
disp(sprintf('epsilon=e0/(KM+s0): %f\n',epsilon));

% Call Matlab Numerical Solver on our function f(t,x)
tspan = [0 floor(10*ts)]; %scale simulation time to slow time
[t,x]=ode15s(@(t,x) QSSA_func2(t,x,K1,K1MINUS,K2,e0), tspan, x0);

% Post Process
h = plot(t,x);

set(h,{'LineWidth'},{2;2;2;2;},{'LineStyle'},...
    {'-';'--';'-';':'},{'Color'},{'c';'k';'r';'m'});
title(sprintf('ENZYME-SUBSTRATE DYNAMICS'));
xlabel('MINUTES');
ylabel('Concentration (nM)');
legend({'S','E','ES','P'},'FontName','Times','FontSize',12);
legend('boxoff')

Km