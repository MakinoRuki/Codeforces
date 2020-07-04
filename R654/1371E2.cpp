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
#define N 100005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, p;
int a[N];
bool check1(int x) {
  int tot=0;
  int i = 1;
  while(i <= n) {
    if (tot < 0) return false;
    if (a[i] <= x) {
      tot++;
      i++;
    } else {
      tot--;
      x++;
    }
  }
  return tot>=0;
}
bool check2(int x) {
  int tot=0;
  int i = 1;
  while(i <= n) {
    if (tot >= p) return false;
    if (a[i] <= x) {
      tot++;
      i++;
    } else {
      tot--;
      x++;
    }
  }
  return tot<p;
}
int main() {
  cin>>n>>p;
  vector<pair<int, int>> vs;
  vs.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a+1, a+n+1);
  int l = a[1], r = a[n];
  while(l < r) {
    int mid = (l+r)/2;
    if (check1(mid)) r = mid;
    else l = mid+1;
  }
  int x = r;
  l = x, r = a[n];
  while(l < r) {
    int mid=(l+r+1)/2;
    if (check2(mid)) l = mid;
    else r = mid-1;
  }
  int y = r;
  if (!check2(y)) cout<<0<<endl;
  else {
    cout<<y-x+1<<endl;
    for (int i = x; i <= y; ++i) {
      printf("%d", i);
      if (i < y) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
