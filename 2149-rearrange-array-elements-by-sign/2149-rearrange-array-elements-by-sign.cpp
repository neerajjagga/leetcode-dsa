class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        // Brute force

        // int n = nums.size();
        
        // vector<int>pos;
        // vector<int>neg;
        // vector<int>ans;

        // // dividing postive and negative numbers
        // for(int i=0; i<n; i++) {
        //     if(nums[i] > 0) {
        //     pos.push_back(nums[i]);
        //     }
        //     else {
        //     neg.push_back(nums[i]);
        //     }
        // }
    
        // // pushing elements into ans array 
        // // in order 
        // for(int i=0; i<n/2; i++) {
        //     ans.push_back(pos[i]);
        //     ans.push_back(neg[i]);
        // }

        // return ans;

        

        // optimal approach

        int n = nums.size();
        int even = 0, odd = 1;
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int num = nums[i];

            if(num >= 0) {
            ans[even] = nums[i];
            even += 2;
            } else {
            ans[odd] = nums[i];
            odd += 2;
            }
        }

        return ans;
    }
};