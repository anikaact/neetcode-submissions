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
    unordered_map<string, map<int, string>> timeMap;
    TimeMap() {
        // initializes the object of the data structure
    }
    
    void set(string key, string value, int timestamp) {
        //stores key with value value at given timestamp (stores into timemap)
        timeMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        //returns value associated with the largest timestamp_prev
        if (timeMap[key][timestamp] != "") return timeMap[key][timestamp];

        int prev = -1;
        string prevvalue = "";
        for (const auto& [time, value] : timeMap[key]) {

            cout << time << ", " << value << "\n";
            if (time > timestamp && prev == -1) return value;
            if (time > timestamp && prev != -1) {
                return prevvalue;
            } 

            prev = time;
            if (value != "") prevvalue = value;            
        }

        return prevvalue;
    }
};
