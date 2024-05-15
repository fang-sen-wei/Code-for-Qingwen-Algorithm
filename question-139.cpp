//游园会
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int num;
set<int> a;

const int maxn=13;
int list[maxn];
//每一层决策的应该是选该元素或者不选该元素
//做递归的题目一定要思考好它的递归树是怎么样的
void dfs(int index,int sum)
{
    if(index==num)  a.insert(sum);
    else
    {
        dfs(index+1,sum);//不选择index层的元素，并递归到下一层
        dfs(index+1,sum+list[index]);//选择该层index的元素，并递归到下一层
    }
}

int main()
{
    scanf("%d",&num);//num个项目
    for(int i=0;i<num;i++) scanf("%d", &list[i]);//list【i】为对应的得分
    dfs(0,0);
    int first=1;
    for(auto x:a)
    {
        if(first) 
        {printf("%d",x);first=0;}
        else printf(" %d",x);
    }
    
}