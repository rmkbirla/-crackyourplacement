class Solution {
public:
    int countcowscanbeassigned(vector<int>& nums, int mindif) {
    int cows = 1;
    int dist = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i]-dist < mindif) {
        
            continue;
        } else {
            cows++;
            dist = nums[i];
        }
    }

    return cows;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low=0;
        int high=stalls[n-1]-stalls[0];
          int cows;
          int ans;
     while (low <= high) {
        int mid = low + (high - low) / 2;
        cows =countcowscanbeassigned(stalls, mid);

        if (cows >= k) {
            low = mid + 1;
            ans=mid;
        } else {
            high = mid - 1;
        }
    }

    return ans;
        // Write your code here
    }
};
