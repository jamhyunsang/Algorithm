#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<int> _vAnswer;
    for (int i = 0; i < triangle.size(); i++)
    {
        _vAnswer.push_back(0);
    }
    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (j == 0)
            {
                _vAnswer[j] += triangle[i][j];
                continue;
            }
            else if (j == i)
            {
                _vAnswer[j] = _vAnswer[j - 1] + triangle[i][j];
                continue;
            }

            if (_vAnswer[j - 1] < _vAnswer[j])
            {
                _vAnswer[j] = _vAnswer[j] + triangle[i][j];
            }
            else
            {
                _vAnswer[j] = _vAnswer[j - 1] + triangle[i][j];
            }
        }
    }
    sort(_vAnswer.begin(), _vAnswer.end());
    answer = _vAnswer.back();
        return answer;
}