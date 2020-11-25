

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 删除链表中节点值重复的所有元素，重复次数可能为 2 ，也可能为 n
 * 
 *  Input: 1->2->3->3->4->4->5
 *  Output: 1->2->5
 * 
 *  Input: 1->1->1->2->3
 *  Output: 2->3
 * 
 * 最简单的处理方式: 使用 set 保存链表节点值，遍历链表，删除节点值在集合中存在的节点，时间复杂度和空间复杂度均为 O(n)
 * 
 * dummy->1->1->1->2->3
 *  ↑     ↑  ↑
 * prev temp current
 * 
 * 另外一种方式就是使用三个指针完成，prev 指针指向当前已删除重复节点的末尾， temp 指针指向 prev->next，current指针则是当前需要处理的指针
 * 若 current->value == temp->val，current 指针继续前进，直到 current->value != temp->val，删除掉 temp 指针到 current指针之间的全部节点(前闭后开)
 * 然后执行 prev->next = current 即可。temp 指针指向 current， current 指针继续前进
 * 
 * Runtime: 8 ms, faster than 89.95% of C++ online submissions for Remove Duplicates from Sorted List II.
 * Memory Usage: 11.8 MB, less than 14.99% of C++ online submissions for Remove Duplicates from Sorted List II.
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr) return head;

        ListNode *dummy = new ListNode(0), *temp = head, *current = head->next, *prev = dummy;
        dummy->next = head;
        
        while (current != nullptr) {
            
            while (current != nullptr && current->val == temp->val)
                current = current->next;
            
            if (current == nullptr) {
                prev->next = current;
                break;
            }
            
            if (temp->next != current) {
                while (temp->val != current->val) {
                    ListNode *deletNode = temp;
                    temp = temp->next;
                    delete deletNode;
                }
                prev->next = current;
                current = current->next;
            } else {
                temp = current;
                current = current->next;
                prev = prev->next;
            }
        }

        ListNode *newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
