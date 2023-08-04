class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> dq   ;
       vector<int> output;
       for(int i=0;i<nums.size();i++){
           while(!dq.empty() && nums[dq.back()]<nums[i]){
               dq.pop_back();
           }
           dq.push_back(i);
            if(dq.front()<=i-k){
               dq.pop_front();
           }
           if(i>=k-1){
             output.push_back(nums[dq.front()]);
           }
          
       }
        return output;
    }
};
