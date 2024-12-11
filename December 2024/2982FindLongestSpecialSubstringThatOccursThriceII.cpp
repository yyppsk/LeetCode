#include <bits/bits-stdc++.h>
using namespace std;
static uint32_t topLengths[26][3]; // Top three lengths for each character

static int maximumLength(const string &input)
{
    const char *const charArray = input.c_str();
    const uint32_t stringLength = input.length();
    uint32_t substringStart = 0;
    char previousChar = *charArray;

    for (uint32_t currentIndex = 1; currentIndex < stringLength;
         currentIndex++)
    {
        const char currentChar = charArray[currentIndex];
        if (currentChar != previousChar)
        {
            uint32_t currentSubstringLength = currentIndex - substringStart;
            auto &currentCharLengths = topLengths[previousChar - 'a'];

            if (currentSubstringLength > currentCharLengths[0])
                swap(currentSubstringLength, currentCharLengths[0]);
            if (currentSubstringLength > currentCharLengths[1])
                swap(currentSubstringLength, currentCharLengths[1]);
            if (currentSubstringLength > currentCharLengths[2])
                swap(currentSubstringLength, currentCharLengths[2]);

            substringStart = currentIndex;
            previousChar = currentChar;
        }
    }

    // Handle the last substring
    {
        uint32_t lastSubstringLength = stringLength - substringStart;
        auto &lastCharLengths = topLengths[previousChar - 'a'];

        if (lastSubstringLength > lastCharLengths[0])
            swap(lastSubstringLength, lastCharLengths[0]);
        if (lastSubstringLength > lastCharLengths[1])
            swap(lastSubstringLength, lastCharLengths[1]);
        if (lastSubstringLength > lastCharLengths[2])
            swap(lastSubstringLength, lastCharLengths[2]);
    }

    uint32_t maxLength = 0;
    for (auto &charLengths : topLengths)
    {
        if (!charLengths[0])
            continue;

        const uint32_t candidateLength =
            charLengths[1] == charLengths[0]
                ? charLengths[0] - (charLengths[2] < charLengths[0])
                : max(charLengths[1] + 2u, charLengths[0]) - 2u;

        maxLength = max(maxLength, candidateLength);

        // Reset lengths for this character
        charLengths[0] = charLengths[1] = charLengths[2] = 0;
    }

    return maxLength ? static_cast<int>(maxLength) : -1;
}
int main()
{
    return 0;
}