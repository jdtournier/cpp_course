% inspired by shotgun sequencing
% https://en.wikipedia.org/wiki/Shotgun_sequencing

% main parameters:

N = 20000;

split_size_min = 50;
split_size_max = 1000;

nsplit = 5;

destination_file = 'fragments.txt';
actual_file = 'solution.txt';

produce_plot = 0;



% start of data generation:

N = round (N + 200*randn(1));
G = randi(4,1,N);
split = {};
map = zeros (nsplit, N);
pos=[];

if produce_plot == 0
  % convert to char array:
  G(G==1) = 'A';
  G(G==2) = 'C';
  G(G==3) = 'G';
  G(G==4) = 'T';
  G = char(G);
end


for n = 1:nsplit
  first = 1;
  k = 1;
  last = split_size_min + randi(split_size_max-split_size_min);
  while first < numel(G)
    k=1-k;
    split{end+1} = G(first:last);
    pos(end+1) = first;
    first = last+1;
    last = first + split_size_min + randi(split_size_max-split_size_min);
    if last > numel(G), last = numel(G); end
    if last-first < split_size_min, break; end
  end

end


% flip sequences at random:
flip=zeros(numel(split),1);
%for n = 1:numel(split)
%  if randi(2,1,1) == 1
%    split{n} = fliplr (split{n});
%    flip(n) = 1;
%  end
%end

k = randperm(numel(split));

if produce_plot == 0
  % write out data:

  f = fopen (destination_file, 'w');
  for n = 1:numel(split)
    fwrite (f, split{k(n)});
    fwrite (f, 10);
  end
  fclose (f);

  f = fopen (actual_file, 'w');
  fwrite (f, G);
  fwrite (f, 10);
  fclose (f);
else

  cmap=[1 0 0; 0 1 0; 0 0 1; 1 1 0];
  figure (1)
  clf
  axis off tight
  hold on
  image(repmat(G,2,1), 'XData', [0 numel(G)], 'YData', [0 0.7]-2, 'CDataMapping', 'scaled'); 
  rectangle ('Position', [-0.5 -2.35 numel(G)+1 1.4],  'LineWidth', 3);
  for n = 1:numel(split)
    p=k(n);
    g = split{p};
    if flip(p), g=fliplr(g); end
    image(repmat(g,2,1), 'XData', pos(p)+[0 numel(g)], 'YData', 2*n+[0 0.7], 'CDataMapping', 'scaled'); 
    colormap (cmap);
    rectangle ('Position', [pos(p)-0.5 2*n-0.35 numel(g)+1 1.4]);
  end

  set(gca,'Position',[0 0 1 1])
end

