function [t,y] = stochsim_SIR(trange,y0,pars)
% function [t,y] = stochsim_SIR(trange,y0,pars)
%
% Simulates an SIR model via the Gillespie algorithm % from t0 to tf in trange given initial
% conditions in y0 = [S0 I0 R0] and parameters
% in pars. Returns time and values

% Conditions
t0=trange(1);
tf=trange(2);
t(1)=t0;
y(1,:)=y0;
tcur=t0;
ycur=y0;
ind=1;

% Model
while (tcur<tf)
  % Check to see if there is an infection
  if (ycur(2)==0)
    ind=ind+1;
    t(ind)=tf;
    y(ind,:)=ycur;
    break;
  end

% Rates
infrate = (pars.beta*ycur(1)*ycur(2))/pars.N;
recrate = pars.gamma*ycur(2);
totrate = infrate + recrate;
dt = -1/totrate*log(rand); tcur=tcur+dt;
% Event type
if (rand<(infrate/totrate)) % infection
    ycur(2)=ycur(2)+1;
    ycur(1)=ycur(1)-1;
else % recovery
    ycur(3)=ycur(3)+1;
    ycur(2)=ycur(2)-1;
  end
  ind=ind+1;
  t(ind)=tcur;
  y(ind,:)=ycur;
end