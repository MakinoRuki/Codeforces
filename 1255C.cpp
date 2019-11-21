#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
int n;
int main() {
	cin>>n;
	int cnt[N];
	memset(cnt, 0, sizeof(cnt));
	vector<vector<int>> a;
	map<pair<int, int>, set<int>> idx;
	for (int i = 0; i < n-2; ++i) {
		int x,y,z;
		cin>>x>>y>>z;
		a.push_back({x,y,z});
		cnt[x]++;
		cnt[y]++;
		cnt[z]++;
		vector<int> tt;
		tt.push_back(x);
		tt.push_back(y);
		tt.push_back(z);
		sort(tt.begin(), tt.end());
		idx[make_pair(tt[0], tt[1])].insert(i);
		idx[make_pair(tt[1], tt[2])].insert(i);
		idx[make_pair(tt[0], tt[2])].insert(i);
	}
	int s;
	for (int i = 0; i < n-2; ++i) {
		int x=a[i][0];
		int y=a[i][1];
		int z=a[i][2];
		if (cnt[z]==1 || cnt[y]==1 || cnt[x]==1) {
			s=i;
			break;
		}
	}
	vector<int> ans;
	for (int i = 0; i < n-3; ++i) {
		int x = a[s][0];
		int y = a[s][1];
		int z = a[s][2];
		vector<int> tt;
		if (cnt[x] == 1) {
			ans.push_back(x);
			tt.push_back(y);
			tt.push_back(z);
		} else if (cnt[y] == 1) {
			ans.push_back(y);
			tt.push_back(x);
			tt.push_back(z);
		} else if (cnt[z] == 1) {
			ans.push_back(z);
			tt.push_back(x);
			tt.push_back(y);
		}
		cnt[x]--;
		cnt[y]--;
		cnt[z]--;
		sort(tt.begin(), tt.end());
		idx[make_pair(tt[0], tt[1])].erase(s);
		s = *idx[make_pair(tt[0], tt[1])].begin();
		if (i == n-4) {
			 x = a[s][0];
			 y=a[s][1];
			 z=a[s][2];
		//	 cout<<"!!"<<x<<" "<<y<<" "<<z<<endl;
			 int cnt2[N];
			 memset(cnt2, 0, sizeof(cnt));
			 for (int j = 0; j < n-2; ++j) {
			 	cnt2[a[j][0]]++;
			 	cnt2[a[j][1]]++;
			 	cnt2[a[j][2]]++;
			 }
			 vector<pair<int, int>> tmp;
			 tmp.push_back(make_pair(cnt2[x], x));
			 tmp.push_back(make_pair(cnt2[y], y));
			 tmp.push_back(make_pair(cnt2[z], z));
			 sort(tmp.begin(), tmp.end());
			 ans.push_back(tmp[2].second);
			 ans.push_back(tmp[1].second);
			 ans.push_back(tmp[0].second);
			 break;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout<<ans[i];
		if (i == n-1) cout<<endl;
		else cout<<" ";
	}
	return 0;
}
