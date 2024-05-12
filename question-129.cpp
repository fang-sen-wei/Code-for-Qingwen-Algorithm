//子集I
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<vector<int>> res;
vector<int> temp;
void DFS(int index)
{
    if(index==n+1)
    {
        res.push_back(temp); //到达树的底部时，为一个方案，选如
    }
    else
    {
        temp.push_back(index);  //在本决策层选中元素
        DFS(index+1);           //递归到下一层
        temp.pop_back();        //删除该元素
        DFS(index+1);           //递归下一层，即不选择本层该元素的情况
    }
}

bool cmp(vector<int> a,vector<int> b)//&为引用，即会真的改变源对象
{
    if(a.size()!=b.size()) return a.size()<b.size();
    else return a<b;
}

int main()
{
    scanf("%d",&n);
    DFS(1);
    sort(res.begin(),res.end(),cmp);
    for(int i=0;i<res.size();i++)
    {
        bool first=1;
        for(int j=0;j<res[i].size();j++)
        {
            if(first)//每行第一个前面没有空格
            {
                 printf("%d",res[i][j]);
                 first=0;
            }
            else printf(" %d",res[i][j]);
        }
        printf("\n");
    }
}

/*
要更好地理解这个DFS（深度优先搜索）过程，我们可以将其比作一个决策树，每个节点代表一个决策点，即选择包含或不包含当前元素。
让我们通过一个具体的例子来解释这个过程，假设`n = 3`。
1. **决策树的根节点**:
   - 考虑第一个元素`1`。我们有两个选择：包含它或不包含它。
2. **第一层决策**:
   - **包含1**: 我们将`1`添加到`temp`中，然后考虑下一个元素`2`。
   - **不包含1**: 我们直接考虑下一个元素`2`，而不改变`temp`。
3. **第二层决策**:
   - 对于每个包含或不包含`1`的情况，我们现在都要对`2`做出同样的选择：包含或不包含。
   - 这会产生四种情况：`{1, 2}`, `{1}`, `{2}`, ``（空集）``。
4. **第三层决策**:
   - 对于每个包含或不包含`1`和`2`的情况，我们现在都要对`3`做出选择。
   - 这会产生八种情况：`{1, 2, 3}`, `{1, 2}`, `{1, 3}`, `{1}`, `{2, 3}`, `{2}`, `{3}`, ``（空集）``。
5. **递归终止**:
   - 当我们到达`4`（`n + 1`）时，由于没有更多的元素可供选择，我们将`temp`中的当前子集添加到`result`中，并返回。
通过这个过程，我们可以看到DFS如何通过在每个决策点选择包含或不包含当前元素来生成所有可能的子集。
这个决策树的结构确保了每个子集都被探索一次，并且所有可能的组合都被考虑到了。

*/
