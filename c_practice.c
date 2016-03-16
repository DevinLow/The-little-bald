#include <stdio.h>
#include <math.h>
#include "c_practice.h"
/*
题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？

程序分析：可填在百位、十位、个位的数字都是1、2、3、4。组成所有的排列后再去 掉不满足条件的排列。
*/

void practice_1(void)
{
	int i,j,k;
	for(i=1;i<5;i++) { // 以下为三重循环
		for(j=1;j<5;j++) {
			for (k=1;k<5;k++) { // 确保i、j、k三位互不相同
				if (i!=k&&i!=j&&j!=k) { 
					printf("%d,%d,%d\n",i,j,k);
				}
			}
		}
	}
}
/*
题目：企业发放的奖金根据利润提成。利润(I)低于或等于10万元时，奖金可提10%；利润高于10万元，低于20万元时，
低于10万元的部分按10%提成，高于10万元的部分，可可提成7.5%；20万到40万之间时，高于20万元的部分，可提成5%；
40万到60万之间时高于40万元的部分，可提成3%；60万到100万之间时，高于60万元的部分，可提成1.5%，高于100万元时，
超过100万元的部分按1%提成，从键盘输入当月利润I，求应发放奖金总数？

程序分析：请利用数轴来分界，定位。注意定义时需把奖金定义成长整型。

*/
void practice_2(void)
{
	double i;
	double bonus1,bonus2,bonus4,bonus6,bonus10,bonus;
	printf("Net income:");
	scanf("%lf",&i);
	bonus1=100000*0.1;
	bonus2=bonus1+100000*0.075;
	bonus4=bonus2+200000*0.05;
	bonus6=bonus4+200000*0.03;
	bonus10=bonus6+400000*0.015;
	if(i<=100000) {
		bonus=i*0.1;
	} else if(i<=200000) {
		bonus=bonus1+(i-100000)*0.075;
	} else if(i<=400000) {
		bonus=bonus2+(i-200000)*0.05;
	} else if(i<=600000) {
		bonus=bonus4+(i-400000)*0.03;
	} else if(i<=1000000) {
		bonus=bonus6+(i-600000)*0.015;
	} else if(i>1000000) {
		bonus=bonus10+(i-1000000)*0.01;
	}
	printf("royalties: bonus=%lf",bonus);

	printf("\n");
}
/*
题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？

程序分析：在10万以内判断，先将该数加上100后再开方，再将该数加上268后再开方，如果开方后的结果满足如下条件，即是结果。
*/
void practice_3(void)
{
	  long int i,x,y;
    for (i=1;i<100000;i++) {
        x=sqrt(i+100); // x为加上100后开方后的结果
        y=sqrt(i+268); // y为再加上168后开方后的结果
        if(x*x==i+100 && y*y==i+268){ //如果一个数的平方根的平方等于该数，这说明此数是完全平方数
            printf("\n%ld\n",i);
        }
    }	
}