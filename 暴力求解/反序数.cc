/**
 * 设N是一个4位数，他的9倍恰好是其反序数。求N的值
 *
 * 
 * 
 */
#include <iostream>
#include <cstdio>

using namespace std;

int Reverse(int x) {
    int revx = 0;
    while(x != 0) {
        revx *= 10;
        revx += x % 10;
        x /= 10;
    }
    return revx;
}

int main() {
    for(int i = 1000; i <= 9999; i++) {
        if(i * 9 == Reverse(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}