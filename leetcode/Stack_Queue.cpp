#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

// 232. Implement Queue using Stacks
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        rev.push(x);
    }

    //shift rev to nor, when nor is empty and pop()/peek() is called
    void shift(){
        if (!nor.empty()) return;
        while (!rev.empty()) {
            nor.push(rev.top());
            rev.pop();
        }
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        shift();
        if (nor.empty()) {
            return 0;
        } else {
            int temp = nor.top();
            nor.pop();
            return temp;
        }
    }
    
    /** Get the front element. */
    int peek() {
        shift();
        if (nor.empty()) {
            return 0;
        } else {
            int temp = nor.top();
            return temp;
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (rev.empty() && nor.empty());
    }

private:
    std::stack<int> rev, nor;
};

// 225. Implement Stack using Queues
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {    
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        st.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        // if (st.empty())
        //     return 0;
        int length = st.size();
        for (; length > 1; length--) {
            st.push(st.front());
            st.pop();
        }
        int top = st.front();
        st.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return st.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return st.empty();
    }
private:
    std::queue<int> st;
};