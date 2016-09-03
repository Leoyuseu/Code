// Implement the following operations of a queue using stacks.

// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.
// Notes:
// You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
// You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

class Queue {
public:
    // Push element x to the back of queue.
    stack<int> si;
    stack<int> so;
    int n;
    Queue(){
        n=0;
    }
    void push(int x) {
        n++;
        si.push(x);
    }
    // Removes the element from in front of queue.
    void pop(void) {
        n--;
        if(!so.empty()){
            so.pop();
        }
        else{
            int l=si.size();
            for(int i=0;i<l;i++){
                so.push(si.top());
                si.pop();
            }
            so.pop();
        }
    }
    // Get the front element.
    int peek(void) {
        if(!so.empty()){
            return so.top();
        }
        else{
            int l=si.size();
            for(int i=0;i<l;i++){
                so.push(si.top());
                si.pop();
            }
            return so.top();
        }
    }
    // Return whether the queue is empty.
    bool empty(void) {
        return(n==0);
    }
};


//***************Implement Stack using Queues******************
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        unsigned int size = s.size();
        this->s.push(x);
        while (size--){
            s.push(s.front());
            s.pop();
        }
    }
    // Removes the element on top of the stack.
    void pop() {
        s.pop();
    }
    // Get the top element.
    int top() {
       return s.front(); 
    }
    // Return whether the stack is empty.
    bool empty() {
        return s.empty();
    }
private:
    queue<int> s;
};