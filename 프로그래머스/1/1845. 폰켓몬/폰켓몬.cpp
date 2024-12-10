#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    unordered_set<int> hashSet(nums.begin(), nums.end());
    int KindCount = nums.size() / 2;

    answer = hashSet.size() >= KindCount ? KindCount : hashSet.size();

    return answer;
}