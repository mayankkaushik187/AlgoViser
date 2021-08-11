#include <bits/stdc++.h>
using namespace std;

int keypadhelp(int num, string output[], string keypad[])
{
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }

    int smallOutputSize = keypadhelp(num / 10, output, keypad);

    string copy[10000];
    for (int k = 0; k < smallOutputSize; k++)
    {
        copy[k] = output[k];
    }
    string xtrString = keypad[num % 10];
    int k = 0;
    for (int i = 0; i < smallOutputSize; i++)
    {
        for (int j = 0; j < xtrString.size(); j++)
        {
            output[k] = copy[i] + xtrString[j];
            k++;
        }
    }

    return k;
}

int keypad(int num, string output[])
{
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string keypad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return keypadhelp(num, output, keypad);
}
