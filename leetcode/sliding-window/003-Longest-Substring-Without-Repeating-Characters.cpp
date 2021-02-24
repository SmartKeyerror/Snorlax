
#include <limits.h>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) return 0;

    unordered_set<char> visited;

    int result = 0;
    int left = 0, right = -1;

    while (left <= s.size() - 1) {
      if (right + 1 < s.size() && visited.count(s[right + 1]) == 0)
        visited.insert(s[++right]);
      else
        visited.erase(s[left++]);

      result = max(result, right - left + 1);
    }
    return result;
  }
};
