#1/usr/bin

target = [1, 2, 4, 56, 78, 90, 4, 10]
key = 4

count=0
for i in target:
    if i==key : count+=1

print("Count = ", count)