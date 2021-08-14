#include <vector>
#include <string>

using namespace std;

bool solution(string text)
{
	vector<int> comma;
	int len = text.size();
	bool num = false;

	if (text[0] == ',' || text[len - 1] == ',')
		return false;
	if (text[0] == '0' && len != 1)
		return false;
	for (int i = 0; i < len; i++)
	{
		if (!((text[i] >= '0' && text[i] <= '9') || text[i] == ','))
			return false;
		if (text[i] == ',')
			comma.push_back(i);
		else
			num = true;
	}
	if (num == false)
		return false;
	if (comma.size() && comma.size() != (len - comma.size() - 1) / 3)
		return false;
	for (int i = 0; i < comma.size(); i++)
	{
		if ((len - comma[i]) % 4)
			return false;
	}
	return true;
}
