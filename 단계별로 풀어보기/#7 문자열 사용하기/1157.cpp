#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main(){
    int a[26] = {0};
    string s; cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i] >= 'a') a[s[i]-'a']++;
        else a[s[i]-'A']++;
    }
    int max = -1;
    for(int i=0;i<26;i++){
        if(a[i] > max) max = a[i];
    }
    int count = 0, ans;
    for(int i=0;i<26;i++){
        if(a[i] == max){
            count++;
            ans = i;
        }
    }
    if(count > 1) cout << "?";
    else printf("%c", ans + 'A');
}
