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
#define M 202
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int b[N];
void dfs2(int l, int r, int& cnt) {
  int mid=(l+r+1)/2;
  if (l == r)return;
  int i;
  for (i = l+1; i <= r; ++i) {
    if (b[i] < b[i-1]) {
      break;
    }
  }
  if (i <= r) {
    cnt+=2;
    dfs2(l, mid-1, cnt);
    dfs2(mid, r, cnt);
  }
}
void dfs(int l, int r, int l2, int r2, int& k) {
//  cout<<l<<" "<<r<<" "<<k<<" "<<l2<<" "<<r2<<endl;
  if (k == 0 || l == r) {
    int cur=l;
    for (int i = l2; i <= r2; ++i) {
      a[cur++] = i;
    }
    return;
  }
  int mid=(l+r+1)/2;
  k -= 2;
  int len = mid-l;
  dfs(l, mid-1, r2 - len+1, r2, k);
  dfs(mid, r, l2, r2-len, k);
}
int main() {
  cin>>n>>k;
  if (k % 2 == 0) {
    puts("-1");
    return 0;
  }
  k--;
  dfs(1, n, 1, n, k);
  if (k != 0) {
    puts("-1");
  } else {
    for (int i = 1; i <= n; ++i) {
      printf("%d", a[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   scanf("%d", &b[i]);
  // }
  // int cnt=1;
  // dfs2(1, n, cnt);
  // cout<<"cnt="<<cnt<<endl;
  return 0;
}
