#include <iostream>
#include <cmath>
using namespace std;
int main()
{

    int sum = 0;
    int i = 1;
    while (sum <= 1000) {
        sum += i;
        if (sum > 1000) break;
        i++;
    }

    cout << "Ket qua: " << i;
}