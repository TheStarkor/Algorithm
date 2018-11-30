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
    }
    if(cnt == 0) return "YES";
    else return "NO";
}

int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        cout << check(s) << '\n';
    }
}