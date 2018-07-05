#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5+5, P = 1e9+7;

int n, m, fa[N], u, v;
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
int ns[N], ms[N];
int main() {
	//freopen("in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(); cout.tie();
	cin >> n >> m;
	for(int i=1; i<=n; i++) fa[i] = i, ns[i] = 1;
	for(int i=1; i<=m; i++) {
		cin >> u >> v;
		u = find(u); v = find(v);
		if(u != v) fa[v] = u, ns[u] += ns[v], ms[u] += ms[v] + 1;
		else ms[u]++;
	}
	long long ans = 1;
	for(int i=1; i<=n; i++) if(i == fa[i]) {
		if(ms[i] == ns[i]) ans = (ans * 2) %P;
		else if(ms[i] == ns[i]-1) ans = (ans * ns[i]) %P;
		else {ans = 0; break;}
	}
	cout << ans;
}
