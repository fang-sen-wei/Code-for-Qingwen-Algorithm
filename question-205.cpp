#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
//使用埃拉托斯特尼筛法
const int MAXN = 1000000 + 1;
bool isPrime[MAXN];
vector<int> primes;

void getPrimes(int n) {
    fill(isPrime,isPrime+MAXN,true);
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {//如果是素数，加入list
            primes.push_back(i);
            for (int j = i + i; j <= n; j += i) {//对于素数的倍数一直到n都不是素数
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getPrimes(n);
    for (int i = 0; i < primes.size(); i++) {
        printf("%d\n", primes[i]);
    }
    return 0;
}
