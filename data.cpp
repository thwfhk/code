#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
int r() {
	int f = (rand() & 1) ? 1 : -1;
	int x = rand() % 100;
	if(x < 50) return -40;
	return f * x;
}

int main() {
	freopen("in", "w", stdout);
	int n = 1000;
	cout << n << endl;
	for(int i=1; i<=n; i++) printf("%d %d\n", r(), r());
}
