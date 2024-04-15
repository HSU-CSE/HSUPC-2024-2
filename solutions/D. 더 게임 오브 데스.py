n,k = map(int,input().split())
graph = [[0,0]]

for _  in range(n):
    left,right = map(int,input().split())
    graph.append([left,right])

visited = [0]*32

remain,now = n,k
while remain != 1:
    next = -1
    if visited[now] == 0 :
        next = graph[now][0]
    else:
        next = graph[now][1]
        remain -= 1
    visited[now] += 1
    now = next

result = -1
for i in range(1,n+1):
    if visited[i] != 2:
        result = i
        break
print(result)