#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define all(v)          ((v).begin()), ((v).end())
#define pb push_back
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define clr(v,d)		memset(v, d, sizeof(v))
const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = ll(1e9 + 7);
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
#define endl '\n'
void stop(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
void run(){
#ifndef ONLINE_JUDGE
	freopen("intput.txt", "r", stdin);
#endif

}
struct edge{
	ll from, to, w;
	edge(ll f, ll t, ll ww){
		from = f;
		to = t;
		w = ww;
	}
	bool operator < (const edge & e)const{
		return w>e.w;
	}
};
const double PI = acos(-1.0);
int main(){
	fast
		ll n,m,s;
	cin >> n >> m;
	s = 0;
	vector< vector<edge> > adj(n);
	while (m--){
		int from, to, w;
		cin >> from >> to >> w;
		from--; to--;
		adj[from].push_back({from,to,w});
		adj[to].push_back({to,from,w});
	}
	vector<ll> len(n, 1e18);
	len[0] = 0;
	priority_queue<edge> q;
	q.push({-1,0,0});
	vector<ll>pr(n, -1);
	while (q.size()){
		edge e = q.top();
		q.pop();
		if (e.w > len[e.to])continue;
		pr[e.to] = (e.from);
		for (auto i : adj[e.to])
		if(len[i.to]>e.w+i.w){
			i.w = len[i.to] = e.w + i.w;
			q.push(i);
		}
	}
	vector<ll > path;
	int d = n-1;
	if (pr[d] == -1)return cout << -1, 0;
	while (d != -1){
		path.push_back(d+1);
		d = pr[d];
	}
	reverse(all(path));
	for (int i = 0; i < path.size(); i++)
		cout << path[i] << " ";
		
	stop();
	return 0;
}