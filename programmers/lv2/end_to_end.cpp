#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, int> m;
    vector<int> answer;
    int i;
    
    for (i = 0; i < words.size(); i++)
    {
        if ((i != 0 && words[i - 1][words[i - 1].size() - 1] != words[i][0]) || m.find(words[i]) != m.end())
            return {i % n + 1, i / n + 1};
        else
            m.insert({words[i], i % n + 1});
    }
    return {0, 0};
}
