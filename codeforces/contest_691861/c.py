n = int(input())
for _ in range(n):
    len_arr = int(input())
    arr = list(map(int, input().split()))
    group_of_6 = []
    group_of_3 = []
    group_of_2 = []
    group_of_1 = []
    for i in arr:
        if i % 6 == 0:
            group_of_6.append(i)
        elif i % 3 == 0:
            group_of_3.append(i)
        elif i % 2 == 0:
            group_of_2.append(i)
        else:
            group_of_1.append(i)
    for i in group_of_6:
        print(i, end=' ')
    for i in group_of_3:
        print(i, end=' ')
    for i in group_of_1:
        print(i, end=' ')
    for i in group_of_2:
        print(i, end=' ')