// 225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/

#include <queue>
using namespace std;

// Solution 1 - O(n) push, O(1) pop, O(1) top
class MyStack
{
public:
    queue<int> q;

    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        int n = q.size() - 1;
        for (int i = 0; i < n; i++)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }

        int top = q.front();

        q.pop();

        return top;
    }

    int top()
    {
        int n = q.size() - 1;
        for (int i = 0; i < n; i++)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }

        int top = q.front();

        q.pop();
        q.push(top);

        return top;
    }

    bool empty()
    {
        return q.empty();
    }
};

// Solution 2 - O(1) push, O(n) pop, O(n) top
class MyStack
{
public:
    queue<int> q;

    MyStack()
    {
    }

    // Ex:
    // stack: 1, 2, 3
    // add 4
    // queue = 3, 2, 1, 4
    // queue = 2, 1, 4, 3
    // queue = 1, 4, 3, 2
    // queue = 4, 3, 2, 1
    void push(int x)
    {
        q.push(x);
        int n = q.size() - 1;
        for (int i = 0; i < n; i++)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }

    int pop()
    {
        int i = q.front();
        q.pop();
        return i;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */