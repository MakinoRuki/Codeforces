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
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
bool check(vector<int>& v, int mid, ll c, int d) {
    ll tot=0LL;
    for (int i = 0; i < d; ++i) {
        if ((i%(mid+1))<v.size()) tot += v[i%(mid+1)];
    }
    return tot >= c;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll c;
    int d;
    scanf("%d%lld%d", &n, &c, &d);
    vector<int> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int l = 0, r = d-1;
    while(l < r) {
        int mid=(l+r+1)/2;
        if (check(v, mid, c, d)) {
            l = mid;
        } else {
            r = mid-1;
        }
    }
    if (r > 0 && r < d-1) {
        printf("%d\n", r);
    } else if ((r == d-1) && check(v, r, c, d)) {
        puts("Infinity");
    } else if (!check(v, r, c, d)) {
        puts("Impossible");
    } else {
        printf("%d\n", r);
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
