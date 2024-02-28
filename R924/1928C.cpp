#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#include <list>
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d%d", &n, &x);
    set<int> ss;
    ss.clear();
    if (n-x>=0 && ((n-x)%2)==0) {
        int z = (n-x)/2;
        for (ll i = 1; i *i <= z; ++i) {
            if ((z%i) == 0) {
                if (i+1>=x) ss.insert(i+1);
                if (z/i != i && z/i+1>=x) ss.insert(z/i+1);
            }
        }
    }
    if (x > 1) {
        if (n+x-2>=0 && ((n+x-2)%2)==0) {
            int z = (n+x-2)/2;
            for (ll i = 1; i *i <= z; ++i) {
                if ((z%i) == 0) {
                    if (i+1>x) ss.insert(i+1);
                    if (z/i != i && z/i+1>x) ss.insert(z/i+1);
                }
            }
        }
    }
    int ans=(int)ss.size();
    printf("%d\n", ans);
  }
  return 0;
}

