% Single Image Haze Removal Using Dark Channel Prior
clear;
close all;
clc;

img = imread('haze1.jpg');
%img=imresize(img,0.5,'nearest');
img = double(img) / 255;
[m, n, k] = size(img);

%parameter
radius = 6; % window radius
w = 0.95; % dehaze weight omiga
   
% calculate light
if k == 3 
        RGBMin = min(img, [], 3);
        light = mean(img, 3);
else 
        RGBMin = img(:, :, 1);
        light = img(:, :, 1);
end
    
% calculate dark channel
darkChannel = zeros(m, n);
for i = 1 : m
        for j = 1 : n
            pitch = RGBMin(max(1, i-radius) : min(m, i+radius), max(1, j-radius) : min(n, j+radius));
            darkChannel(i, j) = min(pitch(:));
        end
end

% choose pixels with 0.1% highest value of dark channel
sortedDChannel = sort(darkChannel(:), 'descend');
threshold = sortedDChannel(round(0.001*m*n));
brightestPixels = light;
brightestPixels(darkChannel < threshold) = 0;
    
% choose the largest light
[row, col] = find(brightestPixels==max(brightestPixels(:)), 1);
atmosphericLight = img(row, col, :);

 % calculate the transmission map
 transmission = 1 - w*min(darkChannel./atmosphericLight, [], 3);

% perform guided filter on the transmission
r = 80;
regularization = 0.01;   
transmission_filter = imguidedfilter(transmission, img, 'NeighborhoodSize',[r r], 'DegreeOfSmoothing', regularization*diff(getrangefromclass(img)).^2);
transmission = max(0.1, transmission_filter);
    
% J = (I-A)/t+A
dehazedImg= (img - atmosphericLight) ./ transmission + atmosphericLight;  


figure;
imshow(darkChannel);
title('Dark Channel');
%imwrite(darkChannel , 'dc.jpg');

figure;
imshow(transmission);
title('Transmission Map');
%imwrite(transmission , 'tm.jpg');

figure;
imshow(dehazedImg);
title('Dehazed Image');
imwrite(dehazedImg , 'dh.jpg');
