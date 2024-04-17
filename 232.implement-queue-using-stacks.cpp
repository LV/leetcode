// @leet start
class MyQueue {
public:
    stack<int> pushStack;
    stack<int> pullStack;
    MyQueue() {}

    void push(int x) {
        pushStack.push(x);
    }

    int pop() {
        if(pushStack.empty() && pullStack.empty()) return 0; // terrible hack to avoid invalid memory access
        // assumes a `pop()` is only called when the queue is non-empty

        if(!pullStack.empty()) {
            int top = pullStack.top();
            pullStack.pop();
            return top;
        }
        if(pushStack.size() == 1) {
            int top = pushStack.top();
            pushStack.pop();
            return top;
        }
        while(!pushStack.empty()) {
            pullStack.push(pushStack.top());
            pushStack.pop();
        }
        int top = pullStack.top();
        pullStack.pop();
        return top;
    }

    int peek() {
        if(pushStack.empty() && pullStack.empty()) return 0; // terrible hack to avoid invalid memory access
        if(!pullStack.empty()) return pullStack.top();
        if(pushStack.size() == 1) return pushStack.top();
        while(!pushStack.empty()) {
            pullStack.push(pushStack.top());
            pushStack.pop();
        }
        return pullStack.top();
    }

    bool empty() {
        return pushStack.empty() && pullStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @leet end
