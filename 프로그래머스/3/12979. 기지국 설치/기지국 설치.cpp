#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int Station = 0;

    for (int APTCount = 1; APTCount <= n; APTCount++)
    {
        int Start = stations.size() > Station ? stations[Station] - w : n + 1;
        int End = stations.size() > Station ? stations[Station] + w : n + 1;

        if (Start > APTCount)
        {
            APTCount += w * 2;
            answer++;
        }
        else
        {
            APTCount = End;
            Station++;
        }
    }

    return answer;
}