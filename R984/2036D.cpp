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
#define M 1005
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
int a[M][M];
vector<string> ss;
int check(vector<pair<int,int>>& v) {
    int cnt=0;
    int sz=(int)v.size();
  //  cout<<"sz="<<sz<<endl;
    v.push_back((v[0]));
    if (sz>1) v.push_back((v[1]));
    if (sz>2) v.push_back((v[2]));
    for (int i = 0; i <= v.size()-4; ++i) {
       // cout<<"xy="<<v[i].first<<" "<<v[i].second<<endl;
        int n1 = ss[v[i].first-1][v[i].second-1]-'0';
        int n2 = ss[v[i+1].first-1][v[i+1].second-1]-'0';
        int n3 = ss[v[i+2].first-1][v[i+2].second-1]-'0';
        int n4 = ss[v[i+3].first-1][v[i+3].second-1]-'0';
        if (n1 == 1  && n2==5 && n3 == 4 && n4 == 3) {
            cnt++;
        }
    }
    return cnt;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    ss.clear();
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        ss.push_back(s);
    }
    int ans=0;
    for (int r = 1; r <= (n+1)/2; ++r) {
        vector<pair<int,int>> v;
        v.clear();
        if (r > n+1-r || r > m+1-r) {
            break;
        }
        for (int c = r; c <= m+1-r; ++c) {
            if (v.empty()) {
                v.push_back(make_pair(r ,c));
            } else {
                int r1 = v.back().first;
                int c1=v.back().second;
                if ((r1 != r) || (c1 != c)) {
                    v.push_back(make_pair(r, c));
                }
            }
        }
      //  cout<<"v="<<v.size()<<endl;
        for (int c = r; c <= n+1-r; ++c) {
            if (v.empty()) {
                v.push_back(make_pair(c ,m+1-r));
            } else {
                int r1 = v.back().first;
                int c1=v.back().second;
                if ((r1 != c) || (c1 != m+1-r)) {
                    v.push_back(make_pair(c, m+1-r));
                }
            }
        }
      //  cout<<"v="<<v.size()<<endl;
        for (int c = m+1-r; c >= r; --c) {
            if (v.empty()) {
                v.push_back(make_pair(n+1-r ,c));
            } else {
                int r1 = v.back().first;
                int c1=v.back().second;
                if ((r1 != n+1-r) || (c1 != c)) {
                    v.push_back(make_pair(n+1-r, c));
                }
            }
        }
     //   cout<<"v="<<v.size()<<endl;
        for (int c = n+1-r; c >= r; --c) {
            if (v.empty()) {
                v.push_back(make_pair(c ,r));
            } else {
                int r1 = v.back().first;
                int c1=v.back().second;
                if ((r1 != c) || (c1 != r)) {
                    if ((c != v[0].first)||(r != v[0].second)) {
                        v.push_back(make_pair(c, r));
                    }
                }
            }
        }
     //   cout<<"v="<<v.size()<<endl;
        ans += check(v);
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

