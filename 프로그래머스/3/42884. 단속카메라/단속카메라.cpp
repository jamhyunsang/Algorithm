#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Compare(vector<int> A, vector<int> B)
{
    return A[1] < B[1] ? true : false;
}

int solution(vector<vector<int>> routes)
{
    int answer = 0;

    sort(routes.begin(), routes.end(), Compare);

    int Camera = -30001;
         
    for (auto Route : routes)
    {
        int In = Route[0];
        int Out = Route[1];

        if (Camera < In)
        {
            Camera = Out;
            answer++;
        }
    }

    return answer;
}