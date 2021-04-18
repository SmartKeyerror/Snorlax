
#include <cmath>
#include <iostream>

using namespace std;


/*
 * 给定链表 A、B，求解这两个链表的交点。它们可能相交，也可能不相交，并且 A、B 链表可能有环，也可能无环。
 * 若交点不存在，返回 nullptr 即可。
 * 
 * 挺有意思的一道题目，原理示意图可参考 https://github.com/SmartKeyerror/Snorlax#intersection-of-two-linked-list
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 判断以 head 为头结点的链表是否有环，若有环，则返回其环节点，否则返回 nullptr
ListNode *detect_cycle(ListNode *head) {
    if (head == nullptr) return head;

    ListNode *slow = head, *fast = head;

    while (fast && fast->next ) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (!fast || !fast->next) return nullptr;

    ListNode *anchor = head;

    while (anchor != slow) {
        anchor = anchor->next;
        slow = slow->next;
    }

    return anchor;
}


// 获取链表长度
int get_length(ListNode *head) {
    if (!head) return 0;

    int length = 0;
    ListNode *current = head;
    while (current) {
        length ++;
        current = current->next;
    }
    return length;
}


// 求解无环链表 A、B 链表的交点
ListNode *intersection_of_no_cycle_linked_list(ListNode *headA, ListNode *headB) {

    int lengthA = get_length(headA);
    int lengthB = get_length(headB);

    ListNode *anchor1, *anchor2;

    if (lengthA >= lengthB) {
        anchor1 = headA;
        anchor2 = headB;
    }
    else {
        anchor1 = headB;
        anchor2 = headA;
    }

    int diff = abs(lengthA - lengthB), remain = min(lengthA, lengthB);

    for (int i = 0; i < diff; i++) anchor1 = anchor1->next;

    for (int i = 0; i < remain; i++) {
        if (anchor1 == anchor2) return anchor1;
        anchor1 = anchor1->next;
        anchor2 = anchor2->next;
    }

    return nullptr;
}


// 求解有环链表 A、B 的交点
ListNode *intersection_of_cycle_linked_list(ListNode *headA, ListNode *cycleA, ListNode *headB, ListNode *cycleB) {
    ListNode *anchor1 = nullptr, *anchor2 = nullptr;

    if (cycleA == cycleB) {
        anchor1 = headA, anchor2 = headB;

        // 求 headA 到 cycleA 的长度，以及 headB 到 cycleB 的长度
        int lenA = 0, lenB = 0;

        while (anchor1 != cycleA) {
            lenA ++;
            anchor1 = anchor1->next;
        }

        while (anchor2 != cycleB) {
            lenB ++;
            anchor2 = anchor2->next;
        }

        if (lenA >= lenB) {
            anchor1 = headA;
            anchor2 = headB;
        }
        else {
            anchor1 = headB;
            anchor2 = headA;
        }

        int diff = abs(lenA - lenB), remain = min(lenA, lenB);

        for (int i = 0; i < diff; i++) anchor1 = anchor1->next;

        for (int i = 0; i < remain; i++) {
            anchor1 = anchor1->next;
            anchor2 = anchor2->next;
        }

        for (int i = 0; i < diff; i++) anchor1 = anchor1->next;

        for (int i = 0; i < remain; i++) {
            if (anchor1 == anchor2) return anchor1;
            anchor1 = anchor1->next;
            anchor2 = anchor2->next;
        }
        return nullptr;
    }

    else {
        anchor1 = cycleA->next;
        while (anchor1 != cycleA) {
            if (anchor1 == cycleB) return cycleB;
            anchor1 = anchor1->next;
        }
        return nullptr;
    }
}


// 求解 A、B 链表的交点
ListNode *intersection_of_linked_list(ListNode *headA, ListNode *headB) {
    if (!headA && !headB || !(headA && headB)) return nullptr;

    // 首先，判断 A、B 是否有环
    ListNode *cycleA = detect_cycle(headA);
    ListNode *cycleB = detect_cycle(headB);

    if (cycleA == nullptr && cycleB == nullptr)
        return intersection_of_no_cycle_linked_list(headA, headB);
    
    else if (cycleA != nullptr && cycleB != nullptr)
        return intersection_of_cycle_linked_list(headA, cycleA, headB, cycleB);

    return nullptr;
}

