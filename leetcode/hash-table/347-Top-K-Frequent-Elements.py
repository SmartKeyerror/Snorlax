from collections import Counter


# 就...怎么说呢, 这玩意儿用 Python 标准库是真的很爽
class Solution(object):
    def topKFrequent(self, nums, k):
        return [i for i, _ in Counter(nums).most_common(k)]
