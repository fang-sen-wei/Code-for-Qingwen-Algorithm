//有限制的选数I
#include<cstdio>
#include<vector>
#include<set>
using namespace std;

vector<vector<int>> r;
vector<int> temp;
int ans=0;
int list[13];
int m;//目标值

void dfs(int ind,int sum)
{
    if(sum==m) ans++;
    else if(sum>m or ind>11) return;
    else
    {
        dfs(ind+1,sum);
        dfs(ind+1,sum+list[ind]);
    }
}
int main()
{
    int n;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    dfs(0,0);
    printf("%d",ans);
}