#include <string>
#include <iostream>

using namespace std;

int main()
{
    int pos;
    bool flag = false;
    char ch;
    string st;
    cin >> st >> ch;
    for (int i = 0; i < st.size(); i++)
        if (st[i] == ch && !flag)
        {
            pos = i;
            flag = true;
        }
    if (flag)
        cout << pos;
    else
        cout << -1;
    return 0;
}
