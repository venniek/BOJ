#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int lmin = 0, smin = 0;
    
    for (vector<int> v: sizes) {
        lmin = max(lmin, max(v[0], v[1]));
        smin = max(smin, min(v[0], v[1]));
    }
    return smin * lmin;
}
