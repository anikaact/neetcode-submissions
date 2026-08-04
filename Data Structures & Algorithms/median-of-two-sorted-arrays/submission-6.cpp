class Solution {
public:
//nums1 = [1,2], nums2 = [3]
// firstptr = 0; secondptr = 0; median = 1
// firstptr = 1; secondptr = 0; median = 1
// return min(firstptr, secondptr)

//nums1 = [2,3], nums2 = [1]
// firstptr = 0; secondptr = 0; median = 1
// firstptr = 1; secondptr = 0; median = 1
// return min(firstptr, secondptr)

//nums1 = [1,3], nums2 = [2,4]
// firstptr = 0; secondptr = 0; median = 2
// firstptr = 1; secondptr = 0; median = 2
// firstptr = 1; secondptr = 1; median = 2


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //case 1: size is odd 
        //case 2: size is even (need to average 2 numbers)
        int len1 = nums1.size(), len2 = nums2.size();
        int medium1 = 0, medium2 = 0;
        int l = 0, r = 0;

        for (int i = 0; i < (len1 + len2) / 2 + 1; i++) {
            medium1 = medium2;
            if (l < len1 && r < len2) {
                if (nums1[l] < nums2[r]) {
                    medium2 = nums1[l];
                    l++; 
                } else {
                    medium2 = nums2[r];
                    r++;
                }
            } else if (l < len1) {
                medium2 = nums1[l];
                l++;
            } else {
                medium2 = nums2[r];
                r++;
            }
        }
        if ((len1 + len2) % 2 == 1) {
            return (double)medium2;
        } else {
            return (medium1 + medium2) / 2.0;
        }
    }
};
