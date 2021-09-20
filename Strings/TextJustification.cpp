#include <bits/stdc++.h>
using namespace std;

string justify(string temp, int maxWidth, bool isLastLine)
{
    if (temp.size() == maxWidth)
    {
        return temp;
    }
    int spacesInString = 0;
    for (auto x : temp)
    {
        if (x == ' ')
        {
            spacesInString++;
        }
    }
    int spacesToInsert = maxWidth - temp.size();
    if (spacesInString == 0 || isLastLine)
    {
        for (int i = 1; i <= spacesToInsert; i++)
        {
            temp += " ";
        }
        return temp;
    }
    int spaceInEachSlot = spacesToInsert / spacesInString;
    int leftOverSpace = spacesToInsert % spacesInString;

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == ' ' && (spaceInEachSlot > 0 || leftOverSpace > 0))
        {
            int noOfSpaces = spaceInEachSlot + (leftOverSpace-- > 0 ? 1 : 0);
            temp.insert(i, noOfSpaces, ' ');
            i += noOfSpaces;
        }
    }
    return temp;
}

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> res;
    string temp = words[0];
    int n = words.size();
    for (int i = 1; i < n; i++)
    {
        if (temp.size() + words[i].size() + 1 <= maxWidth)
        {
            temp += " " + words[i];
        }
        else
        {
            temp = justify(temp, maxWidth, 0);
            res.push_back(temp);
            temp = words[i];
        }
    }

    temp = justify(temp, maxWidth, 1);
    res.push_back(temp);
    return res;
}