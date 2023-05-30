def sort(a):
    n=len(array)
    for i in range(n-1):
        for j in range(n-1-i):
            if(a[j]>a[j+1]):
                a[j],a[j+1]=a[j+1],a[j]

    return a

array=[5,3,8,6,7,2]
x=sort(array)
print('sorted array: ', x)
n=len(x)

min=x[0]
print(min)
max=x[n-1]
print(max)

#built in function
summ=sum(x)
print(summ)

#no built in function
s=0
for i in x:
    s +=i
print(s)

#average
avg=s / n
print(avg)

