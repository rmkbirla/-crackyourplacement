//DP
class Solution {
public:
int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        vector<int>dp(n , -1);
       // return solve(0 , nums , k , dp);
       dp[n-1]=0;
        int val = 0 ;
       int mini = 1e9;
       for(int i=n-2;i>=0;i--)
       {  val=0;
            mini = 1e9;
           for(int j=i;j<n;j++)   //25
           {
                val = val + nums[j];
                int gap = j - i;
                if(val + gap <= k && j < nums.size() - 1){
              int cost = pow(k - (val+gap) , 2) + dp[j+1];
              mini = min(mini , cost);
          }
          else if(val + gap <= k && j == nums.size() - 1)  dp[i] = 0;
           }
           if(dp[i]!=0){
           dp[i]=mini;}
       }
       return dp[0];
    }
};




//Memo
class Solution {
public:
    int dp[502][2002];
    int memoSWW(int i,int rem,vector<int> nums,int k){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][rem]!= -1){
            return dp[i][rem];
        }
            
        int ans=0;

        if(nums[i]>rem){
            ans=(rem+1)*(rem+1) +memoSWW(i+1,k-nums[i]-1,nums,k);
            
        }else{
            ans=min((rem+1)*(rem+1) +memoSWW(i+1,k-nums[i]-1,nums,k),memoSWW(i+1,rem-nums[i]-1,nums,k));
        }
        dp[i][rem]=ans;
        return ans;
        
    }
  int solveWordWrap(vector<int>nums, int k) 
    {  memset(dp,-1,sizeof(dp));
       int n=nums.size();
       return memoSWW(0,k,nums,k);
    }
};
