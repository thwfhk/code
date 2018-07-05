#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n, l[N], r[N];
int st[N], top;
ll a[N];

void init() {
	for(int i=1; i<=n; i++) {
		int le = i;
		while(top && a[st[top]] >= a[i]) {
			le = l[st[top]];
			r[st[top]] = i-1;
			top--;
		}
		st[++top] = i;
		l[i] = le;
	}
	while(top) r[st[top--]] = n;
}

ll b[N];
void add(int l, int r, ll v) {
	if(l > r) return;
	b[l] += v; b[l+1] -= v;
	b[r+1] -= v; b[r+2] += v;
}
void add_ap(int l, int r, ll a0, ll d) {
	if(l > r) return;
	ll n = r-l+1;
	b[l] += a0;
	b[l+1] += d-a0;
	b[r+1] -= a0 + n*d;
	b[r+2] += a0 + (n-1)*d;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	init();

	//for(int i=1; i<=n; i++) printf("l r %d  %d %d\n", i, l[i], r[i]);
	for(int i=1; i<=n; i++) l[i] = i-l[i], r[i] = r[i]-i;

	for(int i=1; i<=n; i++) {
		int d = min(l[i]+1, r[i]+1), len = r[i]+l[i]+2;
		add(d+1, len-d-1, d*a[i]);

		add_ap(1, min(len/2, d), a[i], a[i]);

		int k0 = max(len-d, len/2 + 1);
		add_ap(k0, len-1, (len-k0) * a[i], -a[i]);

	}
	for(int i=2; i<=n; i++) b[i] += b[i-1];
	for(int i=2; i<=n; i++) b[i] += b[i-1];

	int m;
	cin >> m;
	for(int i=1; i<=m; i++) {
		int k;
		cin >> k;
		double ans = (double) b[k] / (n-k+1);
		printf("%.9f\n", ans);
	}
}
