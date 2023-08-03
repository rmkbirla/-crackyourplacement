class Solution {
public:
    vector<int> nextmin(vector<int>& arr) {
    stack<int> st;
    int n = arr.size();
    st.push(n);
    vector<int> next(n);
    for (int i = n - 1; i >= 0; i--) { 
        while (st.top() != n && arr[st.top()] > arr[i]) {
            st.pop();
        }
        next[i] = st.top() != n ? st.top() : n;
        st.push(i);
    }
    return next;
    }
    
    vector<int> prevmin(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        st.push(-1);
        vector<int> next(n);
        for (int i = 0; i < n; i++) { 
            while (st.top() != -1 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
        return next;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> prev=prevmin(arr);
        vector<int> next=nextmin(arr);

        for(int i=0;i<next.size();i++){
            cout<<next[i]<<" ";
        }
        int sum=0;
        for(int i=0;i<arr.size();i++){
         sum=(sum+1ll*arr[i]*(i-prev[i])*(next[i]-i))%1000000007;       
        }
       return sum;
    }
};
