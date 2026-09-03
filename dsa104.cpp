// permutation of string (return true if one of s1's permutations is the substring of s2)

#include <iostream>
#include <string>
using namespace std;
class Solution
{
private:
    bool checkEqual(int count1[], int count2[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (count1[i] != count2[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        // character count array for s1
        int count[26] = {0};

        for (int i = 0; i < s1.length(); i++)
        {
            int index = s1[i] - 'a';
            count[index]++;
        }
        // traverse s2 string in window of size s1 length and compare

        int i =0;
        int windowSize = s1.length();
        int count2[26] = {0};

        // running for first window

        while (i < windowSize)
        {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        if (checkEqual(count, count2))
            return 1;

        // window process
        while (i < s2.length())
        {
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            count2[index]--;

            i++;

            if (checkEqual(count, count2))
                return 1;
        }
        return 0;
    }
};

int main()
{
    string s1, s2;
    cout << "Enter two strings: ";
    cin >> s1 >> s2;

    Solution sol;
    if (sol.checkInclusion(s1, s2))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}