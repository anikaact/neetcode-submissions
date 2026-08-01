class Solution {
public:
    // Encode as: <len>#<string><len>#<string>...
    string encode(vector<string>& strs) {
        string out;
        for (const string& t : strs) {
            out += to_string(t.size());
            out.push_back('#');
            out += t;
        }
        return out;
    }

    vector<string> decode(const string& s) {
        vector<string> res;
        size_t i = 0;
        while (i < s.size()) {
            // 1) read length (digits) up to '#'
            size_t j = i;
            while (j < s.size() && s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));

            // 2) skip '#', then read 'len' chars
            j++; // now at start of string
            res.push_back(s.substr(j, len));

            // 3) advance to next block
            i = j + len;
        }
        return res;
    }
};
