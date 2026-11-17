class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
          stack<int> st;

    int j = 0;

    for (int i = 0; i < pushed.size(); i++) {

        // Push element
        st.push(pushed[i]);

        // Pop whenever top matches required element
        while (!st.empty() && st.top() == popped[j]) {

            st.pop();
            j++;
        }
    }

    return st.empty();
}
    
};