

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 

/*
 * 看，链表是逆序表示一个数字的，这和我们在 415. Add Strings 中做的事情一模一样
 * 
 * Constraints:
 *  The number of nodes in each linked list is in the range [1, 100].
 *  
 * 基于这样的条件我们完全可以将结果保存在额外的链表中，我个人不是很想破坏原链表的数据
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        ListNode *currentL1 = l1, *currentL2 = l2, *currentNode = nullptr;

        ListNode *dummyHead = new ListNode(0);
        ListNode *prevNode = dummyHead;

        while (currentL1 || currentL2) {
            int nbr1 = currentL1 == nullptr ? 0: currentL1->val;
            int nbr2 = currentL2 == nullptr ? 0: currentL2->val;

            int total = nbr1 + nbr2 + carry;
            int res = total % 10;
            carry = total / 10;

            currentNode = new ListNode(res);
            prevNode->next = currentNode; 
            prevNode = currentNode;

            if (currentL1) currentL1 = currentL1->next;
            if (currentL2) currentL2 = currentL2->next;
        }

        if (carry) {
            ListNode *tail = new ListNode(1);
            currentNode->next = tail;
        }
        return dummyHead->next;
    }
};
