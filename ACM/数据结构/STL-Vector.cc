#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> myVector;

int main() {
    for (int i = 0; i < 5; i++) {
        myVector.push_back(i);
    }
    myVector.insert(myVector.begin(), 3, 15); //在头部插入三个15
    myVector.pop_back();
    for (int i = 0; i < myVector.size(); i++) {
        printf("%d ", myVector[i]);
    }
    printf("\n");
    printf("the 5th element of myVector: %d\n", myVector[4]);
    printf("the size of myVector: %d\n", myVector.size());
    myVector.erase(myVector.begin() + 5, myVector.end()); //删除第五后续的元素
    vector<int>::iterator it;
    for (it = myVector.begin(); it != myVector.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    myVector.clear();
    return 0;
}
