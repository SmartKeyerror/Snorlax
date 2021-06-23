
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
 * K 个一组反转链表，末尾不足 K 个的不进行反转
 * 
 * Input: 1->2->3->4->5->6->7->8->9->10->11, k = 3
 * Output: 3->2->1->6->5->4->9->8->7->10->11
 * 
 * 如果使用额外空间的话，那么这道题就会变得比较容易了，O(1) 额外空间的解法相对要复杂一些。
 * 
 * 从 Example 可以看到，链表的 head 节点可能会发生改变，因此我们使用 DummyHead 来进行固定
 * 
 * 使用栈来完成翻转的过程，遍历链表，将节点入栈，当栈大小为 k 时，开始进行处理
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        // 添加哑元节点
        auto dummyNode = new ListNode();
        dummyNode->next = head;

        ListNode *current = head, *tail = dummyNode;
        stack<ListNode *> st;

        while (current != nullptr || st.size() == k) {

            // 装填 K 个节点到栈中
            if (st.size() < k) {
                st.push(current);
                current = current->next;
                continue;
            }

            // 此时栈大小为 K，开始进行处理，也就是 reverse 的过程
            for (int i = 0; i < k; i++) {
                ListNode *node = st.top();
                st.pop();

                tail->next = node;
                tail = node;
            }
        }

        tail->next = nullptr;

        // 处理栈中剩余的不足 K 个节点
        while (!st.empty()) {
            ListNode *node = st.top();
            st.pop();

            // 插入到 tail 后面
            node->next = tail->next;
            tail->next = node;
        }

        head = dummyNode->next;
        delete dummyNode;

        return head;
    }
};