N = input()
weight = []
height = []
rank =[]
for i in range(0,int(N)):
  a, b = map(int, input().split(" "))
  weight.append(a)
  height.append(b)
for i in range(0,int(N)):
  num = 0
  for j in range(0,int(N)):
    if weight[j] > weight[i] and height[j] > height[i]:
      num +=1
  print(num+1, end = " ")