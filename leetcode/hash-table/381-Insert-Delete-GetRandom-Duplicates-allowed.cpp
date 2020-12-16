
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <ctime>

using namespace std;


/*
 * 整体思路与 380 号问题一样，但是现在由于允许重复元素的存在，所以我们的 hashmap 中的 value 不再保存单一的元素索引，而是由相同元素所对应索引组成的列表。
 * 
 * vector: [1, 1, 2, 3, 4]
 * map: {
 *     1: [0, 1],
 *     2: [2],
 *     3: [3],
 *     4: [4]
 * }
 */
class RandomizedCollection {
private:
    vector<int> record;
    unordered_map<int, unordered_set<int>> map;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = true;

        if (map.count(val) != 0)
            flag = false;

        record.push_back(val);
        map[val].insert(record.size() - 1);
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (map.count(val) == 0)
            return false;
        
        int index = *(map[val].begin());        // 取第一个元素进行删除
        map[val].erase(map[val].begin());

        int last = record.back();

        record[index] = last;
        map[last].insert(index);
        map[last].erase(record.size() - 1);
        record.pop_back();

        if (map[val].size() == 0)
            map.erase(val);

        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return record[rand()%record.size()];
    }
};
