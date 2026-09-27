class Solution {
public:
    // int fib(int n) {
    //     if(n == 0 || n == 1)
    //         return n;
        
    //     return fib(n-1) + fib(n-2);
    // }

    int fib(int n) {
        if(n == 0)
            return 0;
        
        int a = 0, b = 1;

        for(int i=0; i<n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }

        return a;
    }
};