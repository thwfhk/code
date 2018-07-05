#include <iostream>
#include <cstdio>
#define mid ((l+r)>>1)
#define lc x<<1
#define rc x<<1|1
#define lson lc, l, mid
#define rson rc, mid+1, r
typedef long long ll;
const int N = 1e5+5;
inline ll read(){
    char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

struct meow {
    ll sum, add;
} t[N<<2];
inline void paint(int x, int l, int r, ll v) {
    t[x].add += v;
    t[x].sum += v * (r-l+1);
}
inline void pushD(int x, int l, int r) {
    if(t[x].add) {
        paint(lson, t[x].add);
        paint(rson, t[x].add);
        t[x].add = 0;
    }
}
void build(int x, int l, int r) {
    if(l == r) t[x].sum = read();
    else {
        build(lson); 
        build(rson);
        t[x].sum = t[lc].sum + t[rc].sum;
    }
}
void Add(int x, int l, int r, int ql, int qr, ll v) {
    if(ql<=l && r<=qr) paint(x, l, r, v);
    else {
        pushD(x, l, r);
        if(ql <= mid) Add(lson, ql, qr, v);
        if(mid < qr) Add(rson, ql, qr, v);
        t[x].sum = t[lc].sum + t[rc].sum;
    }
}
ll Que(int x, int l, int r, int ql, int qr) {
    if(ql<=l && r<=qr) return t[x].sum;
    else {
        pushD(x, l, r);
        ll ans = 0;
        if(ql <= mid) ans += Que(lson, ql, qr);
        if(mid < qr) ans += Que(rson, ql, qr);
        return ans;
    }
	
}
int main() {
    //freopen("in.txt", "r", stdin);
    int n = read(), Q = read();
    build(1, 1, n);
    while(Q--) {
        int t = read(), l = read(), r = read();
        if(t == 1) Add(1,1,n, l, r, read());
        else printf("%lld\n", Que(1,1,n, l, r));
    }
}
