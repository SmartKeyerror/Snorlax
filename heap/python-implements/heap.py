import random
from copy import deepcopy


class Heap(object):
    def __init__(self, data=None):

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
        while index > 0 and self._data[index] > self._data[self._get_parent(index)]:
            self.swap(index, self._get_parent(index))
            index = self._get_parent(index)

    def _shift_down(self, index) -> None:

        # 实际上只需要下沉到最后一个非叶子节点即可
        while self._get_left(index) < len(self._data):

            # 暂定左子节点为最大节点
            max_index = self._get_left(index)

            # 此处需判断是否存在右子节点
            if max_index + 1 < len(self._data) and self._data[max_index] < self._data[max_index + 1]:
                max_index += 1

            if self._data[max_index] < self._data[index]:
                break

            self.swap(max_index, index)

            index = max_index

    def _heapify(self) -> None:

        non_leaf = self._get_parent(len(self._data) - 1)

        while non_leaf >= 0:
            self._shift_down(non_leaf)
            non_leaf -= 1


if __name__ == "__main__":
    random_list = [random.randint(0, 10000) for _ in range(10)]

    heap = Heap(random_list)

    should_sorted_result = []

    while not heap.is_empty():
        item = heap.pop()
        should_sorted_result.append(item)

    # 这里直接使用 sort 函数对其排序进行判断了
    sorted_list = sorted(random_list, reverse=True)

    assert sorted_list == should_sorted_result
