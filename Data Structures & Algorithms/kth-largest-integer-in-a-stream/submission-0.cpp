class KthLargest {
public:
    int kth = 0;
    vector<int> stream;

    KthLargest(int k, vector<int>& nums) {
        kth = k;
        stream = nums;
        sort(stream.begin(), stream.end());
    }
    
    int add(int val) {
        stream.push_back(val);
        sort(stream.begin(), stream.end());
        return stream[stream.size() - kth];
    }
};
