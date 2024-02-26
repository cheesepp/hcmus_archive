#include<iostream>
using namespace std;
int main()
{
    char ch;
    int i;
    cout << "Character\tASCII Value\n";
    int i = 0;
    while (i < 255)
    {
        ch = i;
        cout << ch << "\t|\t" << i << endl;
        i++;
    }
    cout << endl;
    return 0;
}