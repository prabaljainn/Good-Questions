/*
Problem Description

You are given a grid of size ￼ consisting of the following characters:
	•	'S': The starting point.
	•	'F': The destination (end point).
	•	'.': A walkable path.
	•	'#': An obstacle that cannot be crossed.

Your task is to determine the shortest path (in terms of steps) from the starting point ('S') to the destination ('F'). Movement is allowed in the four cardinal directions: up, down, left, and right. You cannot move diagonally or through obstacles ('#').

If the destination is unreachable, output -1.

Input Format
	1.	The first line contains two integers ￼ and ￼ — the number of rows and columns in the grid, respectively.
	2.	The next ￼ lines contain ￼ characters each, representing the grid.

Output Format
	•	Output a single integer:
	•	The minimum number of steps required to reach the destination ('F') from the starting point ('S').
	•	Output -1 if the destination is unreachable.

Constraints
	•	￼
	•	The grid contains exactly one 'S' and one 'F'.

Sample Input and Output

Example 1

Input:

5 5
S....
.###.
..#..
.###.
....F

Output:

8

Explanation:
	•	The shortest path from 'S' to 'F' is 8 steps, avoiding obstacles.

Example 2

Input:

5 5
S....
####.
..#..
.###.
....F

Output:

-1

Explanation:
	•	The destination ('F') is surrounded by obstacles and is unreachable from 'S'.

Example 3

Input:

3 3
S#F
...
...

Output:

2

Explanation:
	•	The shortest path from 'S' to 'F' is 2 steps: move down, then move right.

Approach
	1.	Use Breadth-First Search (BFS) to find the shortest path:
	•	BFS is ideal for unweighted graphs and guarantees the shortest path in terms of steps.
	•	Use a queue to explore all possible paths step-by-step.
	2.	Track visited cells to avoid revisiting and infinite loops.
	3.	Stop as soon as the destination ('F') is reached.
	4.	If the queue is exhausted without reaching 'F', return -1.

This ensures an efficient solution with a time complexity of ￼, suitable for large grids.

*/





#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define vi vector<int>
#define pii pair<int, int>
#define all(c) c.begin(), c.end()
#define pb push_back
#define F first
#define S second
#define int long long
#define fo(i, n) for (int i = 0; i < n; i++)
int mod = 1e9 + 7;
using state = pair<int, int>;
int n, m;
vector<vector<char>> g;
map<state, int> dis;
map<state, bool> vis;

bool checkCoordinates(state position) {
  int x = position.F;
  int y = position.S;

  if (x < 0 || x >= n || y < 0 || y >= m || (g[x][y] == '#')|| vis[position]) return false;
  return true;
}
vector<int> xCoordinate = {0, 1, 0, -1};
vector<int> yCoordinate = {1, 0, -1, 0};
void bfs(state pos) {
  queue<state> q;
  q.push(pos);
  dis[pos] = 0;
  vis[pos] = true;

  while (!q.empty()) {
    state to_explore = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      state newState = {to_explore.F + xCoordinate[i],
                        to_explore.S + yCoordinate[i]};
      if (checkCoordinates(newState)) {
        q.push(newState);
        dis[newState] = dis[to_explore] + 1;
        vis[newState] = true;
      }
    }
  }
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif

  cin >> n >> m;
  g.resize(n);
  state start, end;
  for (int i = 0; i < n; i++) {
    g[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
      if (g[i][j] == 'S')
        start = {i, j};
      else if (g[i][j] == 'F')
        end = {i, j};
    }
  }

  bfs(start);
  cout << dis[end] << endl;
}






