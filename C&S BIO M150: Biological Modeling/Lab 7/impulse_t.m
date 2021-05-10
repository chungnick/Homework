function I = impulse_t(t)
% function I = impulse_t(t)
%
% specifies the applied time-varying current
% works if t is a single value or many values
for i=1:length(t),
    if (t(i)>2 & t(i)<2.5)
        I(i,1)= 13;
    elseif (t(i)>15 & t(i)<15.5)
        I(i,1)= 0;
    else
        I(i,1)= 0;
    end
end