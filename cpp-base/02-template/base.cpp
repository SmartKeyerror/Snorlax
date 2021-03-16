
#include "base.h"
#include <iostream>

using namespace std;

int main() {
    const double a = 1.0, b = 5.0, c = 4.0;
    cout<<"The max value is: "<<maxOfThree(a, b, c)<<endl;

    int i = 15, j = 10, k = 225;
    cout<<"The max value is: "<<maxOfTwo<int>(10, 25.0)<<endl;

    // 全特化
    BuzVector<int, InvisibleAllocator> buzVector;

    // 偏特化
    BuzVector<bool, InvisibleAllocator> boolVector;
}