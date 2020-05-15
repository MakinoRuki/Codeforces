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
int a[N], b[N];
int main() {
  cin>>t;
  for (int cas=1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i =1 ; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    int i = 1, j = n;
    for (int x = 1; x <= k; ++x) {
      if (a[i] < b[j]) {
        swap(a[i], b[j]);
        i++;
        j--;
      } else {
        break;
      }
    }
    int sum=0;
    for (int i =1; i <= n; ++i) {
      sum += a[i];
    }
    cout<<sum<<endl;
  }
  return 0;
}
