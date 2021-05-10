function ploth = plot_hh(dyn,pars)
% function ploth = plot_hh(dyn,pars)
%
% Takes a HH output structure in dyn and plots
% dynamics of Voltage, gating variables, conductance
% currents and applied current
% Defaults
clf;
set(gcf,'DefaultLineMarkerSize',10);
set(gcf,'DefaultAxesLineWidth',2);
set(gcf,'PaperPositionMode','auto');
set(gcf,'Position',[300 40 600 750]);
% main data goes here
% Applied current on bottomA
tmppos= [0.1 0.1 0.8 0.1];
tmpa1 = axes('position',tmppos);
tmph=plot(dyn.t,dyn.appliedI,'k-');
set(tmph,'linewidth',2);
xlabel('Time, ms','fontsize',12,'verticalalignment','top','interpreter','latex');
text(1,25,'Applied current');
ylim([0 30]);
% Currents next
tmppos= [0.1 0.225 0.8 0.1];
tmpa2 = axes('position',tmppos);
tmph=plot(dyn.t,dyn.IK,'k-',dyn.t,dyn.INa,'r-',dyn.t,dyn.IL,'b-');
text(1,400,'Currents');
set(gca,'xticklabel',[]);
ylim([-500 500]);
% Conductances next
tmppos= [0.1 0.35 0.8 0.1];
tmpa3 = axes('position',tmppos);
tmph=plot(dyn.t,dyn.gK,'k-',dyn.t,dyn.gNa,'r-',dyn.t,dyn.gL,'b-');
text(1,25,'Conductances');
set(gca,'xticklabel',[]);
ylim([0 30]);
% Gating
tmppos= [0.1 0.475 0.8 0.1];
tmpa3 = axes('position',tmppos);
tmph=plot(dyn.t,dyn.n,'k-',dyn.t,dyn.m,'r-',dyn.t,dyn.h,'b-');
text(1,0.8,'Gating');
set(gca,'xticklabel',[]);
ylim([0 1]);
% Voltage
tmppos= [0.1 0.6 0.8 0.35];
tmpa3 = axes('position',tmppos);
tmph=plot(dyn.t,dyn.V,'k-');
set(tmph,'linewidth',2);
text(1,130,'Membrane voltage (mV)');
set(gca,'xticklabel',[]);
ylim([-20 150]);
text(-1,pars.EK,'E_K');
text(-1,pars.ENa,'E_{Na}');
text(-1,pars.EL,'E_L');
% Return the plot handle
ploth=gcf;