//n皇后问题
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

bool col_exist[11];
int ans;
int n;

void dfs(int row, int help[])//help[i]表示第i行的位置在第几列,若为-1则表示没放
{
	if(row==n) 
	{
		ans++;
		return;
	}
	else//每行作为决策层，尝试放在第i列
	{
		for(int i=0;i<n;i++)
		{
			if(!col_exist[i])
			{
				bool can_put=true;
				for(int j=0;j<row;j++)//与前row行检测有无发生碰撞
				{
					if(abs(i-help[j])==abs(row-j))
					{
						can_put=false;
						break;
					}
				}
				if(can_put)
				{
					help[row]=i;
					col_exist[i]=true;
					dfs(row+1,help);//下一层
					help[row]=-1;//回溯
					col_exist[i]=false;
				}
			}
			
		}
	}
	
}

int main()
{
	scanf("%d",&n);
	int help[n];
	fill(help,help+n,-1);
	fill(col_exist,col_exist+n,false);
	ans=0;
	dfs(0,help);
	printf("%d",ans);
}