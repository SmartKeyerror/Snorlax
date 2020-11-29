
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 给定一个链表，判断其是否存在环节点，若存在，返回环节点，否则返回 NULL
 * 
 x        a            y    b   z
 +---------------------X--------X--------+
                       |                 |
                       |                 |
                       |                 |
                       |                 |
                       +-----------------+
                                   c

 * 假设链表头结点为 x，环节点为 y，相遇节点为 z，x->y 路径为 a，y->z 路径为 b，z->y 路径为 c
 * 那么有 slow = a + b, fast = a + b + c + b，并且，fast 指针所走过的路径是 slow 指针所走过的两倍，即 2(a+b) = a + b + c + b，可得 a = c
 * 那么问题就简单了，当快慢指针相遇时，slow 指针向前走，同时另外一个指针从头结点开始走，两指针相遇的节点就是环节点。
 * 
 * 有位老哥对链表环节点、环的长度等问题做了很好的总结: https://www.cnblogs.com/hiddenfox/p/3408931.html
 * 
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr; 

        ListNode *slow = head, *fast = head, *cycle = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (!fast || !fast->next) return nullptr;

        while (cycle) {
            if (cycle == slow) return cycle;
            cycle = cycle->next;
            slow = slow->next;
        }
        return nullptr;
    }
};