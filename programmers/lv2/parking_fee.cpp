#include <string>
#include <vector>
#include <cstring>

using namespace std;
int num[10000];
int price[10000];
int check[10000];

vector<string> split(string s, string divid) {
	vector<string> v;
	char* c = strtok((char*)s.c_str(), divid.c_str());
	while (c) {
		v.push_back(c);
		c = strtok(NULL, divid.c_str());
	}
	return v;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	for (int i = 0; i < records.size(); i++)
	{
		vector<string> tmp = split(records[i], " ");
		vector<string> timetmp = split(tmp[0], ":");
		int car_num = stoi(tmp[1]);
		int time = stoi(timetmp[0]) * 60 + stoi(timetmp[1]);
		int sign = tmp[2].compare("IN") == 0 ? -1 : 1;
		num[car_num] += sign * time;
		check[car_num] = 1;
	}
	for (int i = 0; i < 10000; i++)
	{
		if (check[i] == 1 && num[i] <= 0)
			num[i] += 1439;
		if (num[i] > 0)
		{
			price[i] = fees[1];
			if (num[i] > fees[0])
			{
				num[i] -= fees[0];
				price[i] += num[i] / fees[2] * fees[3];
				if (num[i] % fees[2] != 0)
					price[i] += fees[3];
			}
			answer.push_back(price[i]);
		}
	}
	return answer;
}