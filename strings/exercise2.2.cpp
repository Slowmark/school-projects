#include <string>
#include <iostream>

using namespace std;

int main()
{
    int max_size = 0;
    string name, max_name;
    for (int i = 0; i < 10; i++)
    {
        cin >> name;
        if (name.size() > max_size)
        {
            max_name = name;
            max_size = name.size();
        }
    }
    cout << max_name;
    return 0;
}
