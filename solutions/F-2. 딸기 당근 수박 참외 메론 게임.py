N = int(input())
selected = ['N']*N # 선택된 N개의 과일, N은 아직 선택되지 않았다는 것을 의미
# 과일 조합은 사전 순으로 증가하는 순서로 출력해야한다.
# 따라서 정렬해놓은 형태로 과일 배열을 사전에 할당한다.
fruits = ['C','K','M','S','W'] 

def dfs(i):
    global selected
    # N개의 과일을 고른 순간 게임은 종료
    if i == N:
        print(*selected)
        return
    # 아직 N개의 과일을 다 고르지 못했다면 재귀적으로 선택
    for curr_fruit in fruits:
        if selected[i-1] != curr_fruit: # 이전에 고른 과일은 선택 할 수 없음
            selected[i] = curr_fruit
            dfs(i+1)
            selected[i] = 'N' # 백트래킹

dfs(0)
