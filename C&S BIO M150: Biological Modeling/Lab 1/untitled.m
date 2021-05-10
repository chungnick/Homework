syms y(t)
eqn = diff(y,t) == y;
cond = y(0) == 1    %iniital condition y(0) = 1
ySol(t) = dsolve(eqn,cond)

t = 0:0.1:10; %0 to 10 with step size 0.1
figure
plot(t,ySol(t),'b') % blue plot
xlabel('t'), ylabel('y')