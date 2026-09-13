class Solution {
public:
    long long calcTotalHours(vector<int> &piles, int hour) {
        long long totalHours = 0;
        for(int i=0; i<piles.size(); i++) {
            totalHours += ceil(double(piles[i]) / hour);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = calcTotalHours(piles, mid);
            if(totalH <= h)
                high = mid - 1;
            else low = mid + 1;                       
        }

        return low;
    }
};