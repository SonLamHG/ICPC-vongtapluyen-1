#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int solve(int N, int ST, int EN, int u, int d) {
    if (ST == EN) return 0;

    vector<int> dist(N + 1, INT_MAX);
    queue<int> q;

    dist[ST] = 0;
    q.push(ST);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Nút UP
        int up_floor = current + u;
        if (up_floor <= N && dist[up_floor] == INT_MAX) {
            dist[up_floor] = dist[current] + 1;
            q.push(up_floor);
        }

        // Nút DOWN
        int down_floor = current - d;
        if (down_floor >= 1 && dist[down_floor] == INT_MAX) {
            dist[down_floor] = dist[current] + 1;
            q.push(down_floor);
        }
    }

    return dist[EN] == INT_MAX ? -1 : dist[EN];
}

int main() {
    int N, ST, EN, u, d;
    cin >> N >> ST >> EN >> u >> d;

    int result =solve(N, ST, EN, u, d);
    cout << result << endl;

    return 0;
}