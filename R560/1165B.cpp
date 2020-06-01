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
  sort(a+1, a+n+1);
  int tot=0;
  int cur=1;
  for (int i = 1; i <= n; ++i) {
    if (a[i] >= cur) {
      tot++;
      cur++;
    }
  }
  cout<<tot<<endl;
  return 0;
}
