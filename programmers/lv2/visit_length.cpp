#include <string>
#include <set>
#include <map>
#include <utility>
#define PII pair<int, int>
using namespace std;

int solution(string dirs) {
    set<pair<PII, PII> > visit;
    map<char, PII> dir;
    PII loc = {0, 0};
    
    dir.insert({'U', {0, 1}}); dir.insert({'D', {0, -1}});
    dir.insert({'R', {1, 0}}); dir.insert({'L', {-1, 0}});
    for (char c: dirs) {
        PII nloc = {loc.first + dir[c].first, loc.second + dir[c].second};
        if (nloc.first > 5 || nloc.first < -5 || nloc.second > 5 || nloc.second < -5)
            continue;
        if (loc != nloc && visit.find({nloc, loc}) == visit.end())
            visit.insert({loc, nloc});
        loc = nloc;
    }
    return visit.size();
}
