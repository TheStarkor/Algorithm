#include <iostream> 
#include <string>
using namespace std;

string check(string s){
    int cnt=0;
    for (int i=0;i<s.size();i++){
        if (s[i] == '(') cnt++;
        else if (s[i] == ')'){
            if (cnt == 0) return "NO";
            else{
                cnt--;
            }
        }
        if(cnt == 0) return "YES";
    }
}

int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        cout << check(s) << '\n';
    }
}