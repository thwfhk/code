#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
typedef unsigned long long ll;
const int N = 1e5+5;

int n, m;
string s;
string w[N];
int f[N], ans[N];

struct meow {
	int ch[27];
	int val;
} t[N * 10];
int sz = 0;
void insert(int x) {
	string s = w[x]; 
	reverse(s.begin(), s.end());
	int u = 0;
	for(int i=0; i<s.size(); i++) { 
		int c = tolower(s[i]) - 'a';
		if(!t[u].ch[c]) t[u].ch[c] = ++sz;
		u = t[u].ch[c];
	}
	t[u].val = x;
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
		insert(i); 
	}
	f[0] = 1;
	for(int i=1; i<=n; i++) if(f[i-1]) {
		int u = 0;
		for(int j=i; j<=i+1000 && j<=n; j++) {
			int c = s[j] - 'a'; 
			if(!t[u].ch[c]) break;
			u = t[u].ch[c];
			if(t[u].val) f[j] = t[u].val; 
		}
	}
	int p = n;
	while(p) ans[++ans[0]] = f[p], p=p - w[f[p]].size();
	for(int i=ans[0]; i>=1; i--) cout << w[ans[i]] << " ";
}
