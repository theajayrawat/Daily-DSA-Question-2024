// https://leetcode.com/problems/implement-queue-using-stacks/
// T.C : O(N)
// S.C : O(N)

class MyQueue {
public:
    stack<int>s1,s2;
    int front;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty())front=x;
        s1.push(x);
    }
    
    int pop() {
        int ans;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        ans=s2.top();
        s2.pop();
        while(!s2.empty()){
            if(s1.empty())front=s2.top();
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return s1.empty();
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

