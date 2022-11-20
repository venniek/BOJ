#include <vector>
using namespace std;

int check_order(vector<int> &v, int i) {
    int last = v.size() - 1;

    if (v[last - 1] < v[last] && i < v[last]) {
        return 0;
    }
    return 1;
}

int solution(vector<int> a) {
    int i = 0;
    vector<int> tmp;

    while (i < a.size()) {
        if (tmp.size() < 2 || check_order(tmp, a[i])) {
            tmp.push_back(a[i]);
            i++;
        }
        else
            tmp.pop_back();
    }
    return tmp.size();
}
