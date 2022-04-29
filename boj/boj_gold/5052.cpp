#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ilgwan;

int cmp(const string a, const string b)
{
	if (a.size() < b.size())
		return (1);
	return (0);
}

struct TRIE
{
	bool finish;
	TRIE *node[10];
	TRIE()
	{
		finish = false;
		for (int i = 0; i < 10; i++)
			node[i] = NULL;
	}

	void Insert(string str)
	{
		if (str[0] == '\0')
		{
			finish = true;
			return;
		}
		if (finish == true)
		{
			ilgwan = 0;
			return ;
		}
		int cur = str[0] - '0';
		if (node[cur] == NULL)
			node[cur] = new TRIE();
		str.erase(0, 1);
		node[cur]->Insert(str);
		return ;
	}
};

int main()
{
	int t, n;
	string tmp;
	vector<string> v;

	cin >> t;
	while (t-- > 0)
	{
		TRIE *root = new TRIE();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end(), cmp);
		ilgwan = 1;
		for (int i = 0; i < n; i++)
		{
			root->Insert(v[i]);
			if (ilgwan == 0)
				break;
		}
		if (ilgwan == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
		v.clear();
		delete root;
	}
	return 0;
}

