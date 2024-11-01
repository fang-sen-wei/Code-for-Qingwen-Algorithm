#include <stack>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    stack<int> st;
    int index = 0;
    int num = 1;//入栈的数字
    //不知道啥时候结束，用while
    while (num <= n || !st.empty()) {
        if (!st.empty() && st.top() == list[index]) {
            st.pop();
            index++;
        } else if (num <= n) {
            st.push(num++);
        } else {
            break;
        }
    }

    if (st.empty() && index == n) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
