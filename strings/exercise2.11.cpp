#include <string>
#include <iostream>

using namespace std;

int main()
{
    string word, reversed;
    cin >> word;
    reversed.clear();
    for (int i = word.size() - 1; i >= 0; i--)
        reversed += word[i];
    if (reversed == word)
        cout << true;
    else
        cout << false;
    return 0;
}
