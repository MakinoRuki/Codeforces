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
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<int> ids;
    ids.clear();
    for (int i = 2; i < n; ++i) {
      if (a[i] > a[i-1] && a[i] > a[i+1]) {
        ids.push_back(i);
      }
    }
    int tot=0;
    int cur=0;
    while(cur < ids.size()) {
    //  cout<<"cur="<<cur<<" "<<ids[cur]<<" "<<ids[cur+1]<<endl;
      if (cur + 1 < ids.size() && abs(ids[cur+1] - ids[cur]-1) <= 1) {
        tot++;
        a[ids[cur]+1] = max(a[ids[cur]], a[ids[cur+1]]);
        cur += 2;
      } else {
        tot++;
        a[ids[cur]+1] = a[ids[cur]];
        cur++;
      }
    }
    printf("%d\n", tot);
    for (int i = 1; i <= n; ++i) {
      printf("%d", a[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
