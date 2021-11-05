#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string tmp = "";
    
    for (int i = 0; i < new_id.size(); i++)
        new_id[i] += new_id[i] >= 'A' && new_id[i] <= 'Z' ? 'a' - 'A' : 0;
    for (int i = 0; i < new_id.size(); i++)
    {
        char c = new_id[i];
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.')
            tmp += c;
    }
    new_id.clear();
    for (int i = 0; i < tmp.size(); i++)
    {
        char c = tmp[i];
        if (i > 0 && c == '.' && tmp[i - 1] == '.')
            continue;
        new_id += c;
    }
    if (new_id.size() > 0 && new_id[0] == '.')
        new_id.erase(0, 1);
    if (new_id.size() > 0 && new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.size() - 1, 1);
    if (new_id[0] == '\0')
        new_id += 'a';
    if (new_id.size() >= 16)
        new_id.erase(15);
    if (new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.size() - 1, 1);
    if (new_id.size() <= 2)
    {
        char c = new_id[new_id.size() - 1];
        while (new_id.size() < 3)
            new_id += c;
    }
    return new_id;
}
