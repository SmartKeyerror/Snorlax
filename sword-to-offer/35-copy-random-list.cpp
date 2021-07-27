

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


/*
 * 拷贝带有随机指针的链表
 * 
 * Solution-1: 使用 hashmap 保存节点信息，两次遍历，时空复杂度均为 O(n)
 * Solution-2: 直接在原链表上进行拷贝操作，第一次遍历拷贝链表，得到 old-new-old-new-old-new 形式的链表，
 *             然后第二次遍历处理 random 指针。对于节点 u 来说，如果它的 random 指针不为空的话，那么就有
 *             u->next->random = u->random->next。时间复杂度 O(n)，空间复杂度 O(1)
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node *curret = head, *next = nullptr;

        // Node 的复制
        while (curret != nullptr) {
            next = curret->next;
            Node *node = new Node(curret->val);
            node->next = next;
            curret->next = node;
            curret = next;
        }

        // 处理 random 指针
        curret = head;
        while (curret != nullptr) {
            if (curret->random != nullptr) {
                curret->next->random = curret->random->next;
            }
            curret = curret->next->next;
        }

        // 处理合并后的链表
        curret = head;
        Node *newHead = curret->next;
        Node *newCur = newHead;

        while (curret != nullptr) {
            curret->next = newCur->next;
            curret = newCur->next;
            newCur->next = curret == nullptr ? nullptr : curret->next;
            newCur = curret == nullptr ? nullptr : curret->next;
        }

        return newHead;
    }
};