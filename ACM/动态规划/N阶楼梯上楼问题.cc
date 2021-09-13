/**
 * 一次可以走两阶或一阶，问有多少种上楼方式
 * 输入一个整数N, 可能有多组输入
 * 
 */
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 91;

long long dp[MAXN];

int main() {
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < MAXN; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%lld\n", dp[n]);
    }
    return 0;
}