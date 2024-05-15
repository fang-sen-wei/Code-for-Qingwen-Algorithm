//组合数,直接做组合数3，这条会写，前两题也会
//改进新版
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int num,n;
vector<vector<int>> res;
vector<int> temp;
const int maxn=13;
int list[maxn];

void dfs(int start)
{
    if(temp.size()==n)//取n个数，所以临时存储==n时存入
    {
        res.push_back(temp);
    }
    else if(temp.size()>n or start>=num) return;
    else
    {
        for(int i=start;i<num;i++)//i表示可用的下标，从start到num-1
        {
            temp.push_back(list[i]);//每次存入位置为i的元素
            dfs(i+1);//下次递归i+1下标开始的元素，避免重复使用同一元素
            temp.pop_back();//回溯
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
    
    dfs(0);
    sort(res.begin(),res.end(),cmp);
    //这里需要排序，并且筛选不需要的元素，因为相同元素会产生相同的temp，如1 1 3 4，会产生两个1 3 4，并且位置不相邻
    //需要排序
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