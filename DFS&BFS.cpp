#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, V;
bool visited[100] = { false, };

vector <vector<int>> vec;

int dfs(int now_num)
{
    visited[now_num] = true;
    cout << now_num << " ";
    for (int i = 0; i < vec[now_num].size(); i++)
        if (!visited[vec[now_num][i]])
            dfs(vec[now_num][i]);
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
        int now_num = que.front();
        que.pop();
        for (int i = 0; i < vec[now_num].size(); i++)
        {
            if (visited[vec[now_num][i]])
            {
                que.push(vec[now_num][i]);
                visited[vec[now_num][i]] = false;
                cout << vec[now_num][i] << " ";
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