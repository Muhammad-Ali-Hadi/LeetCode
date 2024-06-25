#define x 100

class stacks{
    int top;
    int *arr;
    public:
    stacks()
    {
        arr=new int[x];
        top=-1;
    }

    void push(int val)
    {
        if(top==x-1)
        {
            return;
        }
        ++top;
        arr[top]=val;
    }

    void pop()
    {
        if(top==-1)
        return;
        --top;
    }

    int Top()
    {
        if(top==-1)
        return -1;
        return arr[top];
    }

    bool empty()
    {
        return top==-1;
    }

    ~stacks()
    {
        delete[] arr;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        // if(n<=3)
        // return n;

        // int previous = 2;
        // int current = 3;

        // for(int i=4;i<=n;++i)
        // {
        //     int next = previous+current;
        //     previous = current;
        //     current = next;
        // }
        // return current;
        
        // Using Stacks
        if(n<=3)
        return n;
        stacks stack;
        stack.push(1);
        stack.push(2);
        for (int i=3;i<=n;++i) 
        {
            int first=stack.Top();
            stack.pop();
            int second=stack.Top();
            stack.push(first);
            stack.push(first+second);
        }
        return stack.Top();
    }
};