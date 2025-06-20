#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#define endl '\n';
typedef long long ll;
using namespace std;

int n, s, f, kolvopair;
int first, second, m;
vector<pair<int, int> > g[200100];
vector<vector<int>> vectormass;
ll dist[200100];
bool used[200100];
int pr[200100];

void dijkstra_pq(int start) {
    fill(used, used + n, 0);
    fill(dist, dist + n, 1000);

    dist[start] = 0;
    priority_queue < pair<ll, int>, vector<pair<ll, int>>,
        greater<pair<ll, int>>> pq;
    pq.push({ 0, start });
    while (pq.size()) {
        int v = pq.top().second; pq.pop();
        if (used[v])
            continue;
        used[v] = 1;
        for (auto el : g[v]) {
            int to = el.first;
            int weight = el.second;
            if (!used[to] && dist[to] > dist[v] + weight) {
                dist[to] = dist[v] + weight;
                pr[to] = v;
                pq.push({ dist[to], to });
            }
        }
    }
    if (used[f] == 0) {
        cout << -1;
    }
    else {
        vector<int> ans;
        int k = f;
        int mass = 0;
        while (pr[k] != -1) {
            ans.push_back(k);
            k = pr[k];
        }
        ans.push_back(k);
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size() - 1; ++i) {
            mass += vectormass[ans[i]][ans[i + 1]];
        }
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
        cout << mass;

    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество вершин, начальную и конечную вершину" << endl;
    cin >> n >> s >> f;
    vectormass.resize(n, vector<int>(n));
    cout << "Введите количество пар" << endl;
    cin >> kolvopair;
    --s;
    --f;
    cout << "введите вершины и веса рёбер" << endl;
    for (int i = 0; i < kolvopair; ++i) {
        cin >> first >> second >> m;
        first--;
        second--;
        g[first].push_back({ second, m });
        g[second].push_back({ first, m });
        vectormass[first][second] = m;
        vectormass[second][first] = m;
    }
    pr[s] = -1;
    dijkstra_pq(s);
    return 0;
}