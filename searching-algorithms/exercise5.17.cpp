#include <iostream>

using namespace std;

void fillArrays(int A[], string B[])
{
    for (int i = 0; i < 12; i++)
        cin >> A[i] >> B[i];
}

string findEmail(int num, int A[], string B[])
{
    for (int i = 0; i < 12; i++)
        if (A[i] == num)
            return B[i];
    return "-1";
}

int main()
{
    int AM[12];
    string emails[12];
    fillArrays(AM, emails);
    int num;
    cin >> num;
    cout << findEmail(num, AM, emails);
    return 0;
}
