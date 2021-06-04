#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);

	int map1[n][n];
	int map2[n][n];

	for (int i = 0; i < n; i++)
	{
		for (int k = n - 1; k >= 0; k--)
		{
			map1[i][k] = arr1.at(i) % 2;
			arr1.at(i) /= 2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = n - 1; k >= 0; k--)
		{
			map2[i][k] = arr2.at(i) % 2;
			arr2.at(i) /= 2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
			answer[i].push_back(map1[i][k] + map2[i][k] >= 1 ? '#' : ' ');
	}

    return answer;
}
