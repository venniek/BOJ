#include <vector>
using namespace std;

int add_giji(int cnt, int len) {
    if (cnt <= 0) return 0;
    return cnt / len + (cnt % len != 0);
}

int solution(int n, vector<int> stations, int w)
{
    int ans = 0;
    int len = w * 2 + 1;
    int start = 1;
    
    for (int s : stations) {
        ans += add_giji(s - w - start, len);
        start = s + w + 1;
    }
    ans += add_giji(n - start + 1, len);
    return ans;
}
