
%Read image
A = imread('1.png');
[m,n] = size(A);
imsize = m*n;

%Equalization 
h=zeros(1 , 256);
for i =1 : m
    for j = 1 : n
        h(A(i,j)+1) =  h(A(i,j)+1)+1;
    end
end    
%����
p = [];
for i = 1 : 256
    p(i) = double(h(i)/imsize);
end
%�ֲ�
F = zeros(1 ,256);
F(1) = p(1);
for i = 2 : 256
    F(i)  = F(i-1)+p(i);
end
%��Ӧ
s = [];
for i = 1 : 256
    s(i) = round(F(i)*255);
end   
%���⻯��Ӧ�任
for i =1 : m
    for j = 1 : n
         A(i ,j) = s(A(i , j)+1);
    end
end    
%�ٴ�ͳ��ֱ��ͼ
nh = zeros(1,256);
for i =1 : m
    for j = 1 : n
        nh(A(i,j)+1) =  nh(A(i,j)+1)+1;
    end
end  

%showImg
figure;
imshow(A);
imwrite(A,'2.jpg');

%{
%use Library function
B = histeq(A);
subplot(121);
imshow(B);
counts = imhist(B);
subplot(122);
bar(counts);
%}
