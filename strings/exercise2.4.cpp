#include <string>
#include <iostream>

using namespace std;

int main()
{
    string st;
    cin >> st;
    for (int i = 0; i < st.size(); i++)
        if (st[i] == 'a')
            st[i] = 'b';
    cout << st;
    return 0;
}
