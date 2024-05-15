//背包问题
//dfs
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> res;
int n,w_max;
int weight[13];
int money[13];
void dfs(int ind, int w_max, int val)
{
    if(ind==n and w_max>=0)
    {
        res.push_back(val);
        return;
    }  
    if((w_max-weight[ind])<0)
    {
        res.push_back(val);
        return;
    } 
    dfs(ind+1,w_max,val);
    if((w_max-weight[ind]) >=0)
    {
        dfs(ind+1,w_max-weight[ind],money[ind]+val);//本层装了ind位置的物品，往下一层
    }
}
int main()
{
    scanf("%d %d",&n,&w_max);
    for(int i=0;i<n;i++) scanf("%d",&weight[i]);
    for(int i=0;i<n;i++) scanf("%d",&money[i]);

   
    dfs(0,w_max,0);
    printf("%d",*max_element(res.begin(),res.end()));

}
