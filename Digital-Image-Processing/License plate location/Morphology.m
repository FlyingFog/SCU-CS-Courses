
clear;
ImgPath = 'D:\数字图像作业\dataset\iPhone 5s\';
testImg = dir([ImgPath ,'*.jpg']);
test_size = length(testImg);

for k = 1 : test_size

%read
Img = imread([ImgPath testImg(k).name]);

%to-gray
grayImg = rgb2gray(Img);

%edge
edgeImg = edge(grayImg, 'roberts',0.06,'vertical');
%imwrite(edgeImg , '2.jpg');

%erode
sElem = [1; 1;1 ;1];
              
erodeImg = imerode(edgeImg , sElem);
%imwrite(erodeImg , '3.jpg');

%close
erodeImg= bwareaopen(erodeImg,4);
se1=strel('rectangle',[55,55]); 
Img1 = imclose(erodeImg , se1);
%imwrite(Img1 , '4.jpg');

%
bwImg = bwareaopen(Img1,2000);
%imwrite(bwImg , '5.jpg');

[y , x] = size(bwImg);
cy = zeros(y ,1); 
cx = zeros(x ,1);

for i=6 : y-6
    for j=1 : x
        if(bwImg(i,j)==1)
            cy(i)=cy(i)+1;
        end
    end
end

[~, MaxY]=max(cy);

if MaxY == 1
     MaxY = y/2;
end     

PY1=MaxY;
while((cy(PY1)>=5)  &&  (PY1>7))
    PY1=PY1-1;
end

PY2=MaxY;
while((cy(PY2)>=5 ) &&  (PY2<y-7))
    PY2=PY2+1;
end
PY1 = PY1 - 6;
PY2 = PY2 +6;
for j=1 : x
    for i =PY1 : PY2
        if(bwImg(i,j)==1)
            cx(j)=cx(j)+1;
        end
    end
end

PX1=10;
while((cx(PX1)<5) && (PX1<x))
    PX1=PX1+1;
end
PX2=x-10;
while((cx(PX2)<5) && (PX2>PX1))
    PX2=PX2-1;
end
%对车牌区域的矫正
PX1=PX1-5;
PX2=PX2+5;
plate=Img(PY1:PY2,PX1:PX2,:);
%imshow(plate);
imwrite(plate , [ImgPath num2str(k) '.jpg']);
end    





