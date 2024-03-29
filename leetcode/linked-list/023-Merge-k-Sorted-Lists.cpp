
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 简单的分析一下，在 21.Merge Two Sorted Lists 中我们合并了两个有序的链表，但是这里是 k 个，我们也很难申请 k 个指针然后进行指针的滑动
 * 也就是说，单靠原有的链表结构，我们是无法合并这 k 个有序链表的，必须要借助辅助空间来完成。
 * 
 * 那么这个辅助空间应该用哪个数据结构? 数组? 队列还是栈? 如果把所有链表的元素丢到一个数组中，然后对其进行排序，再遍历输出的话，也能够得到结果
 * 
 * 另外的选择就是树结构了，如果我们构造一棵平衡二叉树，逐一地将链表中的元素添加进去，然后进行一个中序遍历，就能得到结果。
 * 不过，在进行中序遍历的同时，我们还要维护链表的连接性质。
 * 
 * 或者，使用堆结构，将链表元素逐一地 push 进一个最小堆，然后不断地进行 pop 操作，在维护链表连接性质的时候，我们只需要记录上一个 pop 出来的节点即可。
 * 
 * 总之，这些方案都能够得到结果，只是时间效率和实现难度有所不同而已，最简单的实现当然是使用堆实现。
 * 
 * Solution: 
 * 1. 将 vector<ListNode*> 中的所有 Node 一次性地压入到最小堆中，然后再逐一从中取出，时间复杂度 O(K * NlogN)，空间复杂度 O(KN)
 * 2. 另一种方式就是只使用大小为 K 的最小堆。初始化时将所有链表的 head 压入，然后 pop 出最小的那个最为新的 head。紧接着，将 poped->next 压入堆中
 */


struct heapCompare {
    bool operator() (ListNode * const node1, ListNode * const node2) {
        return node1->val > node2->val;
    }
};

class Solution {
private:
    ListNode* mergeKListsUseHeap(vector<ListNode*> &lists) {
        if (lists.size() == 0)
            return nullptr;
        
        priority_queue<ListNode *, vector<ListNode *>, heapCompare> heap;

        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy, *current;

        for (const auto head : lists) {
            if (head != nullptr) {
                heap.push(head);
            }
        }

        while (!heap.empty()) {
            current = heap.top();
            heap.pop();

            prev->next = current;
            prev = current;

            if (current->next != nullptr) {
                heap.push(current->next);
            }
        }

        ListNode *result = dummy->next;
        delete dummy;
        
        return result;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsUseHeap(lists);
    }
};
