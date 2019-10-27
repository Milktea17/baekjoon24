/////////////////////////////////////////////
// 백준 11723번
/////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
int main(){

	int M=0,d,n,S=0;
	char command[7];
	scanf("%d",&M);

	for(int i=0;i<M;i++)
	{
		memset(command,'\0',sizeof(command));
		scanf("%s %d",&command,&n);

		if(strcmp(command,"add") == 0)
			S |= (1 << n);

		else if(strcmp(command,"remove") == 0)
			S &= ~ (1 << n); //나머지는 1이고 그 부분만 0이니까 0으로 만들 수 있음

		else if(strcmp(command,"check") == 0)
		{
			if(S & (1 << n))
				printf("1\n");
			else
				printf("0\n");
		}

		else if(strcmp(command,"toggle") == 0)
			S ^= (1 << n);

		else if(strcmp(command,"all") == 0)
			S = (1 << 21) - 1;

		else if(strcmp(command,"empty") == 0)
			S = 0;
	}
	
	return 0;
}