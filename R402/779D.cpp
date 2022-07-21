#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s1, s2;
int a[N];
int idx[N];
int main() {
  cin>>s1>>s2;
  for (int i = 1; i <= s1.size(); ++i) {
    scanf("%d", &a[i]);
    idx[a[i]] = i;
  }
  int l = 0, r = s1.size();
  while(l < r) {
    int mid=(l+r+1)/2;
    int j = 1;
    int i;
    for (i = 0; i < s2.size(); ++i) {
      while(j <= s1.size() && (idx[j] <= mid || s1[j-1] != s2[i])) {
        j++;
      }
      if (j > s1.size()) {
        break;
      }
      j++;
    }
    if (i < s2.size()) {
      r = mid-1;
    } else {
      l = mid;
    }
  }
  cout<<r<<endl;
  return 0;
}
