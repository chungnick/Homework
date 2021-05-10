function dNdt=logGrowth(r,K)
% function dNdt=logGrowth(t,N)
%
% logGrowth gives the growth rate of a population of size N at time t % Usage:dNdt=logGrowth(t,N)
t = 1:50;
N =1;
dNdt =r*N.*(1-N/K);
end