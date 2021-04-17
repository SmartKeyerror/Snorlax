
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

using namespace std;


// 详细描述: https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/sort


// 时间复杂度: 平均 O(nlogn)，最差为 O(n^2)，随机的原因就在于尽可能的避免在每次 partiation 中都选择最差情况
// 空间复杂度: 平均 O(logn)，最差为 O(n)，开销为递归产生的堆栈，算法内部没有额外使用空间


template <typename T>
void __quick_sort(vector<T>& array, int left, int right) {
    if (left >= right) return;

    // 首先，随机选取 [left, right] 这一闭区间中任意一个元素作为“锚定点”
    int anchor = left + rand() % (right - left + 1);
    int v = array[anchor];

    // 将锚定点置于首位
    swap(array[left], array[anchor]);

    // 设 [left+1...lt] 均小于 v, [gt...right] 均大于 v，初始化时该区间应不存在

    // array[left+1...lt] < v
    int lt = left;

    // array[gt...right] > v
    int gt = right + 1;

    // array[lt+1...current) == v
    int current = left + 1;

    while (current < gt) {
        if (array[current] == v) {
            current++;
        }

        // 属于左半部分
        else if (array[current] < v) {
            swap(array[lt + 1], array[current]);
            lt++, current++;
        }

        else {
            swap(array[gt - 1], array[current]);
            gt--;
        }
    }

    // 循环结束后将 anchor 置于正确的位置
    swap(array[left], array[lt]);

    __quick_sort(array, left, lt - 1);
    __quick_sort(array, gt, right);
}


template <typename T>
void quick_sort(vector<T>& array) {
    srand(time(NULL));
    __quick_sort(array, 0, array.size() - 1);
}


int main() {
    vector<int> array {1, 2, 1, 15, 14, 7, 4, 2, 54, 25, 48, 36, 52};

    quick_sort(array);

    for (auto num : array)
        cout << num <<", ";
    cout << endl;

    return 0;
}
