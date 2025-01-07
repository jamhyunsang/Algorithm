#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int Division = s / n;
    int Remainder = s % n;

    if (Division > 0)
    {
        for (int count = n; count > 0; count--)
        {
            if (Remainder >= count)
                answer.push_back(Division + 1);
            else
                answer.push_back(Division);
        }
    }
    else
    {
        answer.push_back(-1);
    }
    
    return answer;
}