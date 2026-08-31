class Solution {
public:
    // Time Comp - 
    /*
Frequency counting       O(n)
Building map             O(d log d)
Traversing order         O(d + k)
---------------------------------
Total                    O(n + d log d)
    */

    // Space Comp - O(n) 
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x: nums) freq[x]++;

        map<int, vector<int>> order;

        for(auto &[num, count]: freq)
            order[count].push_back(num);

        vector<int> ans;

        for(auto it=order.rbegin(); it != order.rend() && ans.size() < k;    it++) {
            for(int num: it->second) {
                ans.push_back(num);

                if(ans.size() == k) break; 
            }
        }

        return ans;
    }
};
