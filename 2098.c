#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int MAP[17][17];
int cache[17][1<<17];
int MIN = 987654321;
int N;

int TSP(int cur, int visited); //현재도시, 방문한도시들

int main()
{
	scanf("%d",&N);

	if(N < 2 || N >16)
	{
		printf("[N:%d]N은 2이상 16이하로 입력해주세요\n",N);
		return -1;
	}

	int i,j,m;

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&m);
			MAP[i][j]=m;
		}
	}

	memset(cache,-1,sizeof(cache));
	printf("%d\n",TSP(0,1));

	return 0;
}

int TSP(int cur, int visited)
{
	if(visited == (1<<N)-1) //N만큼 1갯수(모두 방문했을 때)
    {
       if (MAP[cur][0] != 0)
               return MAP[cur][0];

       return MIN;	
   }

	int &result = cache[cur][visited];  //메모이제이션, 이전 것 꺼내봄

	if(result != -1) //-1아니면 방문했으니까
		return result;
	result = MIN;

	for(int i=0;i<N;i++)
	{
		if(visited & (1<<i) || MAP[cur][i] == 0) //지나갔거나 0이면 패스
			continue;

		int tmp = MAP[cur][i] + TSP(i,visited+(1<<i));
		result = min(tmp,result);
	}
	return result;

}
