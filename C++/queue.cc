/**
 * C++ : 数组实现“队列”，能存储任意数据。
 *
 * @author yqbao
 * @date 2021/9/10
 */
#include <iostream>
#include "ArrayQueue.h"
using namespace std;

int main() {
    int tmp = 0;
    ArrayQueue<int> *aqueqe = new ArrayQueue<int>();

    aqueqe->add(10);
    aqueqe->add(20);
    aqueqe->add(30);

    //将"队列开头元素"赋值给tmp, 并删除该元素
    tmp = aqueqe->pop();
    cout << "tmp = " << tmp << endl;

    //只将队列的开头的元素赋值给tmp,不删除该元素
    tmp = aqueqe->front();
    cout << "tmp = " << tmp << endl;

    aqueqe->add(40);

    cout << "is_empty() = " << aqueqe->is_empty() << endl;
    cout << "size() = " << aqueqe->size() << endl;
    while(!aqueqe->is_empty()) {
        tmp = aqueqe->pop();
        cout << tmp << endl;
    }

    return 0;

}