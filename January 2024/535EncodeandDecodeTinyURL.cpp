#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    unordered_map<string, string> codeDataBase, urlDataBase;
    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        if (urlDataBase.find(longUrl) != urlDataBase.end())
        {
            return urlDataBase[longUrl];
        }
        string code = buildCode();
        while (codeDataBase.find(code) != codeDataBase.end())
        {
            code = buildCode();
        }
        codeDataBase[code] = longUrl;
        urlDataBase[longUrl] = code;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return codeDataBase[shortUrl];
    }

private:
    string buildCode()
    {
        string code = "";
        for (int i = 0; i < 6; i++)
            code += chars[rand() % 62];
        return "http://tinyurl.com/" + code;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
int main()
{
    return 0;
}