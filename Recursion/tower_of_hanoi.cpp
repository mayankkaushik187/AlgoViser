#include <iostream>
using namespace std;

void TOH(int n, char A, char B, char C)
{
    //base case
    if (n == 1)
    {
        cout << "Move " << n << " from " << A << " to " << C << endl;
        return;
    }
    //recursive case

    TOH(n - 1, A, C, B);
    cout << "Move " << n << " from " << A << " to " << C << endl;
    ;
    TOH(n - 1, B, A, C);
}

int main()
{
    char A = 'A';
    char B = 'B';
    char C = 'C';
    int n = 2;
    TOH(n, A, B, C);
}