#include <fstream>
#include <iostream>

using namespace std;

void Temperature(float arr[])
{
    ifstream fin("temp.txt");
    for (int i = 0; i < 365; i++)
        fin >> arr[i];
    fin.close();
}
void MaxT(float arr[])
{
    float max_temp = -100;
    ofstream fout("max.txt");
    for (int i = 0; i < 365; i++)
        if (arr[i] > max_temp)
            max_temp = arr[i];
    fout << max_temp << endl;
    for (int i = 0; i < 365; i++)
        if (arr[i] == max_temp)
            fout << i+1 << endl; //Ο πίνακας ξεκινά από τη θέση 0 αλλά οι μέρες από τη θέση 1.
    fout.close();
}
void Avg5(float arr[])
{
    ofstream fout("average.txt");
    for (int i = 0; i < 365; i += 5)
    {
        float sum = 0;
        for (int j = i; j < i+5; j++)
            sum += arr[j];
        fout << sum / 5 << endl;
    }
    fout.close();
}
int main()
{
    float T[365];
    Temperature(T);
    MaxT(T);
    Avg5(T);
    return 0;
}
