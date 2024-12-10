#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<string> m_words;
queue<pair<string, int>> m_ChangeWord;
bool m_Visit[50] = { false };
string m_Target;

bool CheckString(string begin, string target)
{
    int DifferentCount = 0;

    for (int count = 0; count < begin.size(); count++)
    {
        if (begin[count] != target[count])
            DifferentCount++;
    }

    return DifferentCount == 1;
}

int BFS(string begin)
{
    m_ChangeWord.push({ begin, 0 });
    while (!m_ChangeWord.empty())
    {
        auto ChangeWord = m_ChangeWord.front();
        m_ChangeWord.pop();

        if (ChangeWord.first == m_Target)
            return ChangeWord.second;

        for (int count = 0; count < m_words.size(); count++)
        {
            if (m_Visit[count])
                continue;

            string word = ChangeWord.first;
            if (CheckString(word, m_words[count]))
            {
                m_ChangeWord.push({ m_words[count], ChangeWord.second + 1 });
                m_Visit[count] = true;
            }
        }
    }

    return 0;
}


int solution(string begin, string target, vector<string> words)
{
    int answer = 0;

    if (find(words.begin(), words.end(), target) == words.end())
        return 0;

    m_words = words;
    m_Target = target;

    answer = BFS(begin);

    return answer;
}