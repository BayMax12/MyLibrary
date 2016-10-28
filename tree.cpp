struct tree {
  int n, logn;
  vector<vector<int>> adj;
  tree(int n) : n(n), adj(n) { 
    logn = 1;
    for (int k = 1; k < n; k *= 2) ++logn;
  }
  void add_edge(int s, int t) {
    adj[s].push_back(t);
    adj[t].push_back(s);
  }
  vector<vector<int>> parent;
  vector<int> rank, depth;
  void rootify(int r) {
    parent.assign(logn, vector<int>(n, r));
    rank.resize(n);
    depth.assign(n, 0);
    int id = 0;
    function<void (int,int)> dfs = [&](int u, int p) {
      rank[u] = id++;
      parent[0][u] = p;
      for (int i = 0; i+1 < logn; ++i) 
        parent[i+1][u] = parent[i][parent[i][u]];
      for (int v: adj[u]) 
        if (v != p) { depth[v] = depth[u]+1; dfs(v, u); }
    }; dfs(r, r);
  }

  int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int i = depth[v]-depth[u], k = 0; i; i /= 2) {
      if (i & 1) v = parent[k][v];
      ++k;
    }
    if (u == v) return u;
    for (int i = logn-1; i >= 0; --i) {
      if (parent[i][u] != parent[i][v]) {
        u = parent[i][u];
        v = parent[i][v];
      }
    }
    return parent[0][u];
  }
};

