class Solution {
public:
    int countPartition(vector<int>& nums, int maxSum) {
    int partitions = 1;
    int partSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (partSum + nums[i] <= maxSum) {
            partSum += nums[i];
        } else {
            partitions++;
            partSum = nums[i];
        }
    }

    return partitions;
}

int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int partitions = countPartition(nums, mid);

        if (partitions > k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

};
