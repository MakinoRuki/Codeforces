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
#define N 300005
#define M 20
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int id=0;
    for (int i = 1; i < n; ++i) {
      if (s[i] <= s[id]) {
        id = i;
      }
    }
    string ans=s.substr(id, 1) + s.substr(0, id) + s.substr(id+1);
    cout<<ans<<endl;
  }
  return 0;
}
