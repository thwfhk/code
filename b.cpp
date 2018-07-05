#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=2e6+5;
typedef long long ll;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int n, mp[N], m;
struct meow{
    int x, y, e;
    bool operator <(const meow &a) const {return e<a.e;}
} a[N];
int fa[N], val[N];
int find(int x) {return x==fa[x] ? x : fa[x]=find(fa[x]);}

int main() {
    freopen("in","r",stdin);
    int T=read();
    while(T--) {
        n=read(); m=0;
        for(int i=1; i<=n; i++) 
            mp[++m]=a[i].x=read(), mp[++m]=a[i].y=read(), a[i].e=read()^1;
        sort(mp+1, mp+1+m); m = unique(mp+1, mp+1+m) - mp - 1;
        for(int i=1; i<=m; i++) fa[i]=i, val[i]=0;
        int flag=1, i;
        sort(a+1, a+1+n);
        for(i=1; i<=n && !a[i].e; i++) { 
            a[i].x = lower_bound(mp+1, mp+1+m, a[i].x) - mp;
            a[i].y = lower_bound(mp+1, mp+1+m, a[i].y) - mp;
            fa[find(a[i].x)] = find(a[i].y);
        }
        for(; i<=n; i++) {
            a[i].x = lower_bound(mp+1, mp+1+m, a[i].x) - mp;
            a[i].y = lower_bound(mp+1, mp+1+m, a[i].y) - mp;
            if(find(a[i].x) == find(a[i].y) ) {puts("NO"); flag=0; break;}
        }
        if(flag) puts("YES");
    }
}
