#define n 1000

class MinStack {
    int Top;
    int *arr;
public:
    MinStack() {
        Top=-1;
        arr=new int[n];
    }
    
    void push(int val) {
        if(Top==n-1)
        return;
        ++Top;
        arr[Top]=val;
    }
    
    void pop() {
        if(Top==-1)
        return;
        --Top;
    }
    
    int top() {
        if(Top==-1)
        return -1;
        return arr[Top];
    }
    
    int getMin() {
        int min=arr[0];
        for(int i=0;i<=Top;++i)
        {
            if(min>arr[i])
            min=arr[i];
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */