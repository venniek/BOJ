#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

vector<string> split(string s, string divid) {
	vector<string> v;
	char* c = strtok((char*)s.c_str(), divid.c_str());
	while (c) {
		v.push_back(c);
		c = strtok(NULL, divid.c_str());
	}
	return v;
}

int is_prime(long long n) {
	if (n == 2 || n == 3 || n == 5)
		return 1;
	if (n == 1 || n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
		return 0;
	for (long long i = 7; i <= sqrt(n); i += 2)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int solution(int n, int k) {
	int answer = 0;
	string num_in_k;

	while (n > 0)
	{
		num_in_k += n % k + '0';
		n /= k;
	}
	reverse(num_in_k.begin(), num_in_k.end());
	vector<string> nums = split(num_in_k, "0");
	for (int i = 0; i < nums.size(); i++)
	{
		if (is_prime(stoll(nums[i])) == 1)
			answer++;
	}
	return answer;
}