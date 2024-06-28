#define n 1000

class MyStack {
    int Top;
    int *arr;
public:
    MyStack() {
        Top=-1;
        arr=new int[n];
    }
    
    void push(int x) {
        if(Top==n-1)
        return;
        ++Top;
        arr[Top]=x;
    }
    
    int pop() {
        if(Top==-1)
        return -1;
        int val=arr[Top];
        --Top;
        return val;
    }
    
    int top() {
        if(Top==-1)
        return -1;
        return arr[Top];
    }
    
    bool empty() {
        return Top==-1;
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