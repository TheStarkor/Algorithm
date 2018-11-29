#include <iostream> 
using namespace std;

int main(){
    int x, y, day;
    int m[12] = {0,31,28,31,30,31,30,31,31,30,31,30};
    cin >> x >> y;
    for (int i=0;i<x;i++){
        y = y+m[i];
    }
    if (y%7 == 1) cout << "MON";
    else if (y%7 == 2) cout << "TUE";
    else if (y%7 == 3) cout << "WED";
    else if (y%7 == 4) cout << "THU";
    else if (y%7 == 5) cout << "FRI";
    else if (y%7 == 6) cout << "SAT";
    else if (y%7 == 0) cout << "SUN";
}