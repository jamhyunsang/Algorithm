#include <string>
#include <vector>
#include <sstream>
#include <deque>
#include <algorithm>

using namespace std;

vector<string> Split(string& str, char delimiter)
{
    vector<string> result;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter))
    {
        result.push_back(token);
    }

    return result;
}

int ConvertToInt(string s)
{
	return stoi(s);
}

vector<int> solution(vector<string> operations) {
    vector<int> queue;

    for (size_t s = 0; s < operations.size(); s++)
    {
        vector<string> order = Split(operations[s], ' ');

        if (order[0] == "I")
        {
            queue.push_back(ConvertToInt(order[1]));
        }
        else if (order[0] == "D")
        {
            if (queue.empty())
                continue;
            if (order[1] == "1")
            {
                auto max = max_element(queue.begin(), queue.end());
                queue.erase(max);
            }
            else if (order[1] == "-1")
            {
                auto minIter = min_element(queue.begin(), queue.end());
                queue.erase(minIter);
            }
		}
    }

    vector<int> answer;

    if (queue.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        auto max = max_element(queue.begin(), queue.end());
        auto min = min_element(queue.begin(), queue.end());
        answer.push_back(*max);
        answer.push_back(*min);
	}

    return answer;
}