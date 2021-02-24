#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 入度为 2 的那个节点就是相交节点。
 */
class Solution {
public:

    ListNode *mapSolution(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode *, int> freq;

        ListNode *current = headA;
        while (current != nullptr) {
            freq[current] ++;
            current = current->next;
        }

        current = headB;
        while (current != nullptr) {
            freq[current] ++;
            if (freq[current] == 2) return current;
            current = current->next;
        }
        return nullptr;
    }

    // Each value on each linked list is in the range [1, 10^9].
    // 题目中给出了这样的条件，所以说我们可以将 A 链表中的 value 取反，也就是乘以 -1。再遍历链表 B 时候遇到了负数的话，那么就说明这是一个相交节点
    void changeValue(ListNode *head) {
        while (head != nullptr) {
            head->val *= -1;
            head = head->next;
        }
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        changeValue(headA);

        ListNode *current = headB;
        while (current != nullptr) {
            if (current->val < 0) break;
            current = current->next;
        }

        changeValue(headA);
        return current;
    }
};