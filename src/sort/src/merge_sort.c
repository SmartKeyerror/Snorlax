
#include <stdlib.h>
#include <stdio.h>
#include "sort.h"



void __merge(elementType list[], int left, int mid, int right, bool (*compare)(elementType a, elementType b)) {

    elementType auxiliary[right-left+1];

    // 我们需要做的事情是将辅助数组中的元素逐一地放置在原数组中，所以辅助数组的初始数据必须和原子数组相同
    for (int i = left; i <= right; i++) {
        auxiliary[i-left] = list[i];
    }

    // 现在我们就可以初始化归并过程中的3个指针了，分别为 i, j, k
    int i = left, j = mid + 1;

    // 一定要注意: 我们是将 auxiliary 的数值写入到 list 数组中
    for (int k = left; k <= right; k++) {

        if (i > mid) {
            list[k] = auxiliary[j-left];
            j++;
        }

        else if (j > right){
            list[k] = auxiliary[i-left];
            i++;
        }

        else if (compare(auxiliary[i-left], auxiliary[j-left])) {  // 有一个偏移量
            list[k] = auxiliary[i-left];                
            i ++;
        } else {
            list[k] = auxiliary[j-left];
            j++;
        }
    }

}


// 使用归并排序，对 [left...right] 的范围进行排序
void __merge_sort(elementType list[], int left, int right, bool (*compare)(elementType a, elementType b)) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    __merge_sort(list, left, mid, compare);          // 对左半部分进行归并排序
    __merge_sort(list, mid + 1, right, compare);     // 对右半部分进行归并排序

    // 左、右部分归并排序以后产生了两个有序的子序列，将有序的子序列合并即可

    // 此时无需进行合并
    if (compare(list[mid], list[mid + 1]))
        return;
    
    // 归并左右两个子序列
    __merge(list, left, mid, right, compare);

    return;
}


void merge_sort(elementType list[], size_t length, bool (*compare)(elementType a, elementType b)) {
    __merge_sort(list, 0, length - 1, compare);
}


// int main() {
//     elementType list[] = {10, 15, 22, 88, 70, 90, 100, 5, 9, 45, 30, 22};
//     size_t length = sizeof(list) / sizeof(elementType);

//     merge_sort(list, length, more);

//     for (size_t i = 0; i < length; i++) {
//         printf("%d ", list[i]);
//     }
// }