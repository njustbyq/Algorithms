/**
 * 打印所有不超过256，其平方具有对称性质的数
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
    for(int i = 0; i <= 256; i++) {
        if(i * i == Reverse(i * i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}