//自然数分解之方案以及方案数
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<vector<int>> res;
vector<int> tmp;
int ans = 0;
int n;

void dfs(int start)//从strat开始加 
{
    int sum = accumulate(tmp.begin(), tmp.end(), 0);//算出临时存储的求和
    if (sum == n)//若存储的数之和==n,找到方案，存入结果，方案+1 
    {
        res.push_back(tmp);
        ans++;
    } 
    else 
    {
        for (int i = start; i <= n-1; i++)//每一层决策的加数范围从1到n-1 
        {
            if((sum+i)>n) break;//剪枝，说明该数已经不符合条件，没有必要后面的循环了
            tmp.push_back(i);//加i
            dfs(i);//下一层仍从i开始加
            tmp.pop_back();//回溯
        }
    }
}
//其实不需要sort和cmp，本身从1开始枚举往后加
bool cmp(vector<int> a, vector<int> &b) 
{
    if (a.size() != b.size()) return a.size() > b.size();
    else return a < b;
}

int main() {
    scanf("%d", &n);
    dfs(1);
    //sort(res.begin(), res.end(), cmp);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            if (j > 0) printf("+");
            printf("%d", res[i][j]);
        }
        printf("\n");
    }
    printf("%d", ans);
}
