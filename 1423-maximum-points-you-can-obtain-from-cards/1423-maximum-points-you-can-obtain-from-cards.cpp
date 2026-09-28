class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if(k == n)
            return totalSum;
     
        int windowSum = 0;
        int windowSize = n - k;

        int i = 0;
        while(i < windowSize) {
            windowSum += cardPoints[i];
            i++;
        }
        
        int minWindowSum = windowSum;

        int left = 0;
        for(int right = windowSize; right < n; right++) {
            windowSum -= cardPoints[left];
            windowSum += cardPoints[right];
            minWindowSum = min(minWindowSum, windowSum);
            left++;
        }

        return totalSum - minWindowSum;
    }
};