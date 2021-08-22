#include <string>
#include <vector>
#include <cmath>
#include <iostream>  /////erase!!

#define MOD (int)pow(10, 7)+19
using namespace std;

vector<long long> solution(string s0, string s1, string line, long long k) {
    vector<long long> answer;
    vector< vector<long long> > cnt(2);
    string newline;
    long long zero_first = 0;
    long long one_first = 0;
    
    for (int j = 0; j < k; j++)
    {
        if (j != 0)
        {
            swap(line, newline);
            newline.clear();
        }
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == '1')
                newline += s1;
            else
                newline += s0;
        }
    }
    cnt[0].push_back(0);
    cnt[1].push_back(0);
    for (int i = 0; i < newline.size(); i++)
    {
        if (newline[i] == '1')
        {
            cnt[0].push_back(cnt[0].back());
            cnt[1].push_back((cnt[1].back() + 1));
            zero_first += cnt[0][i];
        }
        else
        {
            cnt[0].push_back((cnt[0].back() + 1));
            cnt[1].push_back(cnt[1].back());
            one_first += cnt[1][i];
        }
        zero_first %= MOD;
        one_first %= MOD;
    }
    answer.push_back(zero_first);
    answer.push_back(one_first);
    return answer;
}
