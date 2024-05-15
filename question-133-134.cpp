//全排列II 与III，3即元素中有相同元素
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> res;
vector<int> tmp;
int n;
void dfs(int ind, int help[], int list[])
{
    if(ind==n+1)//ind表示决策的第几层
    {
        res.push_back(tmp);
    }
    else
    {
        for(int i=0;i<n;i++)//i在这里表示位置
        {
                if(!help[i]) continue;
                tmp.push_back(list[i]);//放入list[i]位置的元素
                help[i]=0;//表示已经放入
                dfs(ind+1,help,list);
                tmp.pop_back();
                help[i]=1;//表示没放进去
            
        }
    }
}
bool cmp(vector<int> &a,vector<int> &b)
{
    return a<b;
}

int main()
{
    scanf("%d",&n);
    int help[n];
    fill(help,help+n,1);
    int list[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
   
    dfs(1,help,list);
    sort(res.begin(),res.end(),cmp);
    for(int i=0;i<res.size();i++)
    {
        if(i>0 and res[i]==res[i-1]) continue;
        for(int j=0;j<res[i].size();j++)
        {
            if(j>0) printf(" ");
            printf("%d",res[i][j]);
        }
        printf("\n");
    }
}