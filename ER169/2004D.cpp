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
#define M 750
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
vector<string> cc = {"BG", "BR", "BY", "GR", "GY", "RY"};
vector<string> v;
vector<vector<int>> ids;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d\n", &n, &q);
    v.clear();
    ids.clear();
    for (int i = 0; i < 6; ++i) {
        ids.push_back({});
    }
//     istringstream iss;
//   string s;
//   while ( getline( iss, s, ' ' ) ) {
//     printf( "%s\n", s.c_str());
//   }
//   // cin>>s;
     int cur=0;
    string s;
    getline(cin, s);
  //  cout<<"s="<<s<<endl;
    for (int i = 1; i <= n; ++i) {
    //     cout<<"i="<<i<<endl;
    //     scanf("%s", s);
    //   // cin>>s;
    //     cout<<"s="<<s<<endl;
   // cout<<"cur="<<cur<<endl;
        string tmp=s.substr(cur, 2);
        v.push_back(tmp);
        for (int j = 0; j < 6; ++j) {
           // cout<<"j="<<j<<endl;
            if (cc[j] == tmp) {
             //   cout<<"!!"<<endl;
                ids[j].push_back(i);
                break;
            }
        }
      //  cout<<"??"<<endl;
        cur += 3;
       // cout<<"tmp="<<tmp<<" "<<cur<<endl;
    }
   // cout<<"??"<<endl;
    while(q-->0) {
        int x,y;
        scanf("%d%d", &x, &y);
        string s1=v[x-1];
        string s2=v[y-1];
        if (s1[0] == s2[0] || s1[0] == s2[1] || s1[1] == s2[0] || s1[1] == s2[1]) {
            printf("%d\n", abs(x-y));
        } else {
            int ans=inf;
            int id1=0,id2=0;
            for (int i = 0; i < 6; ++i) {
                if (cc[i] == s1) {
                    id1=i;
                } else if (cc[i] == s2) {
                    id2 = i;
                }
            }
            int l=0,r=0;
            if (x > y) swap(x, y);
            for (int i = 0; i < 6; ++i) {
                if (i == id1 || i == id2) {
                    continue;
                }
                int idx=upper_bound(ids[i].begin(), ids[i].end(), x)-ids[i].begin();
                if (idx>=0 && idx<ids[i].size()) {
                    l = (l == 0 ? ids[i][idx] : min(l, ids[i][idx]));
                }
                int idy=lower_bound(ids[i].begin(), ids[i].end(), y)-ids[i].begin();
                idy--;
                if (idy>=0 && idy<ids[i].size()) {
                    r = (r == 0? ids[i][idy] : max(r, ids[i][idy]));
                }
            }
        //    cout<<"lr="<<l<<" "<<r<<endl;
            if (l) {
          //      cout<<"xy="<<x<<" "<<y<<" "<<abs(x-l)+abs(l-y)<<endl;
                ans=min(ans, abs(x-l)+abs(l-y));
            }
            if (r) {
                ans=min(ans, abs(x-r)+abs(r-y));
            }
            printf("%d\n", (ans<inf?ans:-1));
        }
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
