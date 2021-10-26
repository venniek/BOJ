#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    for (int i = 1; i <= n; i++)
    {
        int tmp1 = 0; int tmp2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (citations[j] >= i)
                tmp1++;
            if (citations[j] <= i)
                tmp2++;
        }
        if (tmp1 >= i && n - i <= tmp2)
            answer = max(answer, i);
    }
    return answer;
}
