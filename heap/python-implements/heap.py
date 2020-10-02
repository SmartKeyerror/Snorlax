
import random
from enum import Enum
from copy import deepcopy
from abc import ABCMeta, abstractmethod


class HeapType(Enum):
    MAX = 1
    MIN = 2


class Operator(metaclass=ABCMeta):
    @abstractmethod
    def operate(self, left, right):
        pass


class MaxHeapOperator(Operator):
    def operate(self, left, right):
        # 对于大堆而言, 位于数组左侧的元素通常（但不一定）要大于右侧
        return left > right


class MinHeapOperator(Operator):
    def operate(self, left, right):
        # 对于小堆而言, 位于数组左侧的元素通常（但不一定）要小于右侧
        return left < right


class Heap(object):
    def __init__(self, data=None, heap_type=HeapType.MAX):

        """
        :param data: 初始化的元素数组
        :param heap_type: 堆类型, HeapType.MAX 大堆, HeapType.MIN 位小堆, 默认为大堆
        """

        assert heap_type in [HeapType.MAX, HeapType.MIN]

        self._operate = MaxHeapOperator().operate if heap_type == HeapType.MAX else MinHeapOperator().operate

        if data:
            self._data = deepcopy(data)
            self._heapify()
        else:
            self._data = []

    def is_empty(self):
        return True if not self._data else False

    def push(self, value):
        self._data.append(value)
        self._shift_up(len(self._data) -1)

    def pop(self):
        if self.is_empty():
            raise ValueError("the heap is empty")

        self.swap(0, len(self._data) - 1)
        max_item = self._data.pop()

        self._shift_down(0)

        return max_item

    @classmethod
    def _get_parent(cls, index):
        return (index - 1) // 2

    @classmethod
    def _get_left(cls, index):
        return 2 * index + 1

    @classmethod
    def _get_right(cls, index):
        return 2 * index + 2

    def swap(self, src: int, dst: int):
        self._data[src], self._data[dst] = self._data[dst], self._data[src]

    def _shift_up(self, index) -> None:
        while index > 0 and self._operate(self._data[index], self._data[self._get_parent(index)]):
            self.swap(index, self._get_parent(index))
            index = self._get_parent(index)

    def _shift_down(self, index) -> None:

        # 实际上只需要下沉到最后一个非叶子节点即可
        while self._get_left(index) < len(self._data):

            # 暂定左子节点为最大节点
            max_index = self._get_left(index)

            # 此处需判断是否存在右子节点
            if max_index + 1 < len(self._data) and self._operate(self._data[max_index + 1], self._data[max_index]):
                max_index += 1

            if self._operate(self._data[index], self._data[max_index]):
                break

            self.swap(max_index, index)

            index = max_index

    def _heapify(self) -> None:

        non_leaf = self._get_parent(len(self._data) - 1)

        while non_leaf >= 0:
            self._shift_down(non_leaf)
            non_leaf -= 1


if __name__ == "__main__":
    random_list = [random.randint(0, 10000) for _ in range(100)]

    heap = Heap(random_list, HeapType.MIN)

    should_sorted_result = []

    while not heap.is_empty():
        item = heap.pop()
        should_sorted_result.append(item)

    # 这里直接使用 sort 函数对其排序进行判断了
    sorted_list = sorted(random_list)

    assert sorted_list == should_sorted_result
