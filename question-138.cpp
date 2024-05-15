//单词排列
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<vector<char>> res;
vector<char> tmp;
int n;

void dfs(int ind, int help[], string list) {
    if (ind == n + 1) { // 当ind等于n+1时，表示一个排列已经完成
        res.push_back(tmp);
        return;
    }
    for (int i = 0; i < n; i++) { // 遍历所有位置
        if (!help[i]) continue; // 如果该位置的元素已经被使用，则跳过
        tmp.push_back(list[i]); // 放入list[i]位置的元素
        help[i] = 0; // 标记该位置的元素已经被使用
        dfs(ind + 1, help, list); // 递归到下一层
        tmp.pop_back(); // 回溯，移除当前元素
        help[i] = 1; // 标记该位置的元素未被使用
    }
}

bool cmp(vector<char> &a, vector<char> &b) {
    return a < b; // 用于排序的比较函数
}

int main() {
    string list;
    cin >> list;
    n = list.size();
    int help[n];
    fill(help, help + n, 1); // 初始化help数组，所有元素都标记为未使用

    dfs(1, help, list); // 从第一个位置开始进行排列
    sort(res.begin(), res.end(), cmp); // 对结果进行排序
    for (int i = 0; i < res.size(); i++) {
        if (i > 0 && res[i] == res[i - 1]) continue; // 跳过重复的排列
        for (int j = 0; j < res[i].size(); j++) {
            printf("%c", res[i][j]); // 打印当前排列的每个字符
        }
        printf("\n");
    }
}
