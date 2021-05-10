%(loads imag file)
im1 = imread('Tree2.jpg');
%(Look at image)
image(im1);
%(Only choose part of image with fractal structure you want to analyze) 
i = im1(20:160, 25:240, 3);
%(Sets full color scale for image)
imagesc(~im1);
%(Converts to gray scale)
colormap gray;
%(Look at data and see what scale it is on?)
im1
%(Set threshhold to only look at data above half the maximum value)
th = (i<125);
%(Look at final image)
imagesc(th)
[n,r] = boxcount(i);


h = figure('DefaultAxesFontSize',18);
plot(log(r),log(n),'bo-')
xlabel('log(r, boxsize)','FontSize',18)
ylabel('log(n, number of boxes)','FontSize',18)
title('2D box-count','FontSize',18)

pf = polyfit(log(r'),log(n'),1)

boxcount(i, 'slope')

plot(log(n),log(r),'bo-',log((r/r(end)).^(-1.7)),log(r),'r--',...
    log((r/r(end)).^(-1.59)),log(r),'g--')
xlabel('log(r, box size)')
ylabel('log(n, number of boxes)')
legend('Empirical measure of log(n) versus log(r)',...
    'Estimation by local slope','Estimation by polyfit')