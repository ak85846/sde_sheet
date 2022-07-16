class MinStack {
    stack<long long>s;
    long long mini;
    
public:
    MinStack() {
        while(!s.empty())
            s.pop();
        mini=INT_MAX;
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            mini=val;
        }
        else{
            if(val<mini){
                s.push((long)2*val -(long)mini);
                mini=val;
            }
            else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        long long temp=s.top();
        s.pop();
        if(temp<mini){
            mini=(long)2*mini -(long)temp;
        }
    }
    
    int top() {
        if(s.empty())
            return -1;
        long long temp=s.top();
        if(temp<mini)
            return mini;
        else
            return temp;
    }
    
    int getMin() {
      return mini;  
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