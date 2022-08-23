class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int fromTo[200] = { 0, };
        int used[200] = { 0, };
        for (int i = 0; i < s.size(); i++) {
            int sc = s[i];
            int tc = t[i];
            if (fromTo[sc] == 0) {
                if (used[tc] == 1) { return false; }
                fromTo[sc] = tc;
                used[tc] = 1;
            } else {
                if (fromTo[sc] != tc) { return false; }
            }
        }
        return true;
    }
};
