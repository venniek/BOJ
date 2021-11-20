#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

typedef struct list
{
    string name;
    double exp_per_sec;
    int total_exp;
    int index;
} list;

typedef struct mon
{
    string name;
    int m_exp;
    int m_hp;
    int m_attack;
    int m_defense;
} moninfo;

struct cmp
{
    bool operator()(list a, list b)
    {
        if (a.exp_per_sec != b.exp_per_sec)
			return (a.exp_per_sec < b.exp_per_sec);
		if (a.total_exp != b.total_exp)
			return (a.total_exp < b.total_exp);
		return (b.index < a.index);
    }
};
priority_queue<list, vector<list>, cmp> pq;

string solution(string character, vector<string> monsters) {
    string answer = "";
    vector<int> player;
    moninfo mon_info;
    int tmp = 0;
    istringstream ssc(character);
    string strtmp;
    
    while (getline(ssc, strtmp, ' '))
        player.push_back(stoi(strtmp));
    for (int i = 0; i < monsters.size(); i++)
    {
        vector<string> montmp;
        istringstream ssm(monsters[i]);
        while (getline(ssm, strtmp, ' '))
            montmp.push_back(strtmp);
        mon_info.name = montmp[0];
        mon_info.m_exp = stoi(montmp[1]);
        mon_info.m_hp = stoi(montmp[2]);
        mon_info.m_attack = stoi(montmp[3]);
		mon_info.m_defense = stoi(montmp[4]);
		if (player[0] <= mon_info.m_attack - player[2] && player[1] < mon_info.m_hp) continue;
		if (player[1] <= mon_info.m_defense) continue;
		int time = mon_info.m_hp / (player[1] - mon_info.m_defense);
        if (mon_info.m_hp % (player[1] - mon_info.m_defense) != 0)
            time++;
		pq.push({mon_info.name, (double)mon_info.m_exp / time, mon_info.m_exp, i});
    }
    return pq.top().name;
}