
#include <vector>
#include <stack>

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
    vector<int> nextLargerNodes(ListNode* head) {

        int count = 0;
        ListNode *current = head;
        while (current != nullptr) {
            current = current->next;
            count ++;
        }

        vector<int> result(count, 0);
        stack<pair<int, int>> incStack;

        current = head;
        int index = 0;
        while (current != nullptr) {
            while (!incStack.empty() && current->val > incStack.top().second) {
                result[incStack.top().first] = current->val;
                incStack.pop();
            }
            incStack.push({index, current->val});

            current = current->next, index ++;
        }
        return result;
    }
};