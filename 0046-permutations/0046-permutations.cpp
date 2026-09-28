class Solution {
public:
    vector<vector<int>> result;

    void getPerms(vector<int>& nums, int idx) {
        if(idx == nums.size())
            result.push_back(nums);

        for(int i=idx; i<nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getPerms(nums, idx+1);

            swap(nums[idx], nums[i]); // backtracking
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        getPerms(nums, 0);
        return result;    
    }
};