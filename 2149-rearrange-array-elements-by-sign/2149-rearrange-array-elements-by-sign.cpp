class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int evenIndex = 0, oddIndex = 1;

        for(int num: nums) {
            if(num > 0) {
                result[evenIndex] = num;
                evenIndex += 2;
            }
            else {
                result[oddIndex] = num;
                oddIndex += 2;
            }
        }

        return result;
    }
};