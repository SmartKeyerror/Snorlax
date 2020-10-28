
#include <stddef.h>

struct ListNode {
      int val;
     struct ListNode *next;
};

/*
 * 寻找链表的中间节点，快慢指针解决
 * https://leetcode.com/problems/middle-of-the-linked-list/
 */
struct ListNode *middleNode(struct ListNode *head) {
    struct ListNode *slow, *fast;
    slow = fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

/*
 * 删除单向链表的倒数第 K 个节点，双指针解决
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n){
    struct ListNode *begin, *finish, *temp;
    begin = finish = temp = head;

    for (int i = 0; i < n; i++) {
        if (finish == NULL)
            return NULL;
        finish = finish->next;
    }

    while (finish != NULL) {
        temp = begin;
        begin = begin->next;
        finish = finish->next;
    }

    if (begin == head) {
        return begin->next;
    }

    temp->next = begin->next;
    begin->next = NULL;
    return head;
}