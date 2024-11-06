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
#define N 500005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    vector<int> v;
    v.clear();
    int sum=0;
    cin>>s;
    ll ans=0LL;
    for (int i = 0; i < n; ++i) {
      if ((i%2)==0) {
        if (i==0) {
          s[i] = '(';
          sum++;
          v.push_back(i);
        } else {
          if (sum > 0) {
            sum--;
            int id = v.back();
            v.pop_back();
            ans += i-id;
          } else {
            sum++;
            v.push_back(i);
          }
        }
      } else {
        if (s[i] == '(') {
          sum++;
          v.push_back(i);
        } else {
          sum--;
          int id=v.back();
          v.pop_back();
          ans += i-id;
        }
      }
    }
    printf("%lld\n", ans);
  } 
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

