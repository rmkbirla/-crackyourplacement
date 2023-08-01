class Solution {
public:
    pair<int, long long> helper(vector<int>& arr, int left, int right,pair<int, long long>** dp) {
        if (left == right) {
            return { arr[left], 0LL };
        }
        pair<int, long long> x={-1,-1};
        if(dp[left][right]!= x){
            return dp[left][right];
        }
        pair<int, long long> ans = { 0, INT_MAX };
        for (int i = left; i < right; i++) {
            pair<int, long long> l = helper(arr, left, i,dp);
            pair<int, long long> r = helper(arr, i + 1, right,dp);

            long long sum = l.second + r.second + (static_cast<long long>(l.first) * r.first);
            if (sum < ans.second) {
                ans.second = sum;
            }
            ans.first = max(l.first, r.first);
        }
        return dp[left][right]= ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        pair<int, long long>** dp=new pair<int,long long>*[n];
        for(int i=0;i<n;i++){
            dp[i]=new pair<int,long long>[n];
            for(int j=0;j<n;j++){
                dp[i][j]={-1,-1};
            }
        }
        return static_cast<int>(helper(arr, 0, arr.size() - 1,dp).second);
    }
};
