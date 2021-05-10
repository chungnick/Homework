function dydt = sir_model(t,y,pars)
S = y(1);
I = y(2);
% The model
dSdt = -pars.beta*S*I;
dIdt = pars.beta*S*I-pars.gamma*I; 
dRdt = pars.gamma*I;

dydt = [dSdt; dIdt; dRdt];
end
