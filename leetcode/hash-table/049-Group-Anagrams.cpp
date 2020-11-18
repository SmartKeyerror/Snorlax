
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


// todo: 迟早我要写一个关于 Anagrams 的专栏......

/*
 * eat, tea, 属于同一组，因为组成的字母相同。我们用一个更生动的比喻来描述: 配料表，它们的配料表相同，所以在同一组
 * 那么如何确定它们的配料表相同? 一种方法是将配料表拆开形成一个 list, 然后对这个 list 进行哈希，可惜 list 不能作为 hash key
 * 另外一个方式就是排序，结果仍为字符串，可以进行 hash
 */ 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> hashmap;

        for (int i = 0; i < strs.size(); i++) {
            string s {strs[i]};
            sort(s.begin(), s.end());
            hashmap[s].push_back(strs[i]);      // 同样地，利用 C++ 哈希表的特性直接进行操作，Python 使用 defaultdict
        }

        vector<vector<string>> result;
        
        // 输出 value 值即可 (顺带 Google 了一波 unordered_ma 的遍历方式，这比迭代器看起来舒服多了)
        for (auto &item: hashmap)
            result.push_back(item.second);

        return result;
    }
};
