#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5+5;

int n, m, w, a[N], t[N];
bool check(int x) {
	int s = 0, cnt = m;
	for(int i=1; i<=n; i++) t[i] = a[i];
	for(int i=1; i<=n; i++) {
		s += t[i];
		while(s < x) {
			if(cnt == 0) return false;
			cnt--;
			s++;
			if(i+w <= n) t[i+w]--;
		}
	}
	return true;
}
int main() {
	cin >> n >> m >> w;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=n; i>=1; i--) a[i] -= a[i-1];
	int l = 1, r = 1e9 + 1e6, ans = 0;
	//printf("check %d\n", check(1)); return 0;
	while(l <= r) {
		int mid =  (l+r) >> 1;
		if(check(mid)) ans = max(ans, mid), l = mid+1;
		else r = mid-1;
	}
	cout << ans;
}
