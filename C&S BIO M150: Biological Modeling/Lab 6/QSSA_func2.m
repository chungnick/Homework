function [dxdt] = QSSA_func(t,x,K1,K1MINUS,K2,e0)
% Single Substrate-Enzyme Reaction
% R1: S + E -- k1 --> ES
% R2: ES    -- k1minus --> E + S 
% R3: ES    -- k2 --> E + P 

% ----Original----
s=x(1); e=x(2); c=x(3); p=x(4);
dsdt  = -K1 * e * s + K1MINUS * c;      
dedt  = -K1 * e * s + (K1MINUS + K2) * c;  
dcdt  = K1 * e * s - (K1MINUS + K2) * c;   
dpdt  = K2 * c;     

% ----sQSSA----
% Constraints
%     e(t) + c(t) = e0
% Assumption
%     dcdt ~ 0

%s_qssa = x(5); p_qssa = x(6);

% Pack output
dxdt=[dsdt; dedt; dcdt; dpdt;];
return

