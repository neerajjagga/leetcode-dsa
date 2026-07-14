class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_count = 0;      
        int one_count = 0;      
        int two_count = 0;

        int i = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) zero_count++;
            else if(nums[i] == 1) one_count++;
            else two_count++;
        }      

        while(zero_count) {
            nums[i] = 0;
            i++;
            zero_count--;
        }
        while(one_count) {
            nums[i] = 1;
            i++;
            one_count--;
        }
        while(two_count) {
            nums[i] = 2;
            i++;
            two_count--;
        }
    }
};