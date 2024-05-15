//判断八皇后问题
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;
int n;
int main()
{
	bool t=true;
	int list[8][8];
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			scanf("%d",&list[i][j]);
		}
	}
	bool k=true;
	int help[8];
	fill(help,help+8,0);
	for(int i=0;i<8;i++)//每行
	{
		int count=0;
		for(int j=0;j<8;j++)
		{
			if(list[i][j]==1)
			{
				count++;//每行的皇后数目
				help[i]=j;//第i行的皇后在第j列
			}
		}
		if(count>1)
		{
			k=false;
			break;
		}
	}
	for(int i=0;i<8;i++)
	{
		for(int j=i+1;j<8;j++)
		{
			if(help[i]==help[j])
			{
				k=false;
				break;
			}
			if(abs(help[i]-help[j])==abs(i-j))
			{
				k=false;
				break;
			}
		}
	}

	if(k) printf("YES");
	else printf("NO");
}