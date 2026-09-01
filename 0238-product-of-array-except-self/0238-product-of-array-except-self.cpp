class Solution {
public:

    // Space = O(N) excluding Auxiliary space
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> prefixProduct(n+1, 1);
    //     vector<int> ans;

    //     for(int i=0; i<n; i++) {
    //         prefixProduct[i+1] = prefixProduct[i] * nums[i]; 
    //     }

    //     vector<int> suffixProduct(n+1, 1);

    //     for(int i=n-1; i>=0; i--) {
    //         suffixProduct[i] = suffixProduct[i+1] * nums[i];
    //     }

    //     for(int i=0; i<n; i++) {
    //         int product = prefixProduct[i] * suffixProduct[i+1];
    //         ans.push_back(product);
    //     }

    //     return ans;
    // }




    // Space = O(1) excluding Auxiliary space
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int prefix = 1;
        // pre store left product in ans
        for(int i=0; i<n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for(int i=n-1; i>=0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};