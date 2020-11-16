

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 平均时间复杂度为 O(nlogn) 的算法没几个，快速排序、归并排序，堆排序勉强算是一个 O(nlogn) 的排序算法，但是它需要开辟额外的空间，以及速度比前两者都要差一些
 * 这里使用归并排序解决，快排理论上来说也能够解决，只不过受限于链表的特性，只能两路快排
 * 
 * Runtime: 148 ms, faster than 14.87% of C++ online submissions for Sort List.
 * Memory Usage: 50.3 MB, less than 5.99% of C++ online submissions for Sort List.
 * 
 * 这不科学(哦不，这不神秘学)，我严重怀疑有“禽兽”开了额外的数组来实现
 */
class Solution {

private:

    ListNode *find_mid(ListNode *head) {
        // 快慢指针找中点
        ListNode *slow, *fast, *prev;

        slow = fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        // 断开链表(这里尽量不使用 slow->next 来断开链表，不过也没差)
        prev->next = nullptr;
        return slow;
    }
    
    ListNode *mergeList(ListNode *left, ListNode *right) {

        ListNode *dummy, *current = new ListNode();
        dummy = current;

        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        if (left != nullptr)
            current->next = left;
        
        if (right != nullptr)
            current->next = right;
        
        return dummy->next;
    }


    ListNode *mergeSort(ListNode *head) {

        if (head == nullptr || head->next == nullptr) 
            return head;

        ListNode *mid = find_mid(head);

        ListNode *left = mergeSort(head);
        ListNode *right = mergeSort(mid);

        return mergeList(left, right);
    }


public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
