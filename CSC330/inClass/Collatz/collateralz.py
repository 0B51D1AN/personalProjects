#!/usr/bin/python3


ans=input("Enter an integer for Collatz Conjecture: ")
i=int(ans)
length=0

while i != 1:
    print(int(i))
    length=length+1
    if ( i % 2  == 0 ):
        i = i / 2
    else:
        i = i * 3 + 1

print ( int(i) )
print ("Length of sequence: ", length)
