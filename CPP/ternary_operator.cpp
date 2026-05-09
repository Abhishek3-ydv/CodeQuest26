#include <iostream>
using namespace std;
int main() {
    int a = 10, b = 20, c = 5;
    int min_val = (a < b) ? (a = c ? a : c) : (b < c ? b : c); 
    string res = min_val < 10 ? "Single Digit" : 10; 
    cout << "Min is: " << min_val << endl;
    int x = 5;
    cout << (x = 5 ? "Equal" : "Not Equal") 
    return 0;
}