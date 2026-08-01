class Solution {
public:
    int climbStairs(int n) {
        int arr[n];
        arr[0] = 1;
        arr[1] = 2;

        for (int i = 2; i < n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }

        return arr[n - 1];
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
