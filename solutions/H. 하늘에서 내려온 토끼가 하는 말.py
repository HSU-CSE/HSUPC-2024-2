'''
N x M 크기의 섬
육지 . , 물 *, 토끼의 위치 B, 당근의 위치 C
토끼는 상하좌우로 이동, 물이 찰 예정인 칸으로 이동 불가
물에 맞닿아 있는 칸은 매 분 물에 잠김
'''
from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int,input().split())

c_x,c_y = -1,-1 # 당근의 위치
waterQ = deque() # 물의 위치 기록
bunnyQ = deque() # 토끼 위치 기록

visited = [[-1 for _ in range(M)] for _ in range(N)]

dx = [0,0,-1,1]; dy = [-1,1,0,0]

island = []
for i in range(N):
    row = list(input().rstrip())
    for j in range(M): 
        if row[j] == 'B': # 토끼의 위치(탐색 시작 위치 기록)
            bunnyQ.append((i,j))
            visited[i][j] = 0 # 방문처리
        elif row[j] == 'C': # 당근의 위치(탐색 종료 위치 기록)
            c_x,c_y = i,j
        elif row[j] == '*':
            waterQ.append((i,j))
            visited[i][j] = 0 # 홍수 방문 처리
    island.append(row)

# 토끼가 당근으로 이동한다.
def is_meet():
    global bunnyQ
    new_bunnyQ = deque()
    while bunnyQ:
        x,y = bunnyQ.popleft()
        # 당근에 도달하는데 성공했다면
        if (x,y) == (c_x,c_y):
            return True
        for i in range(4):
            nx = x + dx[i]; ny = y + dy[i]
            # 섬의 영역을 벗어나지 않으면서 아직 방문한적 없는 지역 방문
            if 0<=nx<N and 0<=ny<M and visited[nx][ny] == -1:
                if island[nx][ny] != '*': # 물이 아닌 지역으로 방문 가능
                    # 다음에 물이 도달할 지역인지 검사
                    visited[nx][ny] = visited[x][y] + 1
                    new_bunnyQ.append((nx,ny))
    # 현재 시간에서 만나지 못할 경우 다음 시간으로 넘김
    bunnyQ = new_bunnyQ
    return False

# 홍수
def start_flood():
    global waterQ, isFail
    new_waterQ = deque()
    while waterQ:
        x,y = waterQ.popleft()
        for i in range(4):
            nx = x + dx[i]; ny = y + dy[i]
            if 0<=nx<N and 0<=ny<M and island[nx][ny] != '*': # 물이 아닌 지역 발견시
                # 토끼보다 물이 먼저 도달한 경우 -> 실패
                if island[nx][ny] == 'C' and visited[nx][ny] == -1:
                    isFail = True
                    return
                island[nx][ny] = '*' # 물이 아닌지역에 물이 도달
                if visited[nx][ny] < visited[x][y]:
                    visited[nx][ny] = visited[x][y] + 1
                    new_waterQ.append((nx,ny)) # 다음 물이 도달할 지역으로 선정
    waterQ = new_waterQ        

isFail = False
minute = 0 # 토끼가 당근을 만나는데 걸리는 시간
while True:
    start_flood() # 홍수 시작
    if isFail: # 당근이 물에 잠겼는지 확인
        print("Umchichi..Umchichi..")
        break
    if is_meet(): # 토끼가 당근에 도달하는데 성공하였다면
        print(minute)
        break
    minute += 1
