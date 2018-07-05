#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int w, h, m;
set<int> ver, hor;
//map<int, int> mv, mh;
multiset<int> mv, mh;

void solve(set<int> &s, multiset<int> &mp, int x) {
	set<int>::iterator it = s.insert(x).first, lit, rit;
	lit = --it;
	++it; rit = ++it;
	--it;
	int old = *rit - *lit;// printf("old %d\n", old);
	multiset<int>::iterator mit = mp.find(old);
	mp.erase(mit);
	int new1 = *it - *lit, new2 = *rit - *it;// printf("new %d %d\n", new1, new2);
	mp.insert(new1); mp.insert(new2);

}
int main() {
	ios::sync_with_stdio(false);
	cin >> w >> h >> m;

	ver.insert(0); ver.insert(w); mv.insert(w);
	hor.insert(0); hor.insert(h); mh.insert(h);

	for(int i=1; i<=m; i++) {
		char c; int x;
		cin >> c >> x;
		if(c == 'V') solve(ver, mv, x);
		else solve(hor, mh, x);

		multiset<int>::iterator it = mv.end(); it--;
		int max1 = *it;

		it = mh.end(); it--;
		int max2 = *it;
		//printf("hi %d %d\n", max1, max2);
		cout << (long long) max1 * max2 << endl;
	}
}
