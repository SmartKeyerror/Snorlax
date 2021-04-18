
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;


// 详细描述: https://github.com/SmartKeyerror/Snorlax/tree/master/algorithm/sort


// 时间复杂度: 平均 O(nlogn)，最差为 O(n^2)，随机的原因就在于尽可能的避免在每次 partiation 中都选择最差情况
// 空间复杂度: 平均 O(logn)，最差为 O(n)，开销为递归产生的堆栈，算法内部没有额外使用空间


// 插入排序，小范围内数组排序的最快方式，在近乎有序的情况下，插入排序的效率非常高
template<typename T>
void insertion_sort(vector<T>& array, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        T e = array[i];

        // j 保存元素 e 应该插入的位置
        int j = i;
        for ( ; j > 0 && array[j-1] > e; j--) {
            array[j] = array[j-1];
        }
        array[j] = e;
    }
}


template <typename T>
void __quick_sort(vector<T>& array, int left, int right) {

    // 这里可以做一个简单的小优化: 当 right - left 小于某一个值的时候，使用插入排序对剩下的元素进行排序
    // if (left >= right) return;
    
    if (right - left <= 15) {
        insertion_sort(array, left, right);
        return;
    }
        

    // 首先，随机选取 [left, right] 这一闭区间中任意一个元素作为“锚定点”
    int anchor = left + rand() % (right - left + 1);
    int v = array[anchor];

    // 将锚定点置于首位
    swap(array[left], array[anchor]);

    // 设 [left+1...lt] 均小于 v, [gt...right] 均大于 v，初始化时该区间应不存在

    int lt = left;
    int gt = right + 1;
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
    srand(time(nullptr));
    __quick_sort(array, 0, array.size() - 1);
}


vector<int> generate_random_int_array(int n, int range_l, int range_r) {
    vector<int> array(n);
    srand(time(nullptr));

    for (int i = 0; i < n; i++) {
        array[i] = range_l + rand() % (range_r - range_l + 1);
    }
    return array;
}


template<typename T>
bool is_sorted(const vector<T>& array) {
    for (int i = 0; i < array.size() - 1; i++) {
        if (array[i] > array[i+1]) return false;
    }
    return true;
}


template<typename T>
void test_sort(const string& funcname, void(*sort)(vector<T>&), vector<T>& array) {
    
    clock_t start_time = clock();

    sort(array);

    clock_t end_time = clock();

    cout << funcname << " : " << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

    assert(is_sorted(array));
}


int main() {

    vector<int> array = generate_random_int_array(100000, 0, 100000);
    
    test_sort("Quick Sort 3 Ways With Recursive", quick_sort, array);

    return 0;
}
