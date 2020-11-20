
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 相当直接的一道题目，但是也的确是一个好题目，考察队归并排序中归并过程的理解
 * 对于数组的归并过程，我们需要一个额外的辅助数组来帮助我们存储和搬移数据，但是对于链表而言，我们只需要改变 next 指针就好了，非常 Nice
 * 
 * 1, 3, 4, 7      6, 8, 10, 12
 * ↑               ↑
 * i               j
 * 
 * 如果 i < j，将 i 指向的节点挂接到已有链表上，而后 i 向右移动；如果 i > j，将 j 指向的节点挂接到已有链表上，而后 j 向右移动
 * 
 * 解决完这个问题，可以尝试一下解决 148. Sort List 这个问题，可以直接将这道问题的代码原封不动的拷贝到该题中。
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return nullptr;
        
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;

        // left 表示在 l1 链表中滑动的指针， right 表示在 l2 链表中滑动的指针
        ListNode *left = l1, *right = l2;

        while (left || right) {
            if (left && right) {
                if (left->val < right->val) {
                    prev->next = left;
                    left = left->next;
                }
                else {
                    prev->next = right;
                    right = right->next;
                }
                prev = prev->next;
            }
            else if (left) {
                prev->next = left;
                break;
            }
            else {
                prev->next = right;
                break;
            }
        }

        // 清理掉多余的内存是一个必须养成的习惯
        ListNode *head = dummy->next;
        delete dummy;

        return head;
    }
};