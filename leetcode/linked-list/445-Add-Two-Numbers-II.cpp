
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 如果要求 l1 和 l2 允许被修改，也就是不允许被 reverse 的话，我们可以用一个栈来保存 l1 和 l2 中的节点。
 */
class Solution {
private:
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode *newHead = reverseLinkedList(head->next);

        ListNode *node = head->next;
        node->next = head;
        head->next = nullptr;

        return newHead;
    } 
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLinkedList(l1), l2 = reverseLinkedList(l2);

        int carry = 0;
        ListNode *dummyHead = new ListNode(0);
        ListNode *current = dummyHead;

        while (l1 != nullptr || l2 != nullptr || carry) {

            if (l1 != nullptr) {
                carry += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                carry += l2->val;
                l2 = l2->next;
            }

            current->next = new ListNode(carry % 10);
            carry = carry / 10;
            current = current->next;
        }

        ListNode *res = reverseLinkedList(dummyHead->next);
        delete dummyHead;

        return res;
    }
};