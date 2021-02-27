
/*
	2인 플레이로 검은돌(1) 흰돌(2) 차례대로 셋팅
	연속 5개가 대각선 가로 세로 중 1개의 라인이라도
	생성되면 해당되는 돌이 승리



*/


#include<stdio.h>

#define ROW 19
#define COLUME 19

int Board[23][23] = { 0, };

//방향(우,아래,우하,좌하) 탐색
//오목 승리/패배 체크
/*
	같은 방향인 경우 현재 놓인 돌 이전 위치에 같은 돌이 있는지 체크(6목 방지)
	있을 경우, 다른돌을 만날 때까지 이전으로 되돌아가면서 체크하고,
	같은 돌인 마지막 지점에서 다시 현재지점으로 돌아오면서 체크
	5인 경우 승리 판별
*/
int dirCheck(int curY, int curX, int user)
{
	int cnt = 0;
	int nextY = curY, nextX = curX;

	//우측 탐색
	nextY = curY, nextX = curX;

	cnt = 0;
	while (Board[nextY][nextX-1]  == user &&nextX > 0 )
	{
		nextX--;
	}

	while (Board[nextY][nextX] == user && nextX <= COLUME)
	{
		nextX++;
		cnt++;
	}
	if (cnt == 5)
	{
		return user;
	}

	//아래 탐색
	nextY = curY, nextX = curX;

	cnt = 0;
	while (Board[nextY-1][nextX] == user && nextY > 0)
	{
		nextY--;
	}

	while (Board[nextY][nextX] == user && nextY <= ROW)
	{
		nextY++;
		cnt++;
	}
	if (cnt == 5)
	{
		return user;
	}



	//좌하 탐색
	nextY = curY, nextX = curX;

	cnt = 0;
	while (Board[nextY - 1][nextX+1] == user && (nextY > 0 && nextX <COLUME))
	{
		nextY--;
		nextX++;
	}

	while (Board[nextY][nextX] == user && (nextY <= ROW && nextX > 0))
	{
		nextY++;
		nextX--;
		cnt++;
	}
	if (cnt == 5)
	{
		return user;
	}



	//우하 탐색
	nextY = curY, nextX = curX;

	cnt = 0;
	while (Board[nextY - 1][nextX - 1] == user && (nextY > 0 && nextX > 0))
	{
		nextY--;
		nextX--;
	}

	while (Board[nextY][nextX] == user && (nextY <= ROW && nextX <= ROW))
	{
		nextY++;
		nextX++;
		cnt++;
	}
	if (cnt == 5)
	{
		return user;
	}
	return 0;
}
/*
	< ProtoType Code >
	
	- 검은돌 (1) , 흰돌(2)로 데이터를 턴 제로 좌표를 입력하여 셋팅
	- 방향을 매번(0,0)부터 체크
*/

int main()
{
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 20; j++)
		{
			scanf("%d",&Board[i][j]);

			if (Board[i][j] == 0)
			{
				continue;
			}

			
			if (dirCheck(i, j, Board[i][j]) > 0)
			{
				printf("%d\n", Board[i][j]);

				return 0;
			}
			
			
		}
	}
//	printf("%d\n",dirCheck(1, 1, 1));

	printf("Draw\n");

	return 0;
}
