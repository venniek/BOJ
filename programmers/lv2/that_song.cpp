#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <algorithm>
using namespace std;

int get_time(string t1, string t2) {
    stringstream ss1(regex_replace(t1, regex(":"), " "));
    stringstream ss2(regex_replace(t2, regex(":"), " "));
    string h1, m1, h2, m2;
    ss1 >> h1 >> m1;
    ss2 >> h2 >> m2;
    int h = stoi(h2) - stoi(h1);
    int m = stoi(m2) - stoi(m1);
    if (m < 0) {
        m += 60;
        h--;
    }
    return h * 60 + m;
}

string change_str(string str)  {
    string ret;
    
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i + 1] == '#') {
            ret += str[i] + 32;
            i++;
        }
        else
            ret += str[i];
    }
    if (str[str.size() - 1] != '#')
        ret += str[str.size() - 1];
    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int maxtime = -1;
    
    m = change_str(m);
    for (string info: musicinfos) {
        string t1 = info.substr(0, 5);
        string t2 = info.substr(6, 5);
        string title, infos, total;
        int i = 12;
        while (info[i] != ',') {
            title += info[i];
            i++;
        }
        i++;
        infos = info.substr(i);
        int t = get_time(t1, t2);
        infos = change_str(infos);
        for (int k = 0; k < t / infos.size(); k++)
            total += infos;
        total += infos.substr(0, t % infos.size());
        if (total.find(m) != string::npos) {  
            if (t > maxtime) {
                    answer = title;
                    maxtime = t;
                }
        }
    }
    return answer;
}
