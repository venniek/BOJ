#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int n, k, len;
string val;
stack <char> s;
vector<char> v;

int main() {
	int n, k;
	cin >> n >> k;
	cin >> val;
	len = n - k;
	for (int i = 0; i < val.length(); i++) {

		while (k && !s.empty() && s.top() < val[i]) {
			s.pop();
			k--;
		}
		s.push(val[i]);
	}
	
    while (s.size() > len)
        s.pop();
	for (int i = 0; i < len; i++)
	{	
		v.push_back(s.top());
		s.pop();
	}
	for (int i = 0; i < len; i++)
		cout << v[len - i - 1];
	return 0;
}
