
#include <unordered_map>
#include <random>
#include <ctime>

using namespace std;

/*
 * 挺有意思的一道题目，有意思的是 getRandom 这个 API，需要随机的返回一个 RandomizedSet 中的 value ,并且以 O(1) 的方式返回
 * 
 * 众所周知，不管是 RBTree 还是 hashmap 所实现的集合，都不会提供 random 这样的操作，因为一个是树结构，一个是带有缺省值的动态数组结构，除非
 * 我们遍历整个集合，否则很难在原有的集合基础之上做这件事情。
 * 
 * vector 的 random 操作是最方便的，通过下标查找的效率为 O(1), 删除的话因为不需要维护顺序，也可以在 O(1) 的时间内完成
 * 所以，我们需要一个 hashmap 和一个 vector，其中 hahsmap 存贮着 vector 的 value: index 映射
 */
class RandomizedSet {
private:
    unordered_map<int, int> map;
    vector<int> record;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // 在插入数据时，我们将 val 丢到 record 的末尾，然后在 map 中更新一下 value: index 即可
        if (map.count(val) == 0) {
            record.push_back(val);
            map[val] = record.size() - 1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (map.count(val) == 0)
            return false;
        
        int index = map[val];

        if (record.size() != 1) {
            // 更新 map
            map[record.back()] = index;
            // 更新 record, O(1) 时间复杂度删除索引为 index 的元素，和最后一个元素交换一下位置即可
            record[index] = record.back();
        }

        map.erase(val);
        record.pop_back();

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return record[rand()%record.size()];
    }
};