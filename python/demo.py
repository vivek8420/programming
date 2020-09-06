import sys
sys.stdin=open('../c++/output.txt','r')
sys.stdout=open('../c++/input.txt','w')

s=list(map(str,input().split(',')))
print(len(s))
for i in s:
	if i=='null':
		print(-1)
	else:
		print(i)