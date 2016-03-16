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
/*
题目：输入某年某月某日，判断这一天是这一年的第几天？

程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，特殊情况，闰年且输入月份大于3时需考虑多加一天。

*/
void practice_4(void)
{
    int day,month,year,sum,leap;
  	printf("\n请输入年、月、日，格式为：年,月,日（2015,12,10）\n");
    scanf("%d,%d,%d",&year,&month,&day);  // 格式为：2015,12,10
    switch(month) // 先计算某月以前月份的总天数
    {
        case 1:sum=0;break;
        case 2:sum=31;break;
        case 3:sum=59;break;
        case 4:sum=90;break;
        case 5:sum=120;break;
        case 6:sum=151;break;
        case 7:sum=181;break;
        case 8:sum=212;break;
        case 9:sum=243;break;
        case 10:sum=273;break;
        case 11:sum=304;break;
        case 12:sum=334;break;
        default:printf("data error");break;
    }
    sum=sum+day; // 再加上某天的天数
    if(year%400==0||(year%4==0&&year%100!=0)) {// 判断是不是闰年
        leap=1;
    } else {
       leap=0;
    }
    if(leap==1&&month>2) { // *如果是闰年且月份大于2,总天数应该加一天
        sum++;
    }
    printf("这是这一年的第 %d 天。",sum);
    printf("\n");

}
/*
题目：输入三个整数x,y,z，请把这三个数由小到大输出。

程序分析：我们想办法把最小的数放到x上，先将x与y进行比较，如果x>y则将x与y的值进行交换，然后再用x与z进行比较，如果x>z则将x与z的值进行交换，这样能使x最小。

*/
void practice_5(void)
{
    int x,y,z,t;
    printf("\n请输入三个数字:\n");
    scanf("%d%d%d",&x,&y,&z);
    if (x>y) { /*交换x,y的值*/
        t=x;x=y;y=t;
    }
    if(x>z) { /*交换x,z的值*/
        t=z;z=x;x=t;
    }
    if(y>z) { /*交换z,y的值*/
        t=y;y=z;z=t;
    }
    printf("从小到大排序: %d %d %d\n",x,y,z);
}

/*
题目：用*号输出字母C的图案。

程序分析：可先用'*'号在纸上写出字母C，再分行输出。
*/
void practice_6(void)
{
    printf("用 * 号输出字母 C!\n");
    printf(" ****\n");
    printf(" *\n");
    printf(" * \n");
    printf(" ****\n");
}
/*
题目：输出特殊图案，请在c环境中运行，看一看，Very Beautiful!

程序分析：字符共有256个。不同字符，图形不一样。

VC6.0下出现中文乱码(原因+解决方法):

176的16进制是B0，219的16进制是DB，0xB0DB是"佰"字的内码，所以输出的就是"佰"了。

主要原因是文件信息的代码页不同，我们所使用的操作系统中文状态下的代码页，要显示扩展的ASCII码需要在437 OEM-美国这个下面显示，这样就可以显示出你所希望的。具体修改控制台的默认代码页步骤如下：

    1.点击运行界面左上角标题栏图标【c:\】，选择默认值一项
    2.修改默认代码页，936（ANSI/OEM-简体中文GBK）为437 OEM-美国
    3、关闭后重新运行一下即可

*/
void practice_7(void)
{
	char a=176,b=219;
    printf("%c%c%c%c%c\n",b,a,a,a,b);
    printf("%c%c%c%c%c\n",a,b,a,b,a);
    printf("%c%c%c%c%c\n",a,a,b,a,a);
    printf("%c%c%c%c%c\n",a,b,a,b,a);
    printf("%c%c%c%c%c\n",b,a,a,a,b);
}
/*
题目：输出9*9口诀。

程序分析：分行与列考虑，共9行9列，i控制行，j控制列。
*/
void practice_8(void)
{
	int i,j;
    printf("\n");
    for (i=1;i<=9;i++)
    {
        for(j=1;j<=i;j++)
        {
        	//printf("%d*%d=%-4d",j,i,i*j);
        	printf("%-4d",i*j);
            if(i==j)
            	printf("\n"); /*每一行后换行*/
        }
   
    }
}