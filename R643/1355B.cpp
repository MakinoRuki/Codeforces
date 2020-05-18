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
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int e[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas <= t; ++cas) {
    scanf("%d", &n);
    for (int i =1 ; i <= n; ++i) {
      cnt[i] = 0;
    }
    for (int i =1; i <= n; ++i) {
      scanf("%d", &e[i]);
      cnt[e[i]]++;
    }
    int tot=0;
    int rem=0;
    for (int i =1 ; i <= n; ++i) {
      tot += (cnt[i] + rem) / i;
      rem = (cnt[i]+rem) % i;
    }
    cout<<tot<<endl;
  }
  return 0;
}
