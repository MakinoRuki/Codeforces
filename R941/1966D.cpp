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
#include <random>
#include <ctime>
#include <list>
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    int pw=0;
    while((1<<pw)<=k) {
      pw++;
    }
    pw--;
    vector<int> ans;
    ans.clear();
    for (int i = 0; i < 22; ++i) {
      if (i == pw) continue;
      ans.push_back(1<<i);
    }
    ans.push_back(k-(1<<pw));
    ans.push_back(k+1);
    ans.push_back(k+1+(1<<pw));
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
