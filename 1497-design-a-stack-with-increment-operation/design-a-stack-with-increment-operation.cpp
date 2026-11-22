class CustomStack {
private:
    vector<int> st;
    vector<int> inc;
    int maxSize;
public:

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        st.resize(maxSize);
        inc.resize(maxSize, 0);
    }
    
    void push(int x) {
            if (topIndex + 1 == maxSize) {
            return;
        }

        topIndex++;
        st[topIndex] = x;
    
    }
    
    int pop() {
         if (topIndex == -1) {
            return -1;
        }

        int idx = topIndex;
        int result = st[idx] + inc[idx];

        if (idx > 0) {
            inc[idx - 1] += inc[idx];
        }

        inc[idx] = 0;
        topIndex--;

        return result;
    }
    
    void increment(int k, int val) {
        int idx = min(k, topIndex + 1) - 1;

        if (idx >= 0) {
            inc[idx] += val;
        }
    }
    private:
    int topIndex = -1;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
 