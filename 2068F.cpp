/*
直接贪心。
对于t的当前位置i，如果在s集合中能找到一个s[j]使得s[j]的当前字母c不等于t[i]，那么就选c加入答案串，并更新s中被选中串的当前字母；
否则就加入t[i]。最后s都放完之后检查t是否放完。
*/

#include <iostream>
#include <sstream>
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
#define N 2000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
deque<pair<int,int>> dq[30];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  cin>>n;
  vector<string> v;
  v.clear();
  // for (int i = 0; i < 26; ++i) {
  //   dq[i].clear();
  // }
  for (int i = 1; i <= n; ++i) {
    string s;
    cin>>s;
    v.push_back(s);
    int c=s[0]-'a';
    dq[c].push_back(make_pair(i-1, 0));
  }
  string s2;
  cin>>s2;
  int cur=0;
  string ans="";
  bool ok=true;
  while(true) {
    if (cur >= s2.size()) {
      ok=false;
      break;
    }
    bool found=false;
    bool nn = false;
    for (int i = 0; i < 26; ++i) {
      if (!dq[i].empty()) nn=true;
      if (i != s2[cur]-'a' && !dq[i].empty()) {
     //   cout<<"i="<<(char)(i+'a')<<endl;
        ans.push_back('a'+i);
        int sz = (int)dq[i].size();
        for (int j = 0; j < sz; ++j) {
          auto top = dq[i].front();
          dq[i].pop_front();
          top.second++;
          if (top.second >= v[top.first].size()) {
            continue;
          }
          int cc = v[top.first][top.second]-'a';
          dq[cc].push_back(top);
        }
        found=true;
        break;
      }
    }
    if (!found) {
      if (!nn) {
        break;
      }
      int cc = s2[cur]-'a';
      ans.push_back(s2[cur++]);
      int sz = (int)dq[cc].size();
      for (int j = 0; j < sz; ++j) {
        auto top = dq[cc].front();
        dq[cc].pop_front();
        top.second++;
        if (top.second >= v[top.first].size()) {
          continue;
        }
        int cc2 = v[top.first][top.second]-'a';
        dq[cc2].push_back(top);
      }
    }
  }
  if (ok) {
    puts("YES");
    cout<<ans<<endl;
  } else {
    puts("NO");
  }
  return 0;
}

