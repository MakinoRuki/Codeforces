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
#define M 500005
#define N 5002
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
vector<string> ss;
vector<int> diff[N];
bool mul[N];
int main() {
  cin>>k>>n;
  ss.clear();
  for (int i = 1; i <= k; ++i) {
    cin>>s;
    ss.push_back(s);
  }
  if (k == 1) {
    swap(ss[0][0], ss[0][1]);
    cout<<ss[0]<<endl;
    return 0;
  }
  int cnt[26];
  memset(cnt, 0, sizeof(cnt));
  memset(mul, false, sizeof(mul));
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      cnt[ss[i][j]-'a']++;
      if (cnt[ss[i][j]-'a'] > 1) {
        mul[i] = true;
      }
    }
    for (int j = 0; j < n; ++j) {
      cnt[ss[i][j]-'a']--;
    }
  }
  for (int i = 1; i < k; ++i) {
    diff[i].clear();
    for (int j = 0; j < n; ++j) {
      if (ss[0][j] != ss[i][j]) {
        diff[i].push_back(j);
      }
    }
    if (diff[i].size() > 4) {
      puts("-1");
      return 0;
    }
  }
  string ans = "";
  int id1=-1, id2=-1;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      swap(ss[0][i], ss[0][j]);
      bool ok=true;
      for (int x = 1; x < k; ++x) {
        diff[x].push_back(i);
        diff[x].push_back(j);
        bool found=false;
        int a1 = -1, a2 = -1;
        int num=0;
        for (auto y : diff[x]) {
          if (ss[x][y] != ss[0][y]) {
        //    if (i == 1 && j == 3 && x == 1) cout<<"y="<<y<<endl;
            if (a1 < 0) a1 = y;
            else if (a2 < 0) a2 = y;
            else if (y != a1 && y != a2) found=true;
          }
        }
       // if (i == 1 && j == 3) cout<<x<<" "<<a1<<" "<<a2<<" "<<num<<endl;
        if (found) {
          ok=false;
        } else if (a1 >= 0 && a2 >= 0) {
          if (ss[x][a1] != ss[0][a2] || ss[x][a2] != ss[0][a1]) {
            ok=false;
          }
        } else if (a1 >= 0) {
          ok=false;
        } else if (a2 >= 0) {
          ok = false;
        } else if (!mul[x]) {
          ok=false;
        }
        diff[x].pop_back();
        diff[x].pop_back();
        if (!ok) break;
      }
      swap(ss[0][i], ss[0][j]);
      if (ok) {
        id1 = i, id2 = j;
        break;
      }
    }
    if (id1>=0 && id2>=0) break;
  }
  if (id1>=0 && id2>=0) {
    swap(ss[0][id1], ss[0][id2]);
    cout<<ss[0]<<endl;
  } else {
    puts("-1");
  }
  return 0;
}
