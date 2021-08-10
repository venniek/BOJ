#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i != 0 && arr[i] == answer.back())
            continue;
		answer.push_back(arr[i]);
    }
    return answer;
}
