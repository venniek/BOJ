#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define PII pair<int, int>

int main() {
	int t, n;
	int s, m;
	int ans;

	cin >> t;
	while (t-- > 0) {
		cin >> n;
		ans = 0;
		priority_queue<PII, vector<PII>, greater<PII> > sinip;
		for (int i = 0; i < n; i++) {
			cin >> s >> m;
			sinip.push({s, m});
		}
		while (!sinip.empty()) {
			int tmp = sinip.top().second;
			sinip.pop();
			ans++;
			while (!sinip.empty() && tmp < sinip.top().second)
				sinip.pop();
		}
		cout << ans << endl;
	}
}