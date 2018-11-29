#include <iostream> 
using namespace std;

int main(){
    int cnt, a, b, n=1;
    cin >> cnt;
    while(cnt--){
        cin >> a >> b;
        cout << "Case #" << n++ << ": " << a << " + " << b << " = " << a+b << '\n';
    }
}