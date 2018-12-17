#include <iostream>
using namespace std;
int d[2][100001];

int max(int n){
	int max = -10000, y = 0, x = 0;
	for (int i=0;i<2;i++){
		for (int j=0;j<n;j++){
			if (max < d[i][j]){
				max = d[i][j];
				y = i;
				x = j;
			} 
		}
	}
	if (y==0){
		d[y][x] = -1;
		d[y+1][x] = -1;
		if (x==0) d[y][x+1] = -1;
		else if (x==(n-1)) d[y][x-1] = -1;
		else{
			d[y][x-1] = -1;
			d[y][x+1] = -1;
		}
	}
	else {
		d[y][x] = -1;
		d[y-1][x] = -1;
		if (x==0) d[y][x+1] = -1;
		else if (x==(n-1)) d[y][x-1] = -1;
		else{
			d[y][x-1] = -1;
			d[y][x+1] = -1;
		}
	}
	return max;
}

int main(){
	int cnt, n, re = 0, ans = 0;
	cin >> cnt;
	while(cnt--){
		cin >> n;
		for (int i=0;i<2;i++){
			for (int j=0;j<n;j++){
				cin >> d[i][j];
			}
		}
		while (re != -1){
			re = max(n);
			ans += re;
			// cout << "re : " << re << '\n';
		}
		ans++;
		cout << ans << '\n';
		ans = 0;
		re = 0;
	}
}