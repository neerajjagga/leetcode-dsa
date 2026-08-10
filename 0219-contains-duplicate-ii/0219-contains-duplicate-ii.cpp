class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> positions;

        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];

            if(positions.count(num)) {
                int distance = abs(i - positions[num]);
                if(distance <= k) return true;
            }
            positions[num] = i;
        }
        return false;
    }
};