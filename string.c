#include<stdio.h>
int main(int argc,char* argv[])
{
	char *str="abcd";
	if(strcmp(argv[1],str)==0)
		printf("YES");
	else
		printf("NO");
	return 0;
}
