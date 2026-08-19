class Solution {
public:
    /*
    Example 2: -12 % 5

C++:

-12 % 5 = -2

Again, add 5:

-2 + 5 = 3

So:

-12 → remainder 3

Check:

-12 = (-3 × 5) + 3
     = -15 + 3

Correct.

Example 3: -13 % 5

C++ gives:

-13 % 5 = -3

Add 5:

-3 + 5 = 2

Therefore:

-13 → remainder 2

Check:

-13 = (-3 × 5) + 2
     = -15 + 2

Correct.

Example 4: -14 % 5

C++:

-14 % 5 = -4

Add 5:

-4 + 5 = 1

Therefore:

-14 → remainder 1

Check:

-14 = (-3 × 5) + 1
     = -15 + 1

Correct.
    */
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remFreq;
        for(int num: arr) {
            int rem = ((num % k) + k) % k;
            remFreq[rem]++;
        }

        if (remFreq[0] % 2 != 0) {
            return false;
        }

        for(int rem=1; rem <= k/2; rem++) {
            int need = k - rem;
            
            if(need == rem) {
                if(remFreq[rem] % 2 != 0) return false;
            }
            else {
                if (remFreq[rem] != remFreq[need]) {
                    return false;
                }
            }
        }

        return true;
    }
};