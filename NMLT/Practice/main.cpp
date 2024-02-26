/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    /*int sumDigit;
    cout << "Nhap chu so tong: ";
    cin >> sumDigit;
    int a = 0;
    while(sumDigit - a <= sumDigit && sumDigit - a >= 0) {
        int b = sumDigit - a;
        cout << sumDigit << a << b << endl;
        a++;
    }*/
    
    /*int mirNum;
    cout << "Nhap so: ";
    cin >> mirNum;
    int k = 0;
    int m = 1;
    int temp = mirNum;
    while(temp != 0) {
        int i = temp % 10;
        k = k*10 + i;
        temp /= 10;
        cout << k << endl;
    }
    if (k == mirNum) {
        cout << "Mirrored number";
    } else {
        cout << "Not mirrored number";
    }*/
    
    
    int soCP=0;
    cout<<"Nhap di ba: ";
    cin>>soCP;
    bool soAy=0;
    for(int i=1;i<=soCP/2;i++)
    {
        if(i*i==soCP)
        {
            soAy=1;
        }
    }
    if(soAy)
        cout<<"So Chính Phương."<<endl;
    else
        cout<<"Khum phải số chính phương."<<endl;

    return 0;
}
