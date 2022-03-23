#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int menu()
{
    cout << "Options: " << endl;
    cout << "1. Decimal to binary" << endl;
    cout << "2. Binary to decimal" << endl;
    cout << "3. Complementation of 2" << endl;
    cout << "4. Addition of 2 binaries" << endl;
    cout << "5. Deduction of 2 binaries" << endl;
    cout << "6. Exit" << endl;

    int option;

    cout << endl;
    cout << "Type the option: ";
    cin >> option;

    while (option < 1 || option > 6)
    {
        cout << "Wrong input, try again: ";
        cin >> option;
    }

    return option;
}

bool checkBinary(string binary)
{
    if (binary.size() > 8)
    {
        return false;
    }

    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i] < '0' || binary[i] > '1')
        {
            return false;
        }
    }

    return true;
}

string inputBinary(string binary)
{
    cout << "Type a binary number: ";

    cin >> binary;
    while (!checkBinary(binary))
    {
        cout << "Wrong input, try again: ";
        cin >> binary;
    }

    return binary;
}

string fillBinary(string binary)
{
    string filledBinary;
    filledBinary.clear();

    for (int i = 0; i < 8 - binary.size(); i++)
    {
        filledBinary = filledBinary + '0';
    }

    int j = 0;
    for (int i = 8 - binary.size(); i < 8; i++)
    {
        filledBinary = filledBinary + binary[j];
        j++;
    }

    return filledBinary;
}

string reverseBinary(string binary)
{
    string reversedBinary;
    reversedBinary.clear();

    for (int i = binary.size() - 1; i >= 0; i--)
    {
        reversedBinary = reversedBinary + binary[i];
    }

    return reversedBinary;
}

string convertDecimal(int decimal)
{
    string binary;
    binary.clear();

    bool flag = false;
    while (decimal / 2 >= 0 && !flag)
    {
        if (decimal / 2 == 0)
        {
            flag = true;
        }

        char temp = '0' + decimal % 2; //Converting integer data type to character.
        binary = binary + temp;
        decimal = decimal / 2;
    }

    return reverseBinary(binary);
}

int convertBinary(string binary)
{
    int pos = 0;
    int decimal = 0;

    for (int i = binary.size() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal = decimal + pow(2, pos);
        }
        pos++;
    }

    return decimal;
}

string complementBinary(string binary)
{
    int pos = binary.size() - 1;
    while (binary[pos] != '1')
    {
        pos--;
    }

    for (int i = pos - 1; i >= 0; i--)
    {
        if (binary[i] == '0')
        {
            binary[i] = '1';
        }
        else
        {
            binary[i] = '0';
        }
    }

    return binary;
}

string addBinaries(string binaryA, string binaryB)
{
    string sumBinary;
    sumBinary.clear();

    bool mustAdd = false;
    for (int i = 7; i >=0; i--)
    {
        if (binaryA[i] == '0' && binaryB[i] == '0')
        {
            if (!mustAdd)
            {
                sumBinary = sumBinary + '0';
            }
            else
            {
                sumBinary = sumBinary + '1';
                mustAdd = false;
            }
        }
        else if ((binaryA[i] == '0' && binaryB[i] == '1') || (binaryA[i] == '1' && binaryB[i] == '0'))
        {
            if (!mustAdd)
            {
                sumBinary = sumBinary + '1';
            }
            else
            {
                sumBinary = sumBinary + '0';
            }
        }
        else
        {
            if (!mustAdd)
            {
                sumBinary = sumBinary + '0';
                mustAdd = true;
            }
            else
            {
                sumBinary = sumBinary + '1';
            }
        }
    }

    return reverseBinary(sumBinary);
}

int main()
{
    int option = menu();
    while (option != 6)
    {
        int decimal;
        string binary;
        string binaryA;
        string binaryB;

        switch (option)
        {
            case 1:
                cout << "Type a decimal number: ";
                cin >> decimal;

                cout << "Converted number: ";
                cout << convertDecimal(decimal) << endl;
                break;

            case 2:
                binary = inputBinary(binary);

                cout << "Converted number: ";
                cout << convertBinary(binary) << endl;
                break;

            case 3:
                binary = inputBinary(binary);

                cout << "Complemented number: ";
                cout << complementBinary(binary) << endl;
                break;

            case 4:
                //We could have just converted both binaries to decimals and converted
                //the sum to a binary, but let's be honest, that's what pussies do.
                binaryA = inputBinary(binaryA);
                binaryB = inputBinary(binaryB);

                if (binaryA.size() < 8)
                {
                    binaryA = fillBinary(binaryA);
                }
                if (binaryB.size() < 8)
                {
                    binaryB = fillBinary(binaryB);
                }

                cout << "Sum of binaries: ";
                cout << addBinaries(binaryA, binaryB) << endl;
                break;

            case 5:
                binaryA = inputBinary(binaryA);
                binaryB = inputBinary(binaryB);

                if (binaryA.size() < 8)
                {
                    binaryA = fillBinary(binaryA);
                }
                if (binaryB.size() < 8)
                {
                    binaryB = fillBinary(binaryB);
                }


                cout << "Difference of binaries: ";
                if (convertBinary(binaryA) >= convertBinary(binaryB))
                {
                    binaryB = complementBinary(binaryB);
                    cout << addBinaries(binaryA, binaryB) << endl;
                }
                else
                {
                    binaryB = complementBinary(binaryB);
                    cout << '-' << complementBinary(addBinaries(binaryA, binaryB)) << endl;
                }
                break;
        }
        cout << endl;
        option = menu();
    }

    return 0;
}
