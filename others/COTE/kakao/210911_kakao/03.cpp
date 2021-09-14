#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iostream>

using namespace std;

map<string, int> car;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for (int i = 0; i < records.size(); i++)
    {
        string num;
        string inout;
        int h = (records[i][0] - '0') * 10 + records[i][1] - '0';
        int m = (records[i][3] - '0') * 10 + records[i][4] - '0';
        int time = h * 60 + m;
        int j = 6;
        while (records[i][j] != ' ')
            num += records[i][j++];
        j++;
        while (records[i][j])
            inout += records[i][j++];
        if (car.find(num) == car.end())
            car.insert(make_pair(num, time * -1));
        else if (inout.compare("IN") == 0)
            car[num] -= time;
        else
            car[num] += time;
    }
    for (auto i = car.begin() ; i != car.end(); i++)
    {
        int time = i->second;
        if (time <= 0)
            time += 1439;
        if (time <= fees[0])
            answer.push_back(fees[1]);
        else
        {
            time -= fees[0];
            if (time % fees[2])
                time = time / fees[2] + 1;
            else
                time /= fees[2];
            answer.push_back(time * fees[3] + fees[1]);
        }
    }
    return answer;
}
