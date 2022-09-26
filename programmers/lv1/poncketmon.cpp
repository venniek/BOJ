#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int cnt = nums.size() / 2;
    set<int> s;
    
    for (int n: nums) {
        s.insert(n);
    }
    
    return min((int)s.size(), cnt);
}
