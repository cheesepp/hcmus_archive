#include<iostream>
using namespace std;
int main()
{
    int i = 2;
    while (i <= 9) {
        for (int j = 1; j <= 10; j++) {
            cout << i << " * " << j << " = " << j * i << endl;
        }
        cout << endl;
        i++;
    }
    return 0;
}