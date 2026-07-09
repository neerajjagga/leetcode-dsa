class Solution {
public:
    bool check(vector<int>& nums) {
        int breakCount = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > nums[(i + 1) % nums.size()])
                breakCount++;

                if (breakCount > 1)
                    return false;
        }

        return breakCount <= 1;
    }
};