
#include <vector>

using namespace std;

/*
 * ADT 设计类问题，要求设计一个最小栈，除了栈最基本的操作以外，还需要有一个 getMin 操作，返回栈中的最小值
 * 
 * 这里仍然使用 vector 作为栈实现，链表实现稍微复杂一些。压栈时在尾部压入，弹出时在尾部弹出即可。
 * 
 * 现在来看 getMin 该怎么实现。如果需要在 O(1) 的时间内实现的话，额外空间是少不了的，并且额外空间的元素需要和原有栈同步更新
 * 
 * 假设我们的主栈叫做 A,辅助栈叫做 B，辅助栈中保存的是栈 A 元素的 vector 下标，也就是 0、1、2这样的。下标的好处在于更加通用，对于引用对象也可使用
 * 那么当栈 A 为空时，元素除了压入栈 A,索引还得压入栈 B，以此作为当前栈的最小元素。当继续向栈 A push 元素时，将该元素和栈 B 的栈顶元素进行比较
 * 若小于 B.top()，那么说明有了更小的元素，直接压入栈 B。若大于 B.top()，直接忽略即可。
 * 
 * 栈 A 弹出元素时，判断一下弹出的元素是不是栈 B 的栈顶元素，若是则一并弹出。
 */
class MinStack {
private:
    vector<int> stack;
    vector<int> support;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        stack.push_back(x);
        if (support.empty() || x < stack[support.back()])
            support.push_back(stack.size() - 1);
    }
    
    void pop() {
        int topValue = stack.back();
        if (support.back() == stack.size() - 1)
            support.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return stack[support.back()];
    }
};
