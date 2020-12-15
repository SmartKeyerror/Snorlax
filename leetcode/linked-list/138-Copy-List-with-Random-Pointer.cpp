
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
