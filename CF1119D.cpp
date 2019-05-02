#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
#define pli pair<ll, int>
using namespace std;
typedef long long ll;
int n,q;
ll s[N];
int main() {
	cin>>n;
	vector<ll> sr;
	sr.clear();
	vector<pli> qr;
	qr.clear();
	for (int i = 0; i < n; ++i) {
		cin>>s[i];
		sr.push_back(s[i]);
	}
	sort(sr.begin(), sr.end());
	for (int i = n - 1; i > 0; --i) {
		sr[i] -= sr[i-1];
	}
	for (int i = 0; i < n - 1; ++i ){
		sr[i]=sr[i+1];
	}
	sr.pop_back();
	sort(sr.begin(), sr.end());
	cin>>q;
	for (int i = 0; i < q; ++i) {
		ll l, r;
		cin>>l>>r;
		qr.push_back(make_pair(r-l+1, i));
	}
//	cout<<sr.size()<<endl;
	// for (int i = 0; i < sr.size(); ++i) {
	// 	cout<<i<<" "<<sr[i]<<endl;
	// }
	sort(qr.begin(), qr.end());
	vector<ll>ans(q, 0);
	int j=0;
	ll tot =0;
	for (int i = 0; i < q; ++i) {
		ll len = qr[i].first;
		int idx = qr[i].second;
		while(j<sr.size() && len>sr[j]) {
			tot+=sr[j];
			j++;
		}
	//	cout<<"**"<<i<<" "<<len<<" "<<idx<<" "<<j<<" "<<tot<<endl;
		//if (i == 1) cout<<len<<" "<<tot<<endl;
		ans[idx] = len + tot + ((int)sr.size()-j)*len;
	}
	for (int i = 0; i < q; ++i) {
		cout<<ans[i];
		if (i < q-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
