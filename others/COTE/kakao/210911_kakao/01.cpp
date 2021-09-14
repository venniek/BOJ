#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iostream>

using namespace std;
map<string, int> name;
int rep[1000][1000];
int result[1000];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for (int i = 0; i < id_list.size(); i++)
        name.insert(make_pair(id_list[i], i));
    for (int i = 0; i < report.size(); i++)
    {
        string tmp1;
        string tmp2;
        for (int j = 0; j < report[i][j]; j++)
        {
            while (report[i][j] != ' ')
                tmp1 += report[i][j];
            j++;
            while (report[i][j])
                tmp2 += report[i][j];
        }
        rep[name[tmp1]][name[tmp2]] = 1;
    }
    for (int i = 0; i < id_list.size(); i++)
    {
        for (int j = 0; j < id_list.size(); j++)
            result[j] += rep[i][j];
    }
    for (int i = 0; i < id_list.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < id_list.size(); j++)
        {
            if (rep[i][j] != 0 && result[j] >= k)
                cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}

int main()
{
	vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
	vector<string> report = {}
	solution({"muzi", "frodo", "apeach", "neo"}, {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"}, 2);
	return 0;
}