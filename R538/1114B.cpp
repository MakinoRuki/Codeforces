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
#define N 200005
#define M 100005
#define inf 1000000000
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m, k;
int a[N];
int b[N];
int main() {
  cin>>n>>m>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b+1, b+n+1);
  int bd = b[n-m*k+1];
  ll tot=0;
  map<int, int> num;
  num.clear();
  for (int i = 1; i <= m*k; ++i) {
    tot += b[n-(i-1)];
    num[b[n-(i-1)]]++;
  }
//  cout<<"bd="<<bd<<endl;
  cout<<tot<<endl;
  int j=1;
  for (int i = 1; i < k; ++i) {
    int cnt=0;
    while(j <= n) {
      if (num[a[j]]>0) {
        cnt++;
        num[a[j]]--;
      }
      if (cnt == m) break;
      j++;
    }
    printf("%d", j);
    if (i < k-1) cout<<" ";
    else cout<<endl;
    j++;
  }
  return 0;
}
