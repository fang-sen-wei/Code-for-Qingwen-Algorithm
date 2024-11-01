//可能的出栈序列
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<vector<int>> res; // 用于存储所有的出栈序列
vector<int> temp; // 用于存储当前的出栈序列
stack<int> s; // 模拟栈
int n;

// 递归函数，num表示当前入栈的数字
void dfs(int num)
{
    // 如果当前出栈序列的长度等于n，说明找到了一个完整的序列
    if(temp.size() == n) {
        res.push_back(temp);
        return;
    }

    // 如果还有未入栈的数字，则继续入栈
    if(num <= n) {
        s.push(num); // 进栈
        dfs(num + 1); // 递归
        s.pop(); // 回溯，出栈
    }

    // 如果栈不为空，则可以出栈
    if(!s.empty()) {
        int top = s.top(); // 获取栈顶元素
        s.pop(); // 出栈
        temp.push_back(top); // 加入当前的出栈序列
        dfs(num); // 递归
        temp.pop_back(); // 回溯，移除出栈的元素
        s.push(top); // 回溯，重新入栈
    }
}

int main()
{
    cin >> n;
    dfs(1);
    
    sort(res.begin(), res.end()); // 按字典序排序
    for(const auto& seq : res) {
        for(int i = 0; i < seq.size(); ++i) {
            if(i > 0) cout << " ";
            cout << seq[i];
        }
        cout << endl;
    }
    
    return 0;
}
