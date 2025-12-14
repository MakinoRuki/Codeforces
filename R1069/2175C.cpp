
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
#define N 500005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int cnt[2][30];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s1,s2;
    cin>>s1>>s2;
    for (int i = 0; i < 26; ++i) {
      cnt[0][i]=cnt[1][i]=0;
    }
    for (int i = 0; i < s1.size(); ++i) {
      cnt[0][s1[i]-'a']++;
    }
    for (int i = 0; i < s2.size(); ++i) {
      cnt[1][s2[i]-'a']++;
    }
    bool ok = true;
    for (int i = 0; i < 26; ++i) {
      if (cnt[0][i] > cnt[1][i]) {
        ok=false;
        break;
      } else {
        cnt[1][i] -= cnt[0][i];
      }
    }
    if (!ok) {
      puts("Impossible");
      continue;
    }
    string ans="";
    int cur1=0;
    int cur2=0;
    for (int i = 0; i < s2.size(); ++i) {
      
      while(cur2 < 26 && cnt[1][cur2] == 0) {
        cur2++;
      }
    //  cout<<"i="<<i<<" "<<cur1<<" "<<cur2<<endl;
      if (cur2 >= 26 || (cur1 < s1.size() && s1[cur1]-'a' <= cur2)) {
        ans += s1[cur1];
        cur1++;
      } else {
        ans.push_back('a'+cur2);
        cnt[1][cur2]--;
      }
    }
    cout<<ans<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0));
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
