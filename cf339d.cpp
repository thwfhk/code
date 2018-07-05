#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lc x<<1
#define rc x<<1|1
#define mid ((l+r) >> 1)
#define lson lc, l, mid
#define rson rc, mid+1, r
const int N = (1<<17) + 5;

int n, m, a[N];
struct meow {
	int v, k;
} t[N<<2];
inline void merge(int x) {
	if(t[x].k == 0) t[x].v = t[lc].v | t[rc].v;
	else t[x].v = t[lc].v ^ t[rc].v;
}
void build(int x, int l, int r) {
	if(l == r) cin >> t[x].v, t[x].k = 1;
	else {
		build(lson); 
		build(rson);
		t[x].k = t[lc].k ^ 1;
		merge(x);
	}
}
void cha(int x, int l, int r, int p, int v) {
	if(l == r) t[x].v = v;
	else {
		if(p <= mid) cha(lson, p ,v);
		if(mid < p) cha(rson, p, v);
		merge(x);
	}
}
int main() {
	//freopen("in", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	build(1, 1, 1<<n);
	while(m--) {
		int p, b;
		cin >> p >> b;
		cha(1, 1, 1<<n, p, b);
		cout << t[1].v << endl;
	}
}
