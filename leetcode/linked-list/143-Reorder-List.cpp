#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
 * 对链表进行重排
 * 
 * L0 → L1 → … → Ln - 1 → Ln
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 
 * 相当于将整个链表打散，然后把链表的后面 n/2 个节点，隔一个挂在前面儿的节点中
 * 
 * 比如 1 -> 2 -> 3 -> 4 -> 5，一共 5 个节点，5/2 = 2，因此我们取下 4, 5 这两个节点，从后往前将其插到 1 -> 2 -> 3 这个链表里面
 * 
 * 既然是隔一个插一个，那么 current 指针需要略过头结点，来到节点 2，在节点 2 的前面插入节点 5，也就是 1 -> 5 -> 2 -> 3
 * 
 * current 指针继续前进，达到节点 3，然后在节点 3 的前面插入节点 4，也就是 1 -> 5 -> 2 -> 4 -> 3，和 Example 的结果一致
 * 
 * Stack Solution: Runtime: 92 ms, faster than 6.23% of C++ online submissions for Reorder List. 我人傻了
 * 
 * 用栈确实能解决这个问题，但是效率也忒低了吧......
 * 
 * 如果我们找到了链表的中间节点呢? 从中间节点开始，1 -> 2 -> 3 -> 4 -> 5，也就是从节点 3 开始，节点 4 应该挂在节点 2 后面，节点 5 应该挂在节点 1 后面
 * 
 * 但是原有的链表顺序并不能满足这样的要求，应该先处理节点 5，然后再处理节点 4。reverse 从 middle 到 tail 的所有链表节点，使其变成 1 -> 2 -> 3 -> 5 -> 4
 * 
 * 这个时候就可以进行处理了。也就是说，这道题目中 O(1) 空间复杂度的解法涉及到链表的 3 个问题: 1. 寻找链表的中间节点  2.从 m 到 n 反转链表  3. reorder linked list
 * 
 */
class Solution {
private:
    void stackSolution(ListNode* head) {
        stack<ListNode *> st;
        ListNode *cur = head;
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->next;
        }

        // 我们需要从栈中取出 n/2 个节点出来进行处理
        ListNode *prev = head, *current = head->next;
        int n = st.size();

        for (int i = 0; i < n/2; i++) {
            ListNode *pop_node = st.top();
            st.pop();

            prev->next = pop_node;
            pop_node->next = current;

            prev = current;
            current = current->next;
        }
        prev->next = nullptr;
    }

    void reverseSolution(ListNode* head) {
        // 1. 快慢指针寻找链表中间节点
        // QA: 为什么快慢指针可以找到链表中点？ 因为快指针走到链表末尾时，慢指针所走过的路径长度是其 1/2，而链表的中点不就是所有链表节点的 1/2 吗?
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *middle = slow;

        // 2. 反转 middle 后面所有的节点
        ListNode *prev = middle, *current = middle->next, *next = nullptr;
        middle->next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // 3. 得到了 1 -> 2 -> 3 <- 4 <- 5, 此时 prev 指针指向节点 5，然后 order 即可
        current = head;
        while (current) {
            next = current->next;
            current->next = prev;
            current = prev;
            prev = next;
        }
    }
public:
    void reorderList(ListNode* head) {

        // Stack Solution: Runtime: 92 ms, faster than 6.23% of C++ online submissions for Reorder List.
        // stackSolution(head);

        // Runtime: 60 ms, faster than 8.70% of C++ online submissions for Reorder List. 喵喵喵???
        reverseSolution(head);
    }
};