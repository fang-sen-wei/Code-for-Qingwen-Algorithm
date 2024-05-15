//生成括号对
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParenthesis(vector<string>& result, string current, int open, int close, int n) {
    // 如果左括号和右括号都达到了n个，则将当前字符串添加到结果集中
    if (open == n && close == n) {
        result.push_back(current);
        return;
    }
    
    // 在当前字符串后面添加左括号，但是要确保左括号的数量不超过n
    if (open < n) {
        generateParenthesis(result, current + "(", open + 1, close, n);
    }
    
    // 在当前字符串后面添加右括号，但是要确保右括号的数量不超过左括号的数量
    if (close < open) {
        generateParenthesis(result, current + ")", open, close + 1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesis(result, "", 0, 0, n);
    return result;
}

int main() {
    int n;
    //cout << "Enter the value of n: ";
    cin >> n;
    
    vector<string> result = generateParenthesis(n);
    
    //cout << "All possible valid combinations for " << n << " pairs of parentheses are:" << endl;
    for (string combination : result) {
        cout << combination << endl;
    }
    
    return 0;
}
