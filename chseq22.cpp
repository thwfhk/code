#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5+5, P = 1e9+7;

int n, m, fa[N], cnt;
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
ll Pow(ll a, int b) {
	ll ans = 1;
	for(; b; b >>= 1, a = a*a %P)
		if(b & 1) ans = ans*a %P;
	return ans;
}
int main() {
	//freopen("in", "r", stdin);
	cin >> n >> m;
	for(int i=1; i<=n; i++) fa[i] = i;
	for(int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		y++;
		x = find(x); 
		y = find(y);
		if(x != y) cnt++, fa[y] = x;
	}
	cout << Pow(2, cnt);
}
