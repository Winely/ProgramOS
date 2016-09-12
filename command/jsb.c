#include <stdio.h>

int main(int argc, char * argv[])
{
	int random[25]={3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3};
	char gamer;  // 玩家出拳
	int computer;  // 电脑出拳
	int result;  // 比赛结果
	int time = 0, score = 0;// 第几次玩
				 // 为了避免玩一次游戏就退出程序，可以将代码放在循环中
	printf("===============================================================================\n");
	printf("                      Welcome to +1's SHITOU-JIANDAO-BU \n");
	printf("                  Follow the instruction and enjoy the app :)\n");
	printf("===============================================================================\n");
	while (1) {
		printf("J: JIAN DAO\nS: SHI TOU\nB: BU\nQ: Quit\n");
		printf("Please enter your choose: ");
		int argc2;
		char* argv2[2];
		scanWord(&argc2, argv2);
		gamer=argv2[0][0];
		switch (gamer) {
		case 'j':case'J':
			gamer = 4;
			break;
		case 's':case 'S':
			gamer = 7;
			break;
		case 'b': case'B':
			gamer = 10;
			break;
		case 'q': case'Q':
			printf("===============================================================================\n");
			printf("                       Thanks for using +1's Game! \n");
			printf("===============================================================================\n");
			return 0;

		default:
			printf("Your choice %c is wrong,exit...\n", gamer);
			scanWord(&argc2, argv2);
			//clearScreen();
			return 0;
			break;
		}

		computer = random[time] % 3;  // 产生随机数并取余，得到电脑出拳
		result = (int)gamer + computer;  // gamer 为 char 类型，数学运算时要强制转换类型
		printf("The computer chooses ");
		switch (computer)
		{
		case 0:printf("JIAN DAO\n"); break; //4    1
		case 1:printf("SHI TOU\n"); break; //7  2
		case 2:printf("BU\n"); break;   //10 3
		}
		printf("You choose ");
		switch (gamer)
		{
		case 4:printf("JIAN DAO\n"); break;
		case 7:printf("SHI TOU\n"); break;
		case 10:printf("BU\n"); break;
		}
		if (result == 6 || result == 7 || result == 11)
		{
			score+=10;		
			printf("You win!\n");
		}
		else if (result == 5 || result == 9 || result == 10) 
		{
			score-=10;		
			printf("The computer win!\n");
		}
		else printf("Tie!\n");
		//system("pause>nul&&cls");  // 暂停并清屏
		if(++time == 25) time =0;
		printf("Your score: %d\n", score);
		if(score<=-50) printf(">>>>>>>  Too young, sometimes naive.  (by Him.)<<<<<<<<\n");
		else if(score >=50) printf(">>>>>>>      Exciting!     <<<<<<<\n");
		printf("\n");
	}
	return 0;
}
