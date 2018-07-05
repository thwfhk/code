#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n;
struct meow {
	int x, y;
	bool operator < (const meow &r) const {
		return x == r.x ? y < r.y : x < r.x;
	}
} a[N];
inline bool cmp_x(meow a, meow b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}
inline bool cmp_y(meow &a, meow &b) {
	return a.y == b.y ? a.x < b.x : a.y < b.y;
}

ll ans;
inline ll cal(ll n) {return n * (n-1) / 2;}

int main() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i].x >> a[i].y;

	sort(a+1, a+1+n, cmp_x);
	//sort(a+1, a+1+n);
	for(int i=1; i<=n; i++) {
		int cnt = 1;
		while(i<n && a[i].x == a[i+1].x) cnt++, i++;
		ans += cal(cnt);
	}

	sort(a+1, a+1+n, cmp_y);
	for(int i=1; i<=n; i++) {
		int cnt = 1;
		while(i<n && a[i].y == a[i+1].y) cnt++, i++;
		ans += cal(cnt);
	}
	for(int i=1; i<=n; i++) {
		int cnt = 1;
		while(i<n && a[i].x == a[i+1].x && a[i].y == a[i+1].y) cnt++, i++;
		ans -= cal(cnt);
	}
	cout << ans;
}
