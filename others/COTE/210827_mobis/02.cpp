#include <string>
#include <vector>

using namespace std;

vector<bool> solution(vector<string> a) {
    vector<bool> answer;
    
    for (int i = 0; i < a.size(); i++)
    {
		string str = a[i];
        while (str.size() > 1)
        {
            if (str[0] == 'a')
                str.erase(0, 1);
            else if (str[str.size() - 1] == 'a')
                str.erase(str.size() - 1, 1);
            else if (str[0] == 'b' && str[str.size() - 1] == 'b')
            {
				int left = 0; int right = 0;
                while (left < str.size() && str[left] == 'b')
					left++;
                while (right < str.size() && str[str.size() - 1 - right] == 'b')
            		right++;
				right = min(right, left);
				left = 0;
				for (int k = right; k < str.size() - right; k++)
					if (str[k] == 'a')	left++;
				if (left != right)
				{
					str.erase();
                    break ;
                }
				str.erase(0, right);
				str.erase(str.size() - right, right);
			}
        }
        if (str.size() == 1 && str.compare("a") == 0)
            answer.push_back(true);
        else
            answer.push_back(false);
    }
    return answer;
}
