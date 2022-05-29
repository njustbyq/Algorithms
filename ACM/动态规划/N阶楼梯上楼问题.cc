/**
 * 一次可以走两阶或一阶，问有多少种上楼方式
 * 输入一个整数N, 可能有多组输入
 * 
 * Solution:
 * 当n大于2的时候, 考虑每种上台阶方式的最后一步, 由于只有两种行走方式,
 * 因此它只可能是从n-1阶走到n阶, 或从n-2阶走到n阶
 * 即将此时所有的上楼梯方式按照最后一步走法的不同分成两类，分别确定这两类的上楼梯方式的数目。
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