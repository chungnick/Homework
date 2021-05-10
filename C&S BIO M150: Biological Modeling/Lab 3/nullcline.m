
% Define the nullclines
mnullcline = pars.a/pars.b; % A fixed value
pnullcline = @(p) pars.b.*p./pars.r; % An ‘anonymous’ function % Define a vector of protein and mRNA values
pvec = 0:20:200;
mvec = 0:1:8;
% Plot the mRNA nullcline 
plot(mnullcline*ones(size(pvec)),pvec,'LineWidth',3)
hold on
% Overlay the protein nullclinej 
plot(pnullcline(pvec),pvec,'LineWidth',3)
hold off
% Add some plotting notes and modify the axes
legend('dmdt = 0', 'dpdt = 0')
xlim([min(mvec) max(mvec)])
ylim([min(pvec) max(pvec)])
xlabel('mRNA concentration (nMol)','FontSize',20) 
ylabel('Protein concentration (nMol)','FontSize',20) 
set(gca,'FontSize',20)

% plot direction field
dmdt = @(m) pars.a - pars.b.*m;
dpdt = @(m,p) pars.r.*m-pars.b.*p;
[MM,PP] = meshgrid(mvec,pvec);
hold on 
quiver(MM,PP,dmdt(MM),dpdt(MM,PP),'k','MaxHeadSize',.015,'LineWidth',2); 
hold off