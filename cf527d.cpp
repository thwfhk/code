#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 2e5+5;

int n, x, w;
struct meow {
	int l, r;
	bool operator < (const meow &a) const {
		return r < a.r || (r == a.r && l < a.l);
	}
} a[N];
int main() {
	//freopen("in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(); cout.tie();
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> x >> w;
		a[i].l = max(x-w, 0); a[i].r = x+w;
	}
	sort(a+1, a+1+n);
	//for(int i=1; i<=n; i++) printf("i %d [%d, %d]\n", i, a[i].l, a[i].r);

	int now = 0, ans = 0;
	for(int i=1; i<=n; i++) {
		while(i < n && a[i].r == a[i+1].r) i++;
		if(now <= a[i].l) now = a[i].r, ans++;
	}
	cout << ans;
}
