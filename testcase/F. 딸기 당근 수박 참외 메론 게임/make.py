def dfs(i, N, selected, fruits, output_file):
    # N개의 과일을 고른 순간 게임은 종료
    if i == N:
        output_file.write(' '.join(selected) + '\n')
        return
    # 아직 N개의 과일을 다 고르지 못했다면 재귀적으로 선택
    for curr_fruit in fruits:
        if i == 0 or selected[i-1] != curr_fruit:  # 처음 시작할 때는 이전 과일이 없으므로 추가 조건
            selected[i] = curr_fruit
            dfs(i+1, N, selected, fruits, output_file)
            selected[i] = 'N'  # 백트래킹

# 과일 목록
fruits = ['C','K','M','S','W']

# N의 값 1부터 8까지 실행
for N in range(1, 9):
    selected = ['N']*N  # 초기 선택된 과일 배열
    with open(f"{N}.out", "w") as file:
        dfs(0, N, selected, fruits, file)
    with open(f"{N}.in", "w") as file:
        file.write(str(N))
