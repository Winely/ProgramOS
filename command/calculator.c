#include "stdio.h"

int add_fun(int x,int y)
{
	return x+y;
}
int sub_fun(int x,int y)
{
	return x-y;
}  
int mul_fun(int x,int y)
{
	return x*y;
}  
int div_fun(int x,int y)
{
	return x/y;
} 

void dealWithCal(char* command)
{
	while(1){
		strlwr(command);
		if (strcmp(command,"add")==0)
		{
			printf("Enter the two numbers you want to add with a space:");
			int x,y;
			int argc2;
			char* argv2[1024];
			scanWord(&argc2, argv2);
			x=char2int(argv2[0]);
			y=char2int(argv2[1]);
			int result = add_fun(x,y);
			printf("result: %d\n", result);
			return ;
		}
		else if (strcmp(command,"minus")==0)
		{
			printf("Enter the two numbers you want to minus with a space:");			
			int x,y;
			int argc2;
			char* argv2[3];
			scanWord(&argc2, argv2);
			x=char2int(argv2[0]);
			y=char2int(argv2[1]);
			int result = sub_fun(x,y);
			// printf("minus:x:%d\n", x);
			printf("result: %d\n", result);
			return ;
		}
		else if (strcmp(command,"multiply")==0)
		{
			printf("Enter the two numbers you want to multiply with a space:");
			int x,y;
			int argc2;
			char* argv2[3];
			scanWord(&argc2, argv2);
			x=char2int(argv2[0]);
			y=char2int(argv2[1]);
			int result = mul_fun(x,y);
			printf("result: %d\n", result);
			return ;
		}
		else if (strcmp(command,"divide")==0)
		{
			printf("Enter the two numbers you want to divide with a space:");
			int x,y;
			int argc2;
			char* argv2[3];
			scanWord(&argc2, argv2);
			x=char2int(argv2[0]);
			y=char2int(argv2[1]);
			int result = div_fun(x,y);
			printf("result: %d\n", result);
			return;
		}
		else if (strcmp(command,"quit")==0) break;
		else printf("can not find this command\n");
	}
}


void strlwr(char *str)
{
	int i;
	for (i=0; i<strlen(str); i++)
	{
		if ('A'<=str[i] && str[i]<='Z') str[i]=str[i]+'a'-'A';
	}
}


int main(int argc, char * argv[])
{
	printf("===============================================================================\n");
	printf("                         Welcome to +1's Calculator! \n");
	printf("                  Follow the instruction and enjoy the app :)\n");
	printf("===============================================================================\n");
	while(1){
		printf("choose a method:[add, minus, multiply, divide, quit]\n");
		int argc2;
		char* argv2[2];
		scanWord(&argc2, argv2);
		if (strcmp(argv2[0],"quit")==0) break;
		dealWithCal(argv2[0]);
	}
	printf("===============================================================================\n");
	printf("                       Thanks for using +1's Calculator! \n");
	printf("===============================================================================\n");
	printf("\n");
	return 0;
}

