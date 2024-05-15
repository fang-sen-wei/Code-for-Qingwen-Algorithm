//生成+号
//学习的模板！
#include <iostream>
#include <string>
using namespace std;

int n;
string str;

void dfs(int ind, int sum, int& total_sum) {
    if (ind == str.size()) {
        total_sum += sum;
        return;
    }
    
    for (int i = ind; i < str.size(); ++i) {
        string num_str = str.substr(ind, i - ind + 1);
        int num = stoi(num_str);
        dfs(i + 1, sum + num, total_sum);
    }
}

int main() {
    cin >> n;
    str = to_string(n);

    int total_sum = 0;
    dfs(0, 0, total_sum);

    cout << total_sum << endl;
    return 0;
}
