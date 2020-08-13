/*
	해당되는 숫자의 모든 경우의 수를 순열을 이용하여 구한다.
	순열로 나온 숫자들을 소수가 맞는지 체크하여 카운트한다.

	


*/
#include<stdio.h>
#include<string.h>

char str[8];
char ret[8];
int strLen=0;
int visit[8];


void perm(int cnt,int dep,int pick)
{
	int i;

	if(cnt == pick)
	{

		for(i=0;i<dep;i++)
		{
			printf("%c",ret[i]);
		}
		printf("\n");
		return;
	}

	for(i=0;i<strLen;i++)
	{
		if(visit[i] == 1)
		{
			continue;
		}

		visit[i]=1;
		ret[dep]=str[i];
		perm(cnt+1,dep+1,pick);
		visit[i]=0;
	}

}

int main()
{
	int i;

	scanf("%s",str);

	strLen=strlen(str);
	
	for(i=1;i<=strLen;i++)
	{
		perm(0,0,i);

	}
	return 0;
}
