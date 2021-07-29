
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
 * 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 返回同样按升序排列的结果链表。
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *current = head, *prev = dummy;

        while (current != nullptr && current->next != nullptr) {
            // 发现了重复元素
            int curValue = current->val;
            if (current->val == current->next->val) {
                while (current != nullptr && current->val == curValue) {
                    ListNode *next = current->next;
                    current->next = nullptr;
                    delete current;
                    current = next;
                }
                prev->next = current;
            } else {
                prev = current;
                current = current->next;
            }
        }
        ListNode *newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};