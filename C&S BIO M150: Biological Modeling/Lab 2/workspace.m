% Exercise 2.1

syms ll;

af=[-1, -0.5, -0.5, -0.5, -0.5; 
    -0.5, -1, -0.5, -0.5, -0.5; 
    -0.5, -0.5, -1, -0.5, -0.5; 
    -0.5, -0.5, -0.5, -1, -0.5; 
    -0.5, -0.5, -0.5, -0.5, -1];

v=[1;2;0;3;1];
u1=af*v/norm(af*v);
ll(1)=double(u1'*af*u1)
u2=af*u1/norm(af*u1);
ll(2)=double(u2'*af*u2)
u3=af*u2/norm(af*u2);
ll(3)=double(u3'*af*u3)
u4=af*u3/norm(af*u3);
ll(4)=double(u4'*af*u4)
u5=af*u4/norm(af*u4);
ll(5)=double(u5'*af*u5)
u6=af*u5/norm(af*u5);
ll(6)=double(u6'*af*u6)

u6'*af*u6
% Question 1.a: 
% = -3.0000

eig(af)

% Question 1.b: 
% answer is exactly equal to the largest eigenvalue printed by eig(af)






