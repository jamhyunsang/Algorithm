#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works)
{
    long long answer = 0;

    priority_queue<int> Works(works.begin(), works.end());

    for (int count = 0; count < n; count++)
    {
        int Work = Works.top();
        Works.pop();

        Work = Work - 1 > 0 ? Work - 1 : 0;

        Works.push(Work);
    }

    while (!Works.empty())
    {
        int Work = Works.top();
        Works.pop();
        answer += (long long)Work * (long long)Work;
    }

    return answer;
}