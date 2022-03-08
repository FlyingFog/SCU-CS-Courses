
clear ; 
%��С
n=3;
%����ģ��
H{1} = [0 -1 0;
           -1  4 -1;
            0 -1 0];
       
H{2} = [-1 -1 -1;
           -1  8  -1;
           -1 -1 -1];

H{3} = [1 -2 1;
           -2 4 -2;
           1 -2 1];
      
H{4}= [0 -1 0;
          -1 5 -1;
           0 -1 0];
 
I = imread('cup.jpg');      
[r , c] = size(I);
for m=1 : 4 
img = I;
Idouble = double(I);
for i=1 : r - 2
     for j=1 : c -2
        area = Idouble(i:i+n-1 , j:j+n-1);  
        %���
        x = area.*( H{m} );       
        grad = sum(x(:));   
        %����255��Ϊ255 ����0��Ϊ0
        img(i+1 , j+1) = grad;
     end
end
imwrite(img , [num2str(m) '.jpg']);
end