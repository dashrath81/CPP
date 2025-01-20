#include <iostream>
using namespace std;
int main()
{

    int n = 1;

    for (int i = 5; i >= n; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout <<j;
        }
        cout<<endl;
    }
}

// output
// 12345
// 1234
// 123
// 12
// 1