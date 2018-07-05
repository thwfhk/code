#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

#define lc x<<1
#define rc x<<1|1
#define mid ((l+r) >> 1)
#define lson lc, l, mid
#define rson rc, mid+1, r
const int N = 1e5+5;

struct meow {
	ll add, sum;
} t[N<<2];
inline void paint(int x, int l, int r, int v) {
	t[x].add += v;
	t[x].sum += v * (r-l+1);
}
inline void push_down(int x, int l, int r) {
	if(t[x].add) {
		paint(lson, t[x].add);
		paint(rson, t[x].add);
		t[x].add = 0;
	}
}
void build(int x, int l, int r) {
	if(l == r) cin >> t[x].sum;
	else {
		build(lson);
		build(rson);
		t[x].sum = t[lc].sum + t[rc].sum;
	}
}
void add(int x, int l, int r, int ql, int qr, ll v) {
	if(ql<=l && r<=qr) paint(x, l, r, v);
	else {
		push_down(x, l, r);
		if(ql <= mid) add(lson, ql, qr, v);
		if(mid < qr) add(rson, ql, qr, v);
		t[x].sum = t[lc].sum + t[rc].sum;
	}
}
ll que(int x, int l, int r, int ql, int qr) {
	if(ql<=l && r<=qr) return t[x].sum;
	else {
		push_down(x, l, r);
		ll ans = 0;
		if(ql <= mid) ans += que(lson, ql, qr);
		if(mid < qr) ans += que(rson, ql, qr);
		return ans;
	}
}
int n, m;
int main() {
	freopen("in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	cin >> n >> m;
	build(1, 1, n);
	int op, x, y, k;
	for(int i=1; i<=m; i++) {
		cin >> op >> x >> y;
		if(op == 1) cin >> k, add(1, 1, n, x, y, k);
		else cout << que(1, 1, n, x, y) << endl;
	}
}
