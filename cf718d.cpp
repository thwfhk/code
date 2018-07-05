#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int N = 1e5+5;

int n, m;
vector<int> e[N];
map<vector<int>, int> mp;
map<int, int> f[N];
set<int> s;

int dp(int u, int fa) {
	if(f[u][fa]) return f[u][fa];
	vector<int> cur;
	for(int i=0; i<e[u].size(); i++) 
		if(e[u][i] != fa) cur.push_back(dp(e[u][i], u));
	sort(cur.begin(), cur.end());
	if(!mp[cur]) mp[cur] = ++m;
	return f[u][fa] = mp[cur];
}
int main() {
	//freopen("in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	cin >> n;
	for(int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1; i<=n; i++) if(e[i].size() < 4) s.insert(dp(i, 0));
	cout << s.size();
}
