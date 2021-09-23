#include <string>
#include <vector>

using namespace std;

vector<vector<int> > solution(vector<vector<int> > arr1, vector<vector<int> > arr2) {
    vector<vector<int> > answer;
	int m, n, l;
	// arr1 m * n  arr2  n * l
	m = arr1.size();
	n = arr1[0].size();
	l = arr2[0].size();

	for (int i = 0; i < m; i++)
	{
		vector<int> anstmp;
		for (int j = 0; j < l; j++)
		{
			int tmp = 0;
			for (int k = 0; k < n; k++)
			{
				tmp += arr1[i][k] * arr2[k][j];
			}
			anstmp.push_back(tmp);
		}
		answer.push_back(anstmp);
	}
    return answer;
}
