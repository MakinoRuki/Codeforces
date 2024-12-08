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
#include <stack>
#include <bitset>
#include <chrono>
#define N 200005
#define M 16
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
bool check(string& s, int x) {
    int tot=0;
    for (int i = 0; i < x; ++i) {
        int cnt1=0,cnt2=0;
        for (int j = i; j < n; j += x) {
            if (s[j] != s[i]) cnt1++;
        }
        for (int j = i; j < n; j += x) {
            if (s[j] != s[i+x]) cnt2++;
        }
       // if (x==1) cout<<"i="<<i<<" "<<cnt1<<" "<<cnt2<<endl;
        if (min(cnt1, cnt2) == 0) continue;
        else if (min(cnt1, cnt2) == 1) tot++;
        else return false;
    }
    return tot <= 1;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int ans=n;
    for (int i = 1; i < n; ++i) {
        if (n%i) continue;
        int x=i;
        if (check(s, i)) ans=min(ans, x);
        if (n/i<n) if (check(s, n/i)) ans=min(ans, n/i);
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

