function dydt = si_model(t,y,pars)
% function dydt = si_model(t,y,pars) % SI Model
S=y(1);
I=y(2);
% The model
dSdt = -pars.beta*S*I+pars.gamma*I; 
dIdt = pars.beta*S*I-pars.gamma*I;
dydt = [dSdt; dIdt];
end
