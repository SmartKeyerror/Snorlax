
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


/*
 * 对一个带有 random 指针的链表进行 deep copy，返回新的链表的头结点。因为 random 指针可能随意的乱指，所以我们必须要能够唯一的确定链表中的一个节点
 * 
 * 我们可以维护这样的一个映射: oldNode -> newNode
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;

        unordered_map<Node *, Node *> record;

        Node *current = head;

        // 建立新老映射
        while (current != nullptr) {
            record[current] = new Node(current->val);
            current = current->next;
        }

        current = head;

        while (current != nullptr) {
            record[current]->next = record[current->next];
            record[current]->random = record[current->random];
            current = current->next;
        }

        return record[head];
    }
};


/*
 * 上述方法的空间复杂度为 O(N)，官方提供了一个空间复杂度为 O(1) 的解法，思路很巧妙
 * 
 * 我们首先复制以 next 指针指向的基础节点，将新节点挂在老节点的后面，也就是 旧->新->旧->新->旧->新
 * 
 * 然后我们再去处理 random 指针，对于当前新节点来说，我们假设其名称为 A'，其旧节点为 A。
 * 
 * 如果 A 的 random 节点为 B 的话，那么 A' 的 random 节点就是 B 的下一个节点，也就是 B' 节点。
 * 
 * 最后，我们再将这个链表拆成两份，一份旧链表，一份新链表，返回新链表即可。
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node *current = head;

        // 形成 旧-新-旧-新 链表
        while (current != nullptr) {
            Node *cloned = new Node(current->val);
            cloned->next = current->next;
            current->next = cloned;
            current = cloned->next;
        }

        // 处理 random 节点
        current = head;
        while (current != nullptr) {
            Node *cloned = current->next;
            if (current->random != nullptr) {
                cloned->random = current->random->next;
            }
            current = cloned->next;
        }

        // 拆分链表
        Node *oldHead = head, *newHead = head->next;
        Node *oldCurrent = oldHead, *newCurrent = newHead;

        while (oldCurrent != nullptr) {
            oldCurrent->next = newCurrent->next;

            // newCurrent->next 可能为空，需要注意
            newCurrent->next = newCurrent->next == nullptr ? nullptr : newCurrent->next->next;

            oldCurrent = oldCurrent->next;
            newCurrent = newCurrent->next;
        }
        return newHead;
    }
};