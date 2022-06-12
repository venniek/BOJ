#include <string>
#include <vector>
#include <utility>
#include <set>
using namespace std;

vector<string> solution(vector<vector<int> > line) {
    vector<string> answer;
    set<pair<long long, long long> > nums;
    long long minx = 21000000000, miny = 21000000000, maxx = -21000000000, maxy = -21000000000;
    
    for (int i = 0; i < line.size() -1; i++) {
        for (int k = i + 1; k < line.size(); k++) {
            long long x = (long long)line[i][1] * line[k][2] - (long long)line[i][2] * line[k][1];
            long long y = (long long)line[i][2] * line[k][0] - (long long)line[i][0] * line[k][2];
            long long div = (long long)line[i][0] * line[k][1] - (long long)line[i][1] * line[k][0];
            if (div == 0 || x % div || y % div) continue;
            x /= div; y /= div;
            nums.insert({x, y});
            minx = min(x, minx);
            miny = min(y, miny);
            maxx = max(x, maxx);
            maxy = max(y, maxy);
        }
    }
    for (int i = 0; i <= maxy - miny; i++) {
        string tmp;
        for (int k = 0; k <= maxx - minx; k++)
            tmp += '.';
        answer.push_back(tmp);
    }
    for (pair<long long, long long> p: nums)
        answer[maxy - p.second][p.first - minx] = '*';
    return answer;
}
