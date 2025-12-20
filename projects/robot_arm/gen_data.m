% target parameters:
t = pi/2*[ 1 1 1 1 0 1 ]

x= (0:0.01:1.3)'./1.3;

% straight linear interpolation:
p = x * t;
save -ascii data/parameters-1.txt p;

% cosine modulated interpolation:
p = 0.5*(1-cos(pi*x)) * t;
save -ascii data/parameters-2.txt p;

% smooth start and end, linear in the middle:
y = 1.32*(x.^2)./(0.16+x); 
y(end:-1:(end/2+1)) = 1-y(1:end/2);
p = y * t;
save -ascii data/parameters-3.txt p;
