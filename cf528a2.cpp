#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int w, h, m;
set<int> ver, hor;
map<int, int> mv, mh;

void solve(set<int> &s, map<int, int> &mp, int x) {
	set<int>::iterator it = s.insert(x).first, lit, rit;
	lit = --it;
	++it; rit = ++it;
	--it;
	int old = *rit - *lit;// printf("old %d\n", old);
	mp[old] --;
	if(mp[old] == 0) mp.erase(old);
	int new1 = *it - *lit, new2 = *rit - *it;// printf("new %d %d\n", new1, new2);
	mp[new1] ++; mp[new2] ++;

}
int main() {
	ios::sync_with_stdio(false);
	cin >> w >> h >> m;

	ver.insert(0); ver.insert(w); mv[w]++;
	hor.insert(0); hor.insert(h); mh[h]++;

	for(int i=1; i<=m; i++) {
		char c; int x;
		cin >> c >> x;
		if(c == 'V') solve(ver, mv, x);
		else solve(hor, mh, x);

		map<int, int>::iterator it = mv.end(); it--;
		int max1 = it->first;

		it = mh.end(); it--;
		int max2 = it->first;
		//printf("hi %d %d\n", max1, max2);
		cout << (long long) max1 * max2 << endl;
	}
}

