// 232. Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/

#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> s;
    stack<int> reverse;

    MyQueue() = default;

    void push(int x)
    {
        while (!s.empty())
        {
            reverse.push(s.top());
            s.pop();
        }

        s.push(x);

        while (!reverse.empty())
        {
            s.push(reverse.top());
            reverse.pop();
        }
    }

    int pop()
    {
        int i = s.top();
        s.pop();
        return i;
    }

    int peek() { return s.top(); }

    bool empty() { return s.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */