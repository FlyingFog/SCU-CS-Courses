%Image Haze Removal Using retinex

%read Img
I = imread('test8.jpg');
%img=imresize(img,0.5,'nearest');
R = I(:, :, 1);
[n, m] = size(R);

%gaussian
sigma = 250;
F = fspecial('gaussian', [n,m], sigma);
Efft = fft2(double(F));

%R
R0 = double(R);
Rlog = log(R0+1);
Rfft2 = fft2(R0);

DR0 = Rfft2.* Efft;
DR = ifft2(DR0);

DRlog = log(DR +1);
Rr = Rlog - DRlog;
ExpR = exp(Rr);
MIN = min(min(ExpR));
MAX = max(max(ExpR));
ExpR = (ExpR - MIN)/(MAX - MIN);
%增加自适应直方图均衡
ExpR = adapthisteq(ExpR);

%G
G = I(:, :, 2);
G0 = double(G);
Glog = log(G0+1);
Gfft2 = fft2(G0);

DG0 = Gfft2.* Efft;
DG = ifft2(DG0);

DGlog = log(DG +1);
Gg = Glog - DGlog;
ExpG = exp(Gg);
MIN = min(min(ExpG));
MAX = max(max(ExpG));
ExpG = (ExpG - MIN)/(MAX - MIN);

ExpG = adapthisteq(ExpG);

%B
B = I(:, :, 3);
B0 = double(B);
Blog = log(B0+1);
Bfft2 = fft2(B0);

DB0 = Bfft2.* Efft;
DB = ifft2(DB0);

DBlog = log(DB+1);
Bb = Blog - DBlog;
ExpB = exp(Bb);
MIN = min(min(ExpB));
MAX = max(max(ExpB));
ExpB = (ExpB - MIN)/(MAX - MIN);
ExpB = adapthisteq(ExpB);

%show
result = cat(3, ExpR, ExpG, ExpB);
imwrite(result , 'testdehaze1.jpg');
subplot(121), imshow(I);title("a");
subplot(122), imshow(result);title("b");