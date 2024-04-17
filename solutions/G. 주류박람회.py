'''
N종류의 술을 모두 사기 위해 P, Q개 술을 준비

그냥 상점끼리에서 B에서 A 뺀 거 값에다가 오름차순 매기고 Q개 산 뒤에 뒤에 남아있는 것들은 p개 사서 출력하면 되는 문제
'''
n,p,q = map(int,input().split())
A = [*map(int,input().split())]
B = [*map(int,input().split())]
C = []
for i in range(n):C.append((B[i]-A[i],i))
C.sort()
result = 0
for i in range(q):
    result += B[C[i][1]]
for i in range(q,n):
    result += A[C[i][1]]
print(result)
