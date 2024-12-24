#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> SplitAndConvert(string& str, char delimiter)
{
    vector<int> data;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter))
    {
        data.push_back(stoi(token));
    }

    return data;
}

string solution(string s)
{
    string answer = "";

    vector<int> split = SplitAndConvert(s, ' ');

    sort(split.begin(), split.end());

    answer = to_string(split.front()) + " " + to_string(split.back());

    return answer;
}