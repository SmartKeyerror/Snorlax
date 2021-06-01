
/*
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 * 
 * 输入：head = [1,3,2]
 * 输出：[2,3,1]
 * 
 * 方法很多:
 *  - 递归实现，相当于二叉树的后序遍历，时间、空间复杂度均为 O(n)，但是函数调用栈可能受不了
 *  - 顺序放入结果集，然后再 reverse 结果集，时间复杂度 O(n)，空间复杂度 O(1)
 *  - 或者我们也可以“自找麻烦”，把链表 reverse，然后再顺序遍历放入结果集，时间复杂度 O(n)，空间复杂度 O(1)
 * 
 */

#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    vector<int> reverseVectorSolution(ListNode* head) {
        vector<int> result;

        ListNode *current = head;

        while (current != nullptr) {
            result.push_back(current->val);
            current = current->next;
        }

        reverse(result.begin(), result.end());

        return result;
    }

    vector<int> recursiveSolition(ListNode* head) {
        if (head == nullptr) return {};
        auto res = recursiveSolition(head->next);
        res.push_back(head->val);
        return res;
    }
public:
    vector<int> reversePrint(ListNode* head) {
       return reverseVectorSolution(head);
       return recursiveSolition(head);
    }
};