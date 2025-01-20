#include<iostream>
using namespace std;
int main (){

// *             * 
// * *         * *
// * * *     * * *
// * * * * * * * *
// * * *     * * *
// * *         * *
// *             *

    int n=4;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        for (int j = i; j < n; j++)
        {
            cout << "  ";
        }
        for (int j = i; j < n; j++)
        {
            cout<<"  ";
        }
        
        for (int j = 1; j <=i; j++)
        {
            cout << "* ";
        }
         cout << endl;
    }
    // 
    int s=4;
    for (int i = 1; i <= s; i++)
    {
        for (int j = i; j <= s; j++)
        {
            cout << "* ";
        }

        for (int j = 1; j <i; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j < i; j++)
        {
            cout<<"  ";
        }
        
        for (int j = i; j <=s; j++)
        {
            cout << "* ";
        }
         cout << endl;
    }
}