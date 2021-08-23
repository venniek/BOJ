#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int i, j;
    
    for (i = 1; i <= sqrt(yellow); i++)
    {
        j = yellow / i;
        if (i * j != yellow)
            continue;
        if ((i + 2) * (j + 2) == yellow + brown)
            break;
    }
    answer.push_back(j + 2);
    answer.push_back(i + 2);
    return answer;
}
