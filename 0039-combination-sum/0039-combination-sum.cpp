class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int>& candidates, int target, int start, vector<int>& current) {
        if(target == 0) {
            ans.push_back(current);
            return;
        }

        for(int i=start; i<candidates.size(); i++) {

            if(candidates[i] > target)
                break;
            
            current.push_back(candidates[i]);
            // try then also from same i
            helper(candidates, target - candidates[i], i, current);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> current;
        helper(candidates, target, 0, current);
        return ans;
    }
};