/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
//2018/11/14 更新
//2019/3/7 完成
#include<stdio.h>
#include<math.h>

int sum_bit(int num) {
  int ans=0;
  while(num > 0){
	ans += (num%10);
    num /=10;
  }
  return ans;
}

int multi_bit(int num) {
   int ans=1;
   while(num > 0){
	ans *= (num%10);
    num /=10;
   }
  return ans;
}

int square_sum_bit(int num) {
   int ans = 0;
   while(num > 0){
	int cbit = num%10;
	ans += (cbit*cbit);
    num /=10;
   }
  return ans;
}

int isprime(int num) {
   int i;
   if(num<2)return 0;
   for(i=2 ;i<=sqrt(num) ;i++){
	   if(num%i==0)return 0;
   }
   return 1;
}

int main() {
   //if(isprime(113)&&isprime(sum_bit(113))&&isprime(multi_bit(113))&&isprime(square_sum_bit(113)))
    //to do sth
   int i;
   int a[100] , cnt=0;
   int sum = 0;
   for(i=100 ;i<=9999 ;i++){
	   if(isprime(i) && isprime(sum_bit(i)) && isprime(multi_bit(i)) && isprime(square_sum_bit(i)))
	    {
	      a[++cnt] = i;
		  sum += i;	
		}
	}
   printf("The number of SPs is %d\n" , cnt);
   printf("The sum of SPs is %d\n" , sum);
   printf("The biggest SPs is %d\n" , a[cnt]);
   
   return 0;
}
