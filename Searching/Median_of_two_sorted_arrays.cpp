#include <bits/stdc++.h>
using namespace std;

int getMed(int a1[], int a2[], int n1, int n2)
{
    int m1 = -1;
    int m2 = -1;
    int i = 0;
    int count = 0;
    int j = 0;

    if ((n1 + n2) % 2 == 0)
    {
        //Something

        for (count = 0; count <= (n1 + n2) / 2; count++)
        {
            m1 = m2;
            if (i != n1 && j != n2)
            {
                if (a1[i] < a2[j])
                    m2 = a1[i++];
                else
                    m2 = a2[j++];
            }
            else if (i < n1)
            {
                m2 = a1[i++];
            }
            else if (j < n2)
            {
                m2 = a2[j++];
            }
        }
        return m1 + m2 >> 1;
    }
    else
    {
        //something
        for (count = 0; count <= (n1 + n2) / 2; count++)
        {
            if (i != n1 && j != n2)
            {
                if (a1[i] < a2[j])
                    m2 = a1[i++];
                else
                    m2 = a2[j++];
            }
            else if (i < n1)
            {
                m2 = a1[i++];
            }
            else if (j < n2)
            {
                m2 = a2[j++];
            }
        }
        return m2;
    }
}

int main()
{

    int a1[] = {10, 20, 30, 40, 50}, n1 = 5, a2[] = {5, 15, 25, 35, 45}, n2 = 5;

    cout << getMed(a1, a2, n1, n2);

    return 0;
}