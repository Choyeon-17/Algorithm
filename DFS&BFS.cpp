#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
bool visited[100] = { false, };

vector <vector<int>> vec;

int dfs(int nowNum)
{
    visited[nowNum] = true;
    cout << nowNum << " ";

    for (int i = 0; i < vec[nowNum].size(); i++)
        if (!visited[vec[nowNum][i]])
            dfs(vec[nowNum][i]);
    
    return 0;
}

int bfs()
{
    queue <int> que;

    que.push(V);

    visited[V] = false;
    cout << V << " ";

    while (!que.empty())
    {
        int nowNum = que.front();

        que.pop();

        for (int i = 0; i < vec[nowNum].size(); i++)
        {
            if (visited[vec[nowNum][i]])
            {
                que.push(vec[nowNum][i]);

                visited[vec[nowNum][i]] = false;
                cout << vec[nowNum][i] << " ";
            }
        }
    }

    return 0;
}

int main()
{
    cin >> N >> M >> V;
    vec.resize(N + 1);

    int tmp_a, tmp_b;

    while (--M)
    {
        cin >> tmp_a >> tmp_b;

        vec[tmp_a].push_back(tmp_b);
        vec[tmp_b].push_back(tmp_a);
    }

    for (int i = 1; i < vec.size(); i++)
        sort(vec[i].begin(), vec[i].end());
    
    dfs(V);
    
    cout << endl;

    bfs();

    return 0;
}
