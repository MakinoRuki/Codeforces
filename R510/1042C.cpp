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
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
ll a[N];
int main() {
	cin>>n;
	vector<int> id0;
	vector<pair<ll,int>> id1;
	vector<pair<ll,int>> id2;
	id0.clear();
	id1.clear();
	id2.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		if (a[i]==0) {
			id0.push_back(i);
		} else if (a[i]<0) {
			id1.push_back(make_pair(-a[i], i));
		} else {
			id2.push_back(make_pair(a[i], i));
		}
	}
	sort(id1.begin(), id1.end());
	sort(id2.begin(), id2.end());
	int sz0=(int)id0.size();
	int sz1=(int)id1.size();
	int sz2=(int)id2.size();
	if (sz0 > 0) {
		if (sz1%2) {
			printf("1 %d %d\n", id1[0].second, id0[0]);
		}
		for (int i = 0; i < sz0-1; ++i) {
			printf("1 %d %d\n", id0[i], id0[i+1]);
		}
		if (sz1%2 && sz1-1+sz2 > 0) {
			printf("2 %d\n", id0.back());
		} else if (sz1%2==0 && sz1+sz2>0) {
			printf("2 %d\n", id0.back());
		}
		int st=0;
		if (sz1%2) {
			st=1;
		}
	//	cout<<"ok1"<<endl;
		for (int i = st; i < sz1-1; ++i) {
		//	cout<<"i=??"<<i<<endl;
			printf("1 %d %d\n", id1[i].second, id1[i+1].second);
		}
	//	cout<<"ok2"<<endl;
		if (sz2>0 && sz1>1) {
			printf("1 %d %d\n", id1.back().second, id2[0].second);
		}
	//	cout<<"ok3"<<endl;
		for (int i = 0; i < sz2-1; ++i ){
			printf("1 %d %d\n", id2[i].second, id2[i+1].second);
		}
	} else {
		if (sz1%2) {
			printf("2 %d\n", id1[0].second);
			for (int i = 1; i < sz1-1; ++i) {
				printf("1 %d %d\n", id1[i].second, id1[i+1].second);
			}
			if (sz2>0 && sz1>1) {
				printf("1 %d %d\n", id1.back().second, id2[0].second);
			}
			for (int i = 0; i < sz2-1; ++i ){
				printf("1 %d %d\n", id2[i].second, id2[i+1].second);
			}
		} else {
			for (int i = 0; i < sz1-1; ++i) {
				printf("1 %d %d\n", id1[i].second, id1[i+1].second);
			}
			if (sz1>0 && sz2>0) {
				printf("1 %d %d\n", id1.back().second, id2[0].second);
			}
			for (int i = 0; i < sz2-1; ++i) {
				printf("1 %d %d\n", id2[i].second, id2[i+1].second);
			}
		}
	}
	return 0;
}
