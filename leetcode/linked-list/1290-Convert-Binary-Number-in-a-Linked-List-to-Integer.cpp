
#include <vector>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> digits;
        ListNode *current = head;
        while (current) {
            digits.push_back(current->val);
            current = current->next;
        }

        int res = 0, bit = digits.size();
        for (int i = 0; i < bit; i++)
            res += digits[i] * pow(2, bit - i - 1);
        
        return res;
    }
};
