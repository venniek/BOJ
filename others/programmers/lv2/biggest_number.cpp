#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(const string &a, const string &b){
    if(b + a < a + b)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> strings;
    
    for(int i : numbers)
        strings.push_back(to_string(i));
    
    sort(strings.begin(), strings.end(), compare);
    
    for (int i = 0; i < strings.size(); i++)
        answer += strings[i];
    
    if(answer[0] == '0')
        answer = "0";
    return answer;
}
