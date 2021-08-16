#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int len = prices.size();
    
    for (int i = 0; i < len - 1; i++)
    {
        for (int k = i + 1; k < len; k++)
        {
            if (prices[i] <= prices[k] && k != len - 1)
                continue;
            else
            {
                answer.push_back(k - i);
                break;
            }
        }
    }
    answer.push_back(0);
    return answer;
}
