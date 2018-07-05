#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e6+5;

int n, a[N], mp[N], m, c[N], f1[N], f2[N];
/*
inline void add(int p, int v) {
	if(!p) return;
	for(; p<=n; p+=p&-p) c[p] += v;
}
inline int sum(int p) {
	int ans = 0;
	for(; p; p-=p&-p) ans += c[p];
	return ans;
}
*/
inline void add(int p, int v) {
	for(; p; p-=p&-p) c[p] += v;
}
inline int sum(int p) {
	int ans = 0;
	for(; p<=n; p+=p&-p) ans += c[p];
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i], mp[i] = a[i];
	sort(mp+1, mp+1+n); 
	m = unique(mp+1, mp+1+n) - mp -1;
	for(int i=1; i<=n; i++) {
		a[i] = lower_bound(mp+1, mp+1+m, a[i]) -mp;
		f1[i] = c[a[i]];
		c[a[i]]++;
	}
	memset(c, 0, sizeof(c));
	for(int i=n; i>=1; i--) {
		f2[i] = c[a[i]];
		c[a[i]]++;
	}
	memset(c, 0, sizeof(c));
	long long ans = 0;
	for(int i=1; i<=n; i++) {
		//ans += sum(n) - sum(f2[i]);
		//add(f1[i], 1);
		ans += sum(f2[i] + 1);
		add(f1[i], 1);
	}
	cout << ans;
}
