#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	bool state = false;
	while(true){
		string s; cin >> s;
		string res = "";
		if (s[0] == '#') return 0;
		for (int i = 0; i < s.size(); i++){
			if (state) {
				cout << s[i];
				continue;
			}
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
				cout << s[i];
				state = true;
			}
			else res += s[i];
		}
		cout << res + "ay" << '\n';
		state = false;
	}
}