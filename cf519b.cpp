#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5+5;

int n, mp[N], m, a[N], c1[N], c2[N], c3[N];

int main() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i], mp[i] = a[i];
	sort(mp+1, mp+1+n); 
	m = unique(mp+1, mp+1+n) -mp -1;
	for(int i=1; i<=n; i++) {
		int t = lower_bound(mp+1, mp+1+m, a[i]) - mp;
		c1[t]++;
	}
	for(int i=1; i<=n-1; i++) {
		int t; cin >> t;
		t = lower_bound(mp+1, mp+1+m, t) - mp;
		c2[t]++;
	}
	for(int i=1; i<=n-2; i++) {
		int t; cin >> t;
		t = lower_bound(mp+1, mp+1+m, t) - mp;
		c3[t]++;
	}
	int ans1=0, ans2=0;
	for(int i=1; i<=m; i++) {
		if(c1[i] > c2[i]) ans1 = mp[i];
		if(c2[i] > c3[i]) ans2 = mp[i];
		//printf("c %d   %d %d %d\n", mp[i], c1[i], c2[i], c3[i]);
	}
	printf("%d\n%d", ans1, ans2);
}
