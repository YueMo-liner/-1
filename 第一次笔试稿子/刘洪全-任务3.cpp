#include<stdio.h>
#include<string.h>
#include<windows.h>//引入该函数库，一为使用清屏功能，二为在输入完成后调整鼠标位置，优化体验感。
#include<stdlib.h>

int queren(char zhanghu1[9][40],char zhanghu2[40]);//将通过循环遍历确认登录组与注册组是否匹配以确认登录是否通过
void setGuangbiao(int a,int b);//调整鼠标位置。

int main()
{
	int function,judge,i=0,k=0,t,cnt=0;
	
	char zhanghu1[9][40];
	char mima1[9][40];
	
	char zhanghu2[40];    
	char mima2[40];
	
	
	/*发现汉字和空格占位不一样，查询deepseek,得知，汉字为全角符号，
	数字和英文字符一般为半角字符，即汉字对应两个空格，数字和英文字符对应一个空格*/
	
	for(function=-2;function!=0;)//for循环确保输入为0时才结束程序。
	{
	
	printf("%*s",80,"");//测试得知窗口一行空格有178，为美观我使输出在中间。
		printf("请选择1注册/2登录\n");
	
	scanf("%d",&function);
	
	
	switch(function)
	{
		
	
	case 1://注册部分代码。
	{
		printf("请选择注册账户位置。(1-9)\n");
		scanf("%d",&i);
		i-=1;
		system("cls");
		printf("请输入用户名和密码。\n用户名:\n密码:\n");
	
    	
    	setGuangbiao(7,1);
    	scanf("%s",&zhanghu1[i]);
    	setGuangbiao(5,2);
    	scanf("%s",&mima1[i]);
    	
    	for(t=0,cnt=0;t<9;t++)
    	{
    		
			if(strcmp(zhanghu1[i],zhanghu1[t])==0) cnt+=100;
			
			
		}
    	if(cnt!=100)
    	{
				printf("该账户已存在,请重新输入。\n");
				Sleep(1500);
				goto end;
		}
    
    	
    	k++;
    	i++;
    	 end:;
    	 system("cls");
    	 break;
	} 
	
	
	
	
	
	
	case 2://登录部分代码。
	{
		printf("请输入用户名和密码。\n用户名:\n密码:\n");
		setGuangbiao(7,3);
		scanf("%s",&zhanghu2);
	
		setGuangbiao(5,4);
		scanf("%s",&mima2);
		k++;
		 judge=queren(zhanghu1,zhanghu2); //确认中得出对应账号密码在数组第几位。
		 
		
		if(judge!=-2)
		{
		printf("你好，%s",zhanghu1[judge]);
		Sleep(2000);
			system("cls");
		}
	
		else
		{
		printf("密码错误，请重新输入。") ;
		Sleep(1500);
		system("cls");
			
		}
		break;
	}
	
	
	
	
	
	
     case 0://跳出部分代码。
	{
		system("cls");
		break;
	
	}
	
	
	
	
	
	
	}
	
	}
	return 0;
}

void setGuangbiao(int a,int b)//光标调整代码。
{
		HANDLE eee;
	    	eee=GetStdHandle(STD_OUTPUT_HANDLE);
	    	COORD aaa;
	    	aaa.X=a;  //x==7;y==3;
	    	aaa.Y=b;
			SetConsoleCursorPosition(eee,aaa);
}


int queren(char zhanghu1[9][40],char zhanghu2[40])//确认登录输入账户在注册信息库里是否存在。
{
	int i,judge=-2;
	for(i=0;i<=9;i++)
	{
		
		if(strcmp(zhanghu2,zhanghu1[i])==0)
		{
			judge=i;
			i=10;
		}
		else
		    judge=-2;
	}
	
	
	return judge;//返回注册信息库内排列位置数。
}
