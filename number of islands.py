mat = [
    [1, 1, 0, 1, 0, 0, 1],
    [0, 1, 0, 1, 0, 0, 1],
    [0, 1, 0, 1, 0, 0, 0],
    [0, 0, 1, 1, 1, 0, 0],
    [1, 0, 0, 0, 0, 0, 1],
    [0, 0, 0, 0, 0, 0, 1],
    [0, 1, 0, 0, 0, 1, 1]
]

visited = [False]*(len(mat[0])+1)


def dfs(u):
    visited[u] = True
    for i in range(len(mat[u])):
        if(visited[i] == False and mat[u][i] == 1):
            dfs(i)


c = 0
for i in range(len(mat[0])):
    if(visited[i] == False):
        c += 1
        dfs(i)

print(c)
