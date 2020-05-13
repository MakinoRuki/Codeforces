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
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, k;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    bool found = false;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] == k) found=true;
    }
    bool ok = false;
    for (int i = 1; i <= n; ++i) {
      for (int j = i+1; j <= min(i+2, n); ++j) {
        if (a[i]>=k && a[j] >= k) ok = true;
      }
    }
    if (found && (n==1 || ok)) {
      cout<<"yes"<<endl;
    } else {
      cout<<"no"<<endl;
    }
  }
  return 0;
}
