N = int(input())
selected = [] # 선택된 과일들
# 과일 조합은 사전 순으로 증가하는 순서로 출력해야한다.
# 따라서 정렬해놓은 형태로 과일 배열을 사전에 할당한다.
fruits = ['C','K','M','S','W'] 

def dfs():
    global selected
    # N개의 과일을 고른 순간 게임은 종료
    if len(selected) == N:
        print(*selected)
        return
    # 아직 N개의 과일을 다 고르지 못했다면 재귀적으로 선택
    for fruit in fruits:
        if not selected: # 아직 과일을 선택하지 않은 상태라면 어떠한 과일도 선택이 가능하다.
            selected.append(fruit)
            dfs()
            selected.pop() # 백트래킹
        else: # 과일을 이미 선택한 경우, 이전에 선택한 과일과 현재 과일이 같지 않은 경우에만 선태 가능하다.
            if selected[-1] != fruit:
                selected.append(fruit)
                dfs()
                selected.pop() # 백트래킹

dfs()