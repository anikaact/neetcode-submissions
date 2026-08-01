class Solution {
public:
    int climbStairs(int n) {
        if ( n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

/*
n=1 O=1
n=2, O=2
n=3, O=3
n=4, O=5
    1111, 211, 121, 122, 22
n=5, O=8
    11111, 2111, 1211, 1121, 1112, 221, 212, 122



*/
