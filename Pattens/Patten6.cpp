#include<iostream>
using namespace std;
int main (){

    int n=5;

    for (int i = 1; i <=n; i++)
    {
            for (int j = 5; j >=i; j--)
            {
                cout << i;
            }
            cout <<endl;
            
    }
    
}
// output
// 11111
// 2222
// 333
// 44
// 5