class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        int index = 0;

        for(int i: nums) {
            if(i == 0) zeroCount++;    
            if(i == 1) oneCount++;    
            if(i == 2) twoCount++;    
        }

        while(zeroCount--) {
            nums[index++] = 0;
        }
        while(oneCount--) {
            nums[index++] = 1;
        }
        while(twoCount--) {
            nums[index++] = 2;
        }
    }
};