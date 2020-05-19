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
#define N 500005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int a[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int cnt[7];
  memset(cnt, 0, sizeof(cnt));
  int tot=0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 4) {
      cnt[1]++;
    } else if (a[i] == 8) {
      if (cnt[1]) {
        cnt[1]--;
        cnt[2]++;
      } else {
        tot++;
      }
    } else if (a[i] == 15) {
      if (cnt[2]) {
        cnt[2]--;
        cnt[3]++;
      } else {
        tot++;
      }
    } else if (a[i] == 16) {
      if (cnt[3]) {
        cnt[3]--;
        cnt[4]++;
      } else {
        tot++;
      }
    } else if (a[i] == 23) {
      if (cnt[4]) {
        cnt[4]--;
        cnt[5]++;
      } else {
        tot++;
      }
    } else if (a[i] == 42) {
      if (cnt[5]) {
        cnt[5]--;
        cnt[6]++;
      } else {
        tot++;
      }
    } else {
      tot++;
    }
  }
  for (int i = 1; i <= 5; ++i) {
    tot += i * cnt[i];
  }
  cout<<tot<<endl;
  return 0;
}
