#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int idx;

int cmp(string a, string b)
{
    return a[idx] == b[idx] ? a < b : a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {

    idx = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}
