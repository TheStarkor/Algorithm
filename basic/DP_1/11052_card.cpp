#include <iostream>
using namespace std;
int d[1001] = {0};
int p[10001] = {0};

int main(){
	int n, tmp;
	cin >> n;
	for (int i=1;i<=n;i++){
		int val;
		cin >> val;
		p[i] = val;
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j>=1;j--){
	 		tmp = p[j] + d[i-j];
	 		if (tmp > d[i]) d[i] = tmp;
	 	}
	} // var control.. dont use n;;
	cout << d[n];
}