#include <bits/bits-stdc++.h>
using namespace std;

string replaceWords(vector<string> &dictionary, string sentence)
{
    istringstream inputStringStream;
    inputStringStream.str(sentence);

    vector<string> temp;
    string result, word;
    set<string> st(dictionary.begin(), dictionary.end());
    do
    {
        inputStringStream >> word;
        temp.push_back(word);
    } while (inputStringStream.good());

    for (string str : temp)
    {
        int i = 0;

        while (i <= str.length())
        {
            string stringQuery = str.substr(0, i);

            if (st.find(stringQuery) != st.end())
            {
                result += stringQuery + " ";
                break;
            }

            if (i == str.length())
            {
                result += stringQuery + " ";
            }
            i++;
        }
    }
    result.pop_back();
    return result;
}

#pragma GCC optimize("O3")

class Solution
{
public:
    // dictionary entries indexed by length
    typedef size_t Length;
    typedef map<Length, unordered_set<string_view>> Index;

    // If the word starts with one of the entries in the index, returns the size
    // of the root word, otherwise returns 0.
    inline size_t contains_root(Index &index, string_view const &word)
    {
        auto const &last = index.upper_bound(word.size());
        for (auto iter = index.begin(); iter != last; iter++)
        {
            auto const &length = iter->first;
            auto const &entries = iter->second;
            auto const &prefix = word.substr(0, length);
            if (entries.contains(prefix))
            {
                return length;
            }
        }
        return 0;
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        // build map of root word length -> set of all root words of that length
        Index index;
        for (auto const &entry : dictionary)
        {
            index[entry.size()].insert(entry);
        }
        // work forward through the sentence word by word. copying stuff back
        // whenever we enounter a root
        string::iterator read = sentence.begin();
        string::iterator write = sentence.begin();
        string::iterator next_space = sentence.begin();
        while (true)
        {
            auto next_space = find(read, sentence.end(), ' ');
            string_view word(read, next_space);
            auto root_length = contains_root(index, word);
            // if (read != write) {
            copy(read, next_space, write);
            //}
            if (root_length > 0)
            {
                write += root_length;
            }
            else
            {
                write += word.size();
            }
            *write++ = ' ';
            read = next_space + 1;
            if (next_space == sentence.end())
            {
                break;
            }
        }
        if (write != sentence.end())
        {
            sentence.erase(write - 1, sentence.end());
        }
        return sentence;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main()
{

    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    cout << replaceWords(dictionary, sentence);

    return 0;
}