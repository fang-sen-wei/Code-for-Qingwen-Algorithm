#include <cstdio>
//旋转数组最小值i ii
const int MAXN = 100000;
int n, a[MAXN];

int binarySearch() {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < a[r]) {//中间比右边小，说明最小值在左边
            r = mid;
        } else {//否则在右边
            l = mid + 1;
        }
    }
    return a[l];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d", binarySearch());
    return 0;
}