#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 2e5+5; 
inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while(c < '0' || c > '9') {if(c=='-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = x*10+c-'0'; c = getchar();}
	return x * f;
}

int n, fa[N], mp[N], m;
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
struct meow {
	int x, y, e;
} a[N];

int main() {
	freopen("in", "r", stdin);
	int T = read();
	while(T--) {
		m = 0;
		n = read();
		for(int i=1; i<=n; i++) {
			a[i].x = read(), a[i].y = read(), a[i].e = read();
			mp[++m] = a[i].x; mp[++m] = a[i].y;
		}
		sort(mp+1, mp+1+m); m = unique(mp+1, mp+1+m) - mp - 1;
		
		for(int i=1; i<=m; i++) fa[i] = i, fa[i+m] = i+m;
		int flag = 0;
		for(int i=1; i<=n; i++) {
			a[i].x = lower_bound(mp+1, mp+1+m, a[i].x) - mp;
			a[i].y = lower_bound(mp+1, mp+1+m, a[i].y) - mp;
			if(a[i].e == 1) {
				int x = find(a[i].x), y = find(a[i].y), x1 = find(a[i].x + m), y1 = find(a[i].y + m);
				if(x1 == y) {
					flag = 1;
					break;
				}
				fa[y] = x; fa[y1] = x1;
			} else {
				int x = find(a[i].x), y = find(a[i].y), x1 = find(a[i].x + m), y1 = find(a[i].y + m);
				if(x == y) {
					flag = 1; 
					break;
				}
				fa[x1] = y; fa[y1] = x;
			}
		}
		puts(flag ? "NO" : "YES");
	}
}
