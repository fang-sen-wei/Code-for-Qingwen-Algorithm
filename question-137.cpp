//组合数,直接做组合数3，这条会写，前两题也会
//该写法相当于把所有的num中任取n个数的排列情况都搞出来，然后再通过sort排序判断是否相同
//完全有很多不必要的工作，耗时很长，改进的参考question-137-new.cpp
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int num,n;
vector<vector<int>> res;
vector<int> temp;
const int maxn=13;
int list[maxn];

void dfs(int ind, int help[])
{
    if(ind==n)
    {
        res.push_back(temp);
    }
    else
    {
        for(int i=0;i<num;i++)
        {
            if(!help[i]) continue;
            temp.push_back(list[i]);
            help[i]=0;
            dfs(ind+1,help);
            temp.pop_back();
            help[i]=1;
        }
    }
}

bool cmp(vector<int> &a,vector<int> &b)
{
    return a<b;
}

int main()
{
    scanf("%d %d",&num,&n);//一共num个元素，随机取n个，形成组合数
    for(int i=0;i<num;i++) scanf("%d", &list[i]);
    int help[num];
    fill(help,help+num,1);
    dfs(0,help);
    for(int i=0;i<res.size();i++)
    {
        sort(res[i].begin(),res[i].end());
    }
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