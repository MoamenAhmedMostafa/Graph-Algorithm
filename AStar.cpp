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
void Astar(){
	vector< vector<edge> > adj(n);
	ll n, m, s;
	cin >> n >> m;
	int SL[50000];
	for (int i = 0; i < n; i++)cin >> SL[i];
	s = 0;
	vector< vector<edge> > adj(n);
	while (m--){
		int from, to, w;
		cin >> from >> to >> w;
		from--; to--;
		adj[from].push_back({ from, to, w });
		adj[to].push_back({ to, from, w });
	}
	vector<ll> len(n, 1e18);
	len[0] = 0;
	priority_queue<edge> q;
	q.push({ -1, 0, 0 });
	vector<ll>pr(n, -1);
	while (q.size()){
		edge e = q.top();
		q.pop();
		if (e.w > len[e.to]+SL[e.to])continue;
		pr[e.to] = (e.from);
		for (auto &i : adj[e.to])
		if (len[i.to]>e.w + i.w+SL[i.to]){
			i.w = len[i.to] = e.w + i.w;
			q.push(i);
		}
	}
	vector<ll > path;
	int d = n - 1;
	if (pr[d] == -1)return;
	while (d != -1){
		path.push_back(d + 1);
		d = pr[d];
	}
	reverse(all(path));
	for (int i = 0; i < path.size(); i++)
		cout << path[i] << " ";
}