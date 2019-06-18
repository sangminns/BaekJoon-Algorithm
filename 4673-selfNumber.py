def selfNum(num) :
    sum = int(num)
    for i in range(0,4):
        if num == 0:
            break
        else:
            sum += int(num) % 10
            num /= int(10)
    return sum

arr = []
for i in range(1, 10001):
    key = selfNum(i)
    #print(key)
    arr.append(key)
    if i not in arr:
        print(i)
   
# arr = []
# for i in range(1, 10001):
#     #print(key)
#     sum = i
#     num = i
#     for j in range(0,4):
#         if num == 0:
#             break
#         else:
#             sum += int(num) % 10
#             num /= int(10)
#     arr.append(sum)
    
#     if i not in arr:
#         print(i)

   