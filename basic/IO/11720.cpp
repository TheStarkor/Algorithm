#include <iostream> 
#include <string>
using namespace std;

int main(){
    char tmp[10];
    while(scanf("%10s", tmp) == 1){
        cout << tmp << '\n';
    }
}