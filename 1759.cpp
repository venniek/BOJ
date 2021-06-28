#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> pw;
vector<char> alpha;
int l, c;

int cmp(char a, char b)
{
	if (a < b)
		return (1);
	return (0);
}

int check_right()
{
	int m = 0;
	int j = 0;
	
	for (int i = 0; i < l; i++)
	{
		char t = pw[i];
		if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u')
			m++;
		else
			j++;
	}
	if (m >= 1 && j >= 2)
		return (1);
	return (0);
}

void make_pw(int index)
{
	if (pw.size() == l)
	{
		if (check_right() == 1)
		{
			for (int i = 0; i < l; i++)
				cout << pw[i];
			cout << endl;
		}
		return ;
	}
	for (int i = index; i < c; i++)
	{
		pw.push_back(alpha[i]);
		make_pw(i + 1);
		pw.pop_back();
	}
}

int main()
{
	char tmp;

	cin >> l >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> tmp;
		alpha.push_back(tmp);
	}
	sort(alpha.begin(), alpha.end(), cmp);
	make_pw(0);
	return 0;
}
