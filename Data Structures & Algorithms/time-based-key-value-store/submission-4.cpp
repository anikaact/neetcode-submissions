class TimeMap {
    /*
        key
            timestamp, value
            timestamp, value
        key
            timestamp, value

        vector<pair<string, vector<pair<int int>>>
        vector of {key, vector {timestamp, value}}
    */
public:
    unordered_map<string, vector<pair<int, string>>> timeMap;
    TimeMap() {
        // initializes the object of the data structure
        timeMap = {};
    }
    
    void set(string key, string value, int timestamp) {
        //stores key with value value at given timestamp (stores into timemap)
        //insert using binary
        vector<pair<int, string>> vec = timeMap[key];

        if (vec.empty()) {
            timeMap[key] = {{timestamp, value}};
            return;
        }

        int left = 0;
        int right = vec.size();
        cout << left << ", " << right << "\n";

        while (left < right) {
            int mid = (right - left)/2 + left;

            if (vec[mid].first < timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        cout << timestamp << ", " << left << "\n";

        timeMap[key].insert(timeMap[key].begin() + left, {timestamp, value});
    }
    
    string get(string key, int timestamp) {
        //returns value associated with the largest timestamp_prev
        if (timeMap.find(key) == timeMap.end()) return "";
        
        // use binary to find the value
        vector<pair<int, string>>& vec = timeMap[key];
        if (vec.empty()) return "";

        int left = 0;
        int right = vec.size();

        while (left < right) {
            int mid = (right - left)/2 + left;
            if (vec[mid].first <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left == 0) return "";

        //cout << right << ", " << vec[right].second << "\n";
        return vec[left - 1].second;
    }
};
