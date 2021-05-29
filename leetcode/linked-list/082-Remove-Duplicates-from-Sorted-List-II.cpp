

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

        // 创建 dummy head
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *temp = head, *current = head->next, *prev = dummy;
        
        while (current != nullptr) {
            
            // 寻找到与 temp 不相等的节点，也就是 prev 指针需要指向的下一个节点
            while (current != nullptr && current->val == temp->val)
                current = current->next;
            
            // case 1: 整个链表重复，那么此时直接让 prev->next 指向 current 即可
            if (current == nullptr) {
                prev->next = current;
                break;
            }
            
            // 此时我们需要判断是不是要删除 temp 到 current 之间的链表节点
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
