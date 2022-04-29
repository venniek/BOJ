#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

char hak(double sco)
{
    if (sco >= 90)
        return ('A');
    else if (sco >= 80)
        return ('B');
    else if (sco >= 70)
        return ('C');
    else if (sco >= 50)
        return ('D');
    else
        return ('F');
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    vector<pair<int, int> > v;
    int sco;
    int len = scores.size();
    
    for (int i = 0; i < len; i++)
    {
        v.clear();
        sco = 0;
        for (int k = 0; k < len; k++)
            v.push_back(make_pair(scores[k][i], k));
        sort(v.begin(), v.end());
        if (v[0].second == i && v[0].first != v[1].first)
            v.erase(v.begin() + 0);
        else if (v[len - 1].second == i && v[len - 1].first != v[len - 2].first)
            v.pop_back();
        for (int j = 0; j < v.size(); j++)
          sco += v[j].first;
        sco /= v.size();
        answer += hak(sco);
    }
    return answer;
}
