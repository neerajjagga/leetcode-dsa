class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int bill : bills) {

            // Customer pays $5
            if (bill == 5) {
                five++;
            }

            // Customer pays $10 -> give $5 change
            else if (bill == 10) {
                if (five == 0) {
                    return false;
                }

                five--;
                ten++;
            }

            // Customer pays $20 -> give $15 change
            else {
                // Prefer $10 + $5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                // Otherwise give three $5 bills
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};