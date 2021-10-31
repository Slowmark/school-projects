#include <string>
#include <iostream>

using namespace std;

int main()
{
    string st;
    cin >> st;
    char temp = st[st.size()-1];
    for (int i = st.size() - 1; i > 0; i--)
        st[i] = st[i-1];
    st[0] = temp;
    cout << st;
    return 0;
}
