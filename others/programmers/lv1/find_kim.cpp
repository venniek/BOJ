#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int ans;
    
    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == "Kim")
            ans = i;        
    }
    answer += "김서방은 ";
    answer += to_string(ans);
    answer += "에 있다";
    return answer;
}
