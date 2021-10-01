/**
 * 输入一个数n，然后输入n个不同的数值，再输入一个值x，
 * 输出这个值再数组中的下标
 * 
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 200;

int arr[MAXN];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int x;
        scanf("%d", &x);
        int answer = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] == x) {
                answer = i;
                break;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}