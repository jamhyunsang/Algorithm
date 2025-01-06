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

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    deque<int> queue;

    for (int count = 0; count < operations.size(); count++)
    {
        vector<string> split = Split(operations[count], ' ');

        switch (split[0][0])
        {
        case 'I':
        {
            queue.push_back(stoi(split[1]));
        }
        break;
        case 'D':
        {
            if (!queue.empty())
            {
                sort(queue.begin(), queue.end());
                if (split[1] == "1")
                {
                    queue.pop_back();
                }
                else
                {
                    queue.pop_front();
                }
            }
        }
        break;
        }
    }

    if (queue.empty())
    {
        answer = { 0,0 };
    }
    else
    {
        sort(queue.begin(), queue.end());
        answer.push_back(queue.back());
        answer.push_back(queue.front());
    }

    return answer;
}