#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
typedef unsigned long long ll;
const int N = 1e5+5;
ll B = 123;

int n, m;
string s;
string w[N];
ll su[N], ha[N], Pow[N];
int f[N];
map<int, int> mp;

inline ll Hash(string s) {
	ll ans = 0;
	reverse(s.begin(), s.end());
	for(int i=0; i<s.size(); i++) ans = (ans * B + tolower(s[i])); 
	return ans;
}
inline ll cal(int l, int r) {
	ll ans = su[r] -  su[l-1] * Pow[r-l+1];
	return ans;
}

int ans[N];

inline bool equ(int l, int r, string s2) {
	reverse(s2.begin(), s2.end());
	for(int i=l; i<=r; i++) if(s[i] != tolower(s2[i-l])) return false;
	return true;
}
int main() {
	//freopen("in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	cin >> n;
	cin >> s; s = " " + s;
	cin >> m;
	for(int i=1; i<=m; i++) {
		cin >> w[i];
		ha[i] = Hash(w[i]);
		mp[ha[i]] = i;
	}
	Pow[0] = 1;
	for(int i=1; i<=n; i++) Pow[i] = Pow[i-1] * B ;
	for(int i=1; i<=n; i++) su[i] = (su[i-1] * B + s[i]);

	f[0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) if(f[j-1]) {
			int val = cal(j, i);
			if(mp[val]) f[i] = mp[val];
			if(f[i] && w[mp[val]].size() != i-j+1) {puts("noooo"); return 0;}
			if(f[i]) break;
		}
	}
	int p = n;
	//if(n == 9835) printf("ai %d\n", f[1554]);
	while(p) {
		ans[++ans[0]] = f[p], p=p - w[f[p]].size();
		//if(n == 9835) printf("p %d\n", p);
		//if(++cnt == 10000) {return 0;}
	}
	for(int i=ans[0]; i>=1; i--) cout << w[ans[i]] << " ";

}

