#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;

    int changeCount = 0;
    int removeCount = 0;

    while (s != "1")
    {
        changeCount++;
        removeCount += count(s.begin(), s.end(), '0');
        int length = count(s.begin(), s.end(), '1');

        bitset<150000> bit(length);
        string bitstring = bit.to_string();
        int startidx = bitstring.find('1');
        s = bitstring.substr(startidx);
    }

    answer = { changeCount, removeCount };

    return answer;
}