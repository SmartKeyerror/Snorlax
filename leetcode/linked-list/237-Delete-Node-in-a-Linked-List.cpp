
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * 给定一个链表节点，并删除该节点，链表头节点未给出。
 * 
 * 由于链表头结点未给出，所以只能调整节点的值实现，并且需要保证链表的有序性，所以只能一个一个节点的进行数据“迁移”
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *current = node, *tail = nullptr;
        while (current->next != nullptr) {
            tail = current;
            ListNode *next = current->next;
            current->val = next->val;
            current = current->next;
        }
        tail->next = nullptr;
    }
};
