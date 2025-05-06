#include <bits/stdc++.h>
using namespace std;

int v, e, res;
int parent[10002];
vector<pair<int, pair<int, int>>> vec;

int find(int x) { // find parent
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back({ c, {a,b} });
    }
    sort(vec.begin(), vec.end());

    for (int i = 1; i <= v; i++)
        parent[i] = i;

    for (int i = 0; i < vec.size(); i++) {
        int now = vec[i].second.first;
        int next = vec[i].second.second;
        int weight = vec[i].first;

        // 사이클이 아닌지 확인 후 사이클이 아니라면 두 정점을 연결 (Union)
        if (find(now) != find(next)) {
            parent[find(next)] = find(now);
            res += weight;
        }
    }
    cout << res;
}

/**
 * Kruskal Alghrithm
 * 그래프의 모든 정점들을 가장 적은 비용으로 연결할 때 사용함 == Minimum Spanning Tree (MST)
 * Greedy의 일종
 *
 * 간선들을 오름차순으로 정렬 후, 사이클을 형성하지 않는 선에서 정렬된 순서대로 간선 선택.
 *
 * parent 배열에 관한 설명
 * 1. parent는 각 정점이 자기 자신만 포함하는 독립적인 집합을 형성하도록 parent[i] = i 로 초기화.
 * 2. find 함수를 통해 가장 최상의 부모를 찾음.
 * 3. 사이클이 형성되지 않는다면(두 정점의 root가 다르면) 두 정점의 root를 같게 만들어줌.
 */