
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 旋转链表 k 次，每一次的旋转都将链表的最后一个元素旋转到头结点上
 * 
 *              1->2->3->4->5
 * rotate 1     5->1->2->3->4
 * rotate 2     4->5->1->2->3
 * 
 * 暴力解法: 循环 k 次，每次都从头到尾的找链表的尾节点，将尾节点挂上去, 时间复杂度为 O(nk)
 * 
 * 我们尝试着多 rotate 几次，看能不能找到什么规律，这个环形队列感觉非常类似
 * 
 *              1->2->3->4->5
 * rotate 1     5->1->2->3->4   将倒数第 1 个节点后的链表挂到链表头
 * rotate 2     4->5->1->2->3   将倒数第 2 个节点后的链表挂到链表头
 * rotate 3     3->4->5->1->2   将倒数第 3 个节点后的链表挂到链表头
 * rotate 4     2->3->4->5->1   将倒数第 4 个节点后的链表挂到链表头
 * rotate 5     1->2->3->4->5   k % 链表长度 == 0，我们什么都可以不用做
 * 
 * 所以，这是一个找到链表的倒数第 k 个节点的问题。
 * 
 * Runtime: 4 ms, faster than 98.89% of C++ online submissions for Rotate List.
 * Memory Usage: 12.3 MB, less than 7.20% of C++ online submissions for Rotate List.
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr) return head;

        // 确定链表长度以及尾节点
        int listSize = 0;
        ListNode *current = head, *tail = nullptr;
        while (current != nullptr) {
            tail = current;
            current = current->next;
            listSize ++;
        }
        
        int lastK = k % listSize;

        if (lastK == 0) 
            return head;
        
        // 找到链表的倒数第 k 个以及第 k-1 个节点，后者是为了断开原有链表连接而用
        ListNode *start = head, *end = head, *prev;
        for (int i = 0; i < lastK; i++) 
            end = end->next;
        while (end != nullptr) {
            prev = start;
            start = start->next;
            end = end->next;
        }
    
        if (prev != nullptr) prev->next = nullptr;

        tail->next = head;
        return start;
    }
};
