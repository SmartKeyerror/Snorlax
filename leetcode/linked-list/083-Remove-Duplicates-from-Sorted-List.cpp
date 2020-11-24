
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *current = head;

        while (current && current->next) {
            if (current->val == current->next->val) {
                ListNode *deleteNode = current->next;
                current->next = deleteNode->next;
                delete deleteNode;
            } else
                current = current->next;
        }
        return head;
    }
};
