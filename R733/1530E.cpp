#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#include <time.h>
#define eps 1e-7
#define M 22
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, l, r;
string s;
int cnt[26];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>s;
		n = (int)s.size();
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i) {
			cnt[s[i]-'a']++;
		}
		int tot=0;
		int id = -1;
		int id2 = -1;
		int tot2=0;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] > 0) tot++;
			if (cnt[i] == 1 && id < 0) {
				id = i;
			}
			if (cnt[i]>1) tot2++;
			if (cnt[i] > 0 && id2 < 0) {
				id2 = i;
			}
		}
		if (tot == 1) {
			cout<<s<<endl;
		} else if (tot2 == 0) {
			sort(s.begin(), s.end());
			cout<<s<<endl;
		} else {
			if (id >= 0) {
				string ans="";
				cnt[id]--;
				for (int i = 0; i < 26; ++i) {
					for (int j =1; j <= cnt[i]; ++j) {
						ans.push_back('a'+i);
					}
				}
			//	cout<<"ans="<<ans<<endl;
				reverse(ans.begin(), ans.end());
				ans.push_back('a'+id);
				reverse(ans.begin(), ans.end());
				cout<<ans<<endl;
			} else {
			//	cout<<"???"<<endl;
				if (cnt[id2]*2<=n+2) {
					string ans="";
					ans.push_back('a'+id2);
					ans.push_back('a'+id2);
					cnt[id2]-=2;
					int cur=0;
					while(ans.size() < n) {
						while(cur < 26) {
							if (cur != id2 && cnt[cur] > 0) {
								break;
							}
							cur++;
						}
						if (cur < 26) {
							ans.push_back('a'+cur);
							cnt[cur]--;
						}
						if (cnt[id2]>0) {
							ans.push_back('a'+id2);
							cnt[id2]--;
						}
					}
					cout<<ans<<endl;
				} else {
					if (tot == 2) {
					//	cout<<"!!!"<<endl;
						string ans="";
						ans.push_back('a'+id2);
						cnt[id2]--;
						for (int i = 0; i < 26; ++i) {
							if (i != id2 && cnt[i] > 0) {
								for (int j = 1; j <= cnt[i]; ++j) {
									ans.push_back('a'+i);
								}
								break;
							}
						}
						for (int i = 1; i <= cnt[id2]; ++i) {
							ans.push_back('a'+id2);
						}
						cout<<ans<<endl;
					} else {
						int x=-1,y=-1;
						for (int i = 0; i < 26; ++i) {
							if (cnt[i] > 0 && i!=id2) {
								if (x < 0) {
									x=i;
								} else if (y<0) {
									y=i;
								} else {
									break;
								}
							}
						}
					//	cout<<id2<<" "<<x<<" "<<y<<endl;
						string ans = "";
						ans.push_back('a'+id2);
						cnt[id2]--;
						ans.push_back('a'+x);
						cnt[x]--;
						for (int i = 1; i <= cnt[id2];++i) {
							ans.push_back('a'+id2);
						}
						cnt[id2]=0;
						ans.push_back('a'+y);
						cnt[y]--;
						for (int i = 0; i < 26; ++i) {
							for (int j = 1; j <= cnt[i]; ++j) {
								ans.push_back('a'+i);
							}
						}
						cout<<ans<<endl;
					}
				}
			}
		}
	}
  return 0;
}
