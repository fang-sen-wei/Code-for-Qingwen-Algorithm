#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1000000 + 1;
bool isPrime[MAXN];
vector<int> primes;

void getPrimes(int n) {
    fill(isPrime,isPrime+MAXN,true);
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i + i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
//先求出大概一个范围内所有的素数
int main() {
    int n;
    scanf("%d", &n);
    getPrimes(MAXN);
    int ind=0;
    //然后直接暴力搜索即可，符合孪生条件的ind++，直到ind==n即可
    for(int i=1;i<primes.size();i++)
    {
        if(primes[i]-primes[i-1] == 2)
        {
            ind++;
        }
        if(ind==n)
        {
            printf("%d %d",primes[i-1],primes[i]);
            break;
        }

    }
    return 0;
}