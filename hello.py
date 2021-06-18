def dfs(u):
    visited[u] = True
    print(u, end=' ')

    for i in g[u]:
        if(visited[i] == False):
            dfs(i)


n, e = map(int, input().split())
g = [[]]*(n+1)
visited = [False]*(n+1)
while e:
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
    e -= 1

dfs(1)
