clear;

%参数   H          S       V   Threshold
p=[0.56 0.71 0.4 1 0.3 1 3];

%to HSV
ImgPath = 'D:\数字图像作业\dataset\iPhone 5s\';
testImg = dir([ImgPath ,'*.jpg']);
test_size = length(testImg);

for k = 1 :test_size
Image= imread([ImgPath testImg(k).name]);
Image=im2double(Image);
s=size(Image,2);
I=rgb2hsv(Image);
[y,x,z]=size(I);

cy = zeros(y, 1);
bw = boolean(zeros(y,x));
for i = 1 : y
    for j = 1 : x
        curh = I(i, j, 1);
        curs = I(i, j, 2);
        curv = I(i, j, 3);
        if (curh>=p(1) && curh<=p(2)) && ( curs >=p(3) &&  curs<=p(4))&& (curv>=p(5) && curv<=p(6))
            bw(i,j)=1;
        end
    end
end
%imshow(bw);
bw = bwareaopen(bw ,1000);

%统计
for i = 1 : y
    for j = 1 : x
        if bw(i,j)==1
            cy(i) = cy(i)+1;
        end
    end
end    

[~, MaxY] = max(cy);
Th = p(7);

PY1 = MaxY;
while ((cy(PY1,1)>Th) && (PY1>2))
    PY1 = PY1 - 1;
end

PY2 = MaxY;
while ((cy(PY2,1)>Th) && (PY2<y-2))
    PY2 = PY2 + 1;
end
PY1 = PY1 - 2;
PY2 = PY2 + 2;

%修正
if PY1 < 1
    PY1 = 1;
end

if PY2 > y
    PY2 = y;
end

bwY = bw(PY1:PY2, :, :);
%imshow(bwY);
%imwrite(bwY , 'n2.jpg'); 
[y1,x1]=size(bwY);
cx=zeros(1,x1);
for j = 1 : x1
    for i = 1 : y1
            if bwY(i , j)==1
            cx(j) = cx(j) + 1; 
           end
    end
end
 
[~, MaxX] = max(cx);
Th = p(7);
PX1 = MaxX;
 
while ((cx(1,PX1)>Th) && (PX1>2))
    PX1 = PX1 - 1;
end
PX2 = MaxX;
while ((cx(1,PX2)>Th) && (PX2<x1-2))
    PX2 = PX2 + 1;

end
bwXY=bw(PY1:PY2,PX1:PX2);
%imwrite(bwXY , 'n3.jpg');
plate=Image(PY1:PY2,PX1:PX2,:);
imwrite(plate , [ImgPath num2str(k) '.jpg']);
end