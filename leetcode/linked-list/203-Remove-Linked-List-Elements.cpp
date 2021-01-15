

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy, *current = head;

        while (current) {
            if (current->val == val) {
                pre->next = current->next;
                ListNode *deleted = current;
                current = current->next;
                
                deleted->next = nullptr;
                delete deleted;
            }
            else {
                current = current->next;
                pre = pre->next;
            }
        }
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};