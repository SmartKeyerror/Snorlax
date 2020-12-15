
#include <string>
#include <unordered_map>

using namespace std;

/*
 * 映射建立问题
 * 
 * 我们能否使用 s 和 t 首先建立每一个字符的映射，然后遍历 s 尝试去恢复 t'，在比较 t' 和 t 是否相等?
 * 答案是不可以的，例如 s = "cd", t = "cc", 映射建立如下: 
 *  'c' => 'c'
 *  'd' => 'c'
 * 在遍历时我们仍然会得到正确的 t'，但是实际上他们并没有正确的映射，正确的映射应该是双向的。
 * 所以说，我们得有两个 hashmap，分别建立 s->t 的映射，以及 t->s 的映射，然后进行交叉对比
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> map1, map2;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];

            if (map1.count(c1) && map1[c1] != c2) return false;
            else map1[c1] = c2;

            if (map2.count(c2) && map2[c2] != c1) return false;
            else map2[c2] = c1;
        }
        return true;
    }
};
