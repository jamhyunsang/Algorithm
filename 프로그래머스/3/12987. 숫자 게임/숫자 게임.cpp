#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int BIndex = 0;
    for (int ACount = 0; ACount < A.size(); ACount++)
    {
        if (A[ACount] > B.back())
            break;
        
        for (int BCount = BIndex; BCount < B.size(); BCount++)
        {
            if (A[ACount] < B[BCount])
            {
                BIndex = BCount + 1;
                answer++;
                break;
            }
        }
    }

    return answer;
}