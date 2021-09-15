/**
 * 输入任意序列，可以获得成绩从高到低或从低到高的排序，相同成绩按先录入者排在前面
 * 输入多行，首先输入要排序的人的个数，然后输入排序方法0, 1
 * 再分别输入他们的名字和成绩，以一个空格隔开
 * 按照指定方式输出名字和成绩，以一个空格隔开
 * 
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int score;
    int order;
};

bool CompareDescending(Student x, Student y) {
    if(x.score == y.score) {
        return x.order < y.order;
    } else {
        return x.score > y.score;
    }
}

bool CompareAscending(Student x, Student y) {
    if(x.score == y.score) {
        return x.order < y.order;
    } else {
        return x.score < y.score;
    }
}

int main() {
    int n;
    int type;
    while (scanf("%d%d", &n, &type) != EOF) {
        Student arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i].name >> arr[i].score;
            arr[i].order = i;
        }
        if (type == 0) {
            sort(arr, arr + n, CompareDescending);
        } else {
            sort(arr, arr + n, CompareAscending);
        }
        for(int i = 0; i < n; i++) {
            cout << arr[i].name << " " << arr[i].score << endl;
        }
    }
    return 0;
}
