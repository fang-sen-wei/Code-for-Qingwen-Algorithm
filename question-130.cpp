//子集II
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=13;
int list[maxn];//存储集合里的数字
int n;//集合中有几个数字
vector<vector<int>> res;
vector<int> tmp;

void DFS(int index, int list[])
{
    if(index==n+1)
    {
        res.push_back(tmp);
    }
    else
    {
        tmp.push_back(list[index-1]);//index=1开始，list索引从0开始，故-1
        DFS(index+1,list);
        tmp.pop_back();
        DFS(index+1,list);
    }
}

bool cmp(vector<int> a, vector<int> b)
{
    if(a.size()!=b.size()) return a.size()<b.size();
    else return a<b;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    DFS(1,list);
    sort(res.begin(),res.end(),cmp);
    for(int i=0;i<res.size();i++)
    {
        int first=1;
        for(int j=0;j<res[i].size();j++)
        {
            if(first)
            {
                printf("%d",res[i][j]);
                first=0;
            }
            else printf(" %d",res[i][j]);
        }
        printf("\n");
    }

}