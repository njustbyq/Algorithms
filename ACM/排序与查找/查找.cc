/**
 * 输入有多组数据
 * 每组输入n, 然后输入n个整数，再输入m，最后输入m个整数
 * 若在n个数组中，则输出YES，否则输出NO
 * 
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int arr[MAXN];

bool BinarySearch(int n, int target) {
    int left = 0;
    int right = n - 1;
    while(left <= right) {
        int middle = (left + right) / 2;
        if(arr[middle] < target) {
            left = middle + 1;
        }else if(arr[middle] > target) {
            right = middle - 1;
        }else {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            int target;
            scanf("%d", &target);
            if(BinarySearch(n, target)) {
                printf("YES\n");
            }else {
                printf("NO\n");
            }
        }
    }
    return 0;
}

