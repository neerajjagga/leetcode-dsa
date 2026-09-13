class Solution {
public:
    bool canMakeBouquets(vector<int> &bloomDay, int m, int k, long long day) {
        int cnt = 0;
        int noOfBoq = 0;
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= day) cnt++;
            else {
                noOfBoq += (cnt / k);
                cnt = 0;
            }
        }
        noOfBoq += (cnt / k);
        return noOfBoq >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long neededFlowers = 1LL * m * k;
        if(neededFlowers > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        long long ans = -1;

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(canMakeBouquets(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};