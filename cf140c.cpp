#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5+5;

int n, r[N], ans, ans1[N], ans2[N], ans3[N];
struct meow {
	int r, cnt;
	bool operator < (const meow &r) const {
		return cnt < r.cnt;
	}
} ;
priority_queue<meow> q;
meow a, b, c;

int main() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> r[i];
	sort(r+1, r+1+n);
	for(int i=1; i<=n; i++) {
		int cnt = 1;
		while(r[i+1] == r[i]) i++, cnt++;
		q.push((meow){r[i], cnt});
	}
	while(q.size() >= 3) {
		a = q.top(); q.pop();
		b = q.top(); q.pop();
		c = q.top(); q.pop();
		a.cnt --;
		b.cnt --;
		c.cnt --;
		if(a.cnt != 0) q.push(a);
		if(b.cnt != 0) q.push(b);
		if(c.cnt != 0) q.push(c);

		ans++;
		ans1[ans] = a.r;
		ans2[ans] = b.r;
		ans3[ans] = c.r;
	}
	printf("%d\n", ans);
	for(int i=1; i<=ans; i++) {
		int t[5];
		t[1] = ans1[i], t[2] = ans2[i], t[3] = ans3[i];
		sort(t+1, t+4);
		printf("%d %d %d\n", t[3], t[2], t[1]);
	}
}
