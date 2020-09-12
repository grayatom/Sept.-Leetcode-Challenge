class Solution {
public:
    set<string> validTimes;
    
    bool isValid(string curr, int nxt) {
        if(curr.length() == 0) {
            if(nxt > 2) return false;
        }
        else if(curr.length() == 1) {
            if(curr[0] == '2') {
                if(nxt > 3) return false;
            }
        }
        else if(curr.length() == 2) {
            if(nxt > 5) return false;
        }
        return true;
    }
    
    void buildTime(vector<int>& a, int l, string curr) {
        if(l == 4) {
            validTimes.insert(curr);
            return;
        }
        for(int i = l; i < 4; i++) {
            swap(a[l], a[i]);
            if(isValid(curr, a[l])) {
                curr += to_string(a[l]);
                buildTime(a, l + 1, curr);
                curr.pop_back();
            }
            swap(a[l], a[i]);
        }
    }
    string largestTimeFromDigits(vector<int>& A) {
        validTimes.clear();
        buildTime(A, 0, "");
        if(validTimes.empty()) return "";
        string res = *validTimes.rbegin();
        res.insert(2, ":");
        return res;
    }
};
