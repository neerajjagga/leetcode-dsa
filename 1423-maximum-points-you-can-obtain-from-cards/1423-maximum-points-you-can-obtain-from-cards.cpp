class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = k-1, r = n-1;
        
        int maxScore = 0;
        int currentScore = 0;
        
        // precompute first k elements sum
        for(int i=0; i<=l; i++) {
            currentScore += cardPoints[i];
        }
        
        maxScore = currentScore;
        
        // if length of array is equal to k - then direct return precompute score
        if(k == n) return maxScore;
        
        while (l >= 0) {
            currentScore -= cardPoints[l--];
            currentScore += cardPoints[r--];
            maxScore = max(maxScore, currentScore);
        }
        
        
        return maxScore;
    }
};