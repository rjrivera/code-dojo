
##9.1 You are given two sorted arrays, A and B, and A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.

import math

##isMergable determines if B can FIT into A by measuring the sie of B and determining number of A null slots available. 

def isMergable(A, B):
     numNull = 0
     sizeOfB = len(B)
     for x in range(0, len(A)):
          if(A[x] is None):
               numNull += 1
     if(sizeOfB <= numNull):
          return 1
     return 0   

def merge(A, B):
     sorted = False
     tempA = 0
     tempB = 0
     indexI = 0
     indexJ = 0
     print("Here is 'A' as is: ", A)
     ##Calculate at what index None values appear in A
     for x in range(0, len(A)):
          if(A[x] is None):
               indexJ = x
               print("I should see this")
               break
               print("I shouldn't see this")
     ##Insert B into A at index where None values occur
     for x in range(0, len(B)):
          A[indexJ] = B[x]
          indexJ += 1
     print("here is A after B is appended (unsorted): ", A)
     indexI = 0
	
     while(sorted == False):
          sorted = True
##implement bubble sort as an initial solution to "get it live"
	  for x in range(0, len(A)-1):
               if(A[x+1] < A[x]):
                    tempA = A[x]
                    A[x] = A[x+1]
                    A[x+1] = tempA
               if(A[x+1] is None):
                    break ##done to prevent machien from analyizing null (None) values of the Array.
          for x in range(0, len(A)):
               if(A[x+1]<A[x]):
                    sorted = False
                    break
               if(A[x+1] is None):
                    break
          print("Computing, \n")

     print("Array A, after Bubble Sort, is: \n", A)
          

     return

##begin main script

A = [4, 5, 6, 3 ,4, None,None ,None ,None ,None ,None ,None ]
print("The contents of A are as follows: ", A)
print("The task of the developer is to creat a function to combine a second list of similar datatypes into A while still keeping the numbers sorted. The original array 'A' may be unsorted")
B = [2,5,6,7]
print("The contents of B are as follows: ", B)
if(isMergable(A, B)):
     print("B can fit in A")
     merge(A, B)
else:
     print("B can not fit in A")
     print("terminating program")

