#include <iostream>
using namespace std;

int main() {
    int n = 5; 

    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    
}

// output
//     *
//    **
//   ***
//  ****
// *****