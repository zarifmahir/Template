//Sieve of Eratosthenes
int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}


//Extended euclidean algorithm
int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}


// Diophantine (for ax+by=c) [for any solutions: x = x0 + k*g, y = y0 - k*g]
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}


//Modular Exponentiation
int modexp(int a, int b){
int result = 1;
while(s){
if(s&1) result *= a;
a*=a;
s>>=1;
}
return result;
}


// Modular Inverse when a^p mod p, where p is prime (Fermats's little theorem)
int inv(int a, int p){
return modexp(a, p-2, p)
}

// Modular Inverse of A, when A and m are coprime
Let a number be B such that (A*B) % m = 1, so B is then called the modular inverse of A
so 1 = AB - qm......q is quotient(A/B)
Here A and m is given so using extended gcd we can get a value of B
int x, y;
int g = gcd(A, B, x, y);
if(g!=1) NO solution
else{
ans = (x%m +m)%m....m is added to avoid negative value of B
}

// nCr = n-1Cr-1 + n-1Cr

//BFS, prepare adj list first
queue<int> q;
int visited[n+1] // n = number of nodes
memset(visited, 0, sizeof(visited));
q.push(1);
while(!q.empty()){
int curr = q.front(); q.pop();
if(visited[curr]) continue;
visited[curr] = 1;
for(int v: adj_list[curr]){
if(visited[v]) continue;
q.push(v);
}
}

//Flood fill algorithm, similar to BFS
int n, m; cin>>n>>m; [a grid of nxm]
int x, y; cin>>x>>y; [starting from  the cell x, y]
int vis[n+1][m+1];
for(int i=0; i<n+1; i++) for(int j=0; j<m+1; j++) vis[i][j] = 0;

vector<int> dx = {0, 0, 1, -1}
vector<int>dy = {1, -1, 0, 0}        [these are to get the positions (i,j+1), (i, j-1), (i+1, j), (i-1, j)]
queue<pair<int,int>> Q;
vis[x][y] = 1; [making vis 1 before pushing in the queue]
Q.push({x,y});
while(!Q.empty()){
pair<int,int> curr = Q.front();
Q.pop();
int i = curr.first, j= curr.second;
for(int k=0; k<4; k++){
int nx = i+dx[k], ny = j+dy[k];
if(nx<1 or ny<1 or ny>m or nx>n) continue;
if(vis[nx][ny]) continue;
vis[nx][ny] = 1;
Q.push({nx, ny});
}
}

//Topological Sorting

int n,m; cin>>n>>m; // n = no of nodes, m = no of edges
vector<int> adj_list[n+1];
vector<int> indegree[n+1];
for(int i=0; i<m; i++){
int u, v; cin>>u>>v;
adj_list[u].push_back(v);
indegree[v]++;
}

multiset<pair<int,int>> ms;
for(int i=1; i<n+1; i++) ms.insert({indegree[i], i});
vector<int> is_used(n+1);
vector<int> ordering;

while(!ms.empty()){
auto root = *ms.begin();
ms.erase(ms.begin());
if(is_used[root.second]) continue;
if(root.first!=0) break; // cycle is present..not DAG = Directed Acyclic Graph
is_used[root.second] = 1;
ordering.push_back(root.second);
for(int v: adj_list[root.second]){
indegree[v]--;
ms.insert({indegree[v], v});
}
}
if(ordering.size()!=n) cout<<"Not dag";
else print ordering;

//Floyd warshall algorithm - To find shortest paths between all pairs of nodes
int n; cin>>n; //no of nodes
int m; cin>>m; // no of edges
int dist[n+1][n+1];

for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
        dist[i][j] = 1e9;
    }
}

for(int i=1; i<=n; i++) dist[i][i] = 0;

for(int i=1; i<=m; i++){
    int u, v, w; cin>>u>>v>>w;
    dist[u][v] =  min(dist[u][v], w); // w is the edge weight, for directed graph
}

for(int k=1; k<=n; k++)
{
for(int i=1; i<=n; i++){
for(int j=1; j<=n; j++){
dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}
}
} // TC: O(N3), SC: O(N2)


// Bellman Ford Algorithm, for determining negative cycle in a graph

vector<vector<int>> edge_list;
int n, m; cin>>n>>m;
for(int i=1; i<=m; i++){
int u,v, w; cin>>u>>v>>w;
edge_list.push_back({u,v,w});
}

for(int i=0; i<n; i++){
    for(vector<int> edge: edge_list){
    int u = edge[0], v = edge[1], w = edge[2];
    if(dist[u]+w<dist[v]){
    dist[v] = dist[u]+w;
    if(i==n-1) cout<<"NEGATIVE CYCLE PRESENT"<<"\n";
    }
    }
}







