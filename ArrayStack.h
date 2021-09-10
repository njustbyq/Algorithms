#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include <iostream>

using namespace std;
//模板类
template<class T>
class ArrayStack {
public:
    ArrayStack();
    ~ArrayStack();
    void push(T t); //向栈中添加一个元素t
    T peek();   //从栈中取出一个元素
    T pop();    //从栈中删除一个元素
    int size(); //大小
    int isEmpty();  //判断是否为空
private:
    T *arr;
    int count;
};
//初始化
template<class T>
ArrayStack<T>::ArrayStack() {
    arr = new T[12];
    if(!arr) {
        cout << "arr malloc error!" << endl;
    }
    count = 0;
}
//析构函数
template<class T>
ArrayStack<T>::~ArrayStack() {
    if(arr) {
        delete[] arr;
        arr = NULL;
    }
}

template<class T>
void ArrayStack<T>::push(T t) {
    arr[count++] = t;
}

template<class T>
T ArrayStack<T>::peek() {
    return arr[count - 1];
}

template<class T>
T ArrayStack<T>::pop() {
    int ret = arr[count - 1];
    count--;
    return ret;
}

template<class T>
int ArrayStack<T>::size() {
    return count;
}

template <class T>
int ArrayStack<T>::isEmpty() {
    return size() == 0;
}
#endif