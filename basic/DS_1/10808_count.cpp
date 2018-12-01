#include <iostream>
#include <string>
using namespace std;
// '\n' ""

int main(){
	int n[26] = {0,};
	string s;
	cin >> s;
	
	for(int i=0;i<s.size();i++) n[int(s[i]-97)] = n[int(s[i])-97] + 1;
	for(int i=0;i<26;i++) cout << n[i] << " ";
}