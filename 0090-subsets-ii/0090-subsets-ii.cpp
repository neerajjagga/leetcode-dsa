class Solution {
public:
    vector<vector<int>> result;

    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i) {
        if(i == nums.size()) {
            result.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i+1);
        ans.pop_back();

        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[i]) idx++;

        getAllSubsets(nums, ans, idx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        getAllSubsets(nums, ans, 0);
        return result;
    }
};