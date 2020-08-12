/*

	기존의 snail 알고리즘과 같이 접근
	(단, 입력받은 행과 열이 동일 하지 않을 수 있으니 이 부분 고려해야함)

	N과M을 입력받으며 N과 M중 작은 수를 cnt에 저장( 전체적으로 탐색 'ㄱ'자 혹은 'ㄴ'자)

	열 먼저 탐색 시작 (M만큼 탐색)
	- 탐색하면서 sw변수만큼 연산하면서 이동

	행 탐색 시작(N-1만큼이동)
	- 탐색하면서 sw변수만큼 연산하면서 이동

	둘다 끝나면 N과 M을 -1씩 감소
	sw 변수도 -1을 곱하여 전환

	위의 과정을 cnt만큼 반복

	방향이 꺽일떄마다 결과를 카운트해야하므로
	swFlag를 두어 열 혹은 행 탐색 때 플래그를 1로 설정하고
	탐색이 끝나고 swFlag가 1인 경우 결과 카운트 시작
	swFlag=0으로 초기화

	마지막 행또는 열을 탐색할 때 swFlag가 1이되어 결과 카운트
	가 증가하므로 결과 값 출력 시 ret-1로 감소시켜 출력

*/
#include<stdio.h>

int N,M;
int sw = 1;
int map[101][101];

int minFunc(int n1,int n2)
{
	if(n1 > n2)
		return n2;
	return n1;
}

int main()
{
	int curY=0,curX=-1;
	int i,j,k;
	int row=0,col=0,cnt=0;
	int num=1,ret=0;

	scanf("%d %d",&N,&M);

	row=N;
	col=M;

	cnt=minFunc(N,M);

	for(i=0;i<cnt;i++)
	{
		int swFlag=0;

		for(j=0;j<col;j++)
		{
			curX= curX+sw;

			map[curY][curX]=num++;
			swFlag=1;
		}

		if(swFlag==1)
			ret++; //꺽일떄 카운트

		swFlag=0;
		
		for(k=0;k<row-1;k++)
		{
			swFlag=1;
			curY= curY+sw;
			
			map[curY][curX]=num++;
		}

		if(swFlag == 1)
			ret++;

		sw = sw * (-1);
		row--;
		col--;
	}
/*
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
*/
	printf("%d\n",ret-1);
	return 0;
}
