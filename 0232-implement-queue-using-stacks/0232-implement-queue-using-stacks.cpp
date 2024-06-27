#define n 1000

class MyQueue {
    int front;
    int back;
    int *arr;
public:
    MyQueue()
    {
        arr=new int[n];
        front=-1;
        back=-1;
    }

    void push(int val)
    {
        if(back==n-1)
        {
            cout<<"Queue Overflow!\n";
            return;
        }
        ++back;
        arr[back]=val;
        if(front==-1)
        ++front;
    }

    int pop()
    {
        if(front==-1 || front>back)
        {
            cout<<"No Elements in Queue\n";
            return -1;
        }
        int val=arr[front];
        ++front;
        return val;
    }

    int peek()
    {
        if(front==-1 || front>back)
        {
            cout<<"No Elements in Queue\n";
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        return front==-1 || front>back;
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