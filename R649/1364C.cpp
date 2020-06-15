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
#define N 100002
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int a[N];
int b[N];
int main() {
  cin>>n;
  set<int> ss;
  ss.clear();
  for (int i= 0; i <= 1000000; ++i) {
    ss.insert(i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (ss.find(a[i]) != ss.end()) {
      ss.erase(a[i]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    b[i] = -1;
  }
  for (int i = 2; i <= n; ++i) {
    if (a[i] != a[i-1]) {
      b[i] = a[i-1];
    }
  }
  bool ok = true;
  for (int i = 1; i <= n; ++i) {
    if (b[i] < 0) {
      if (ss.empty()) {
        ok = false;
        break;
      }
      b[i] = (*ss.begin());
      ss.erase(ss.begin());
    }
  }
  if (!ok) cout<<-1<<endl;
  else {
    for (int i =1; i <= n; ++i) {
      printf("%d", b[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
