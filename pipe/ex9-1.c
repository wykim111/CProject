#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE* fp;
	int i;

	fp = popen("wc -l","w");

	if(fp==NULL)
	{
		fprintf(stderr, "popen failed\n");
		exit(1);
	}

	for(i=0; i <100; i++)
	{
		fprintf(fp,"test line\n");
	}

	pclose(fp);

	return 0;
}
