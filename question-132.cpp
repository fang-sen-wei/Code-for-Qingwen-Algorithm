//全排列I
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> res;
vector<int> tmp;
int n;
void dfs(int ind, int help[])
{
    if(ind==n+1)
    {
        res.push_back(tmp);
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(help[i-1])
            {
                tmp.push_back(i);
                help[i-1]=0;//表示已经放入
                dfs(ind+1,help);
                tmp.pop_back();
                help[i-1]=1;//表示没放进去
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    int help[n];
    fill(help,help+n,1);
    dfs(1,help);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            if(j>0) printf(" ");
            printf("%d",res[i][j]);
        }
        printf("\n");
    }
}