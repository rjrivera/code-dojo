import numpy as np  

mat = np.array([[ 1, 2, 3 ],
                [ 2, 3, 10 ],
                [ 4, 6, 7 ]] )

#create function that adds 100 to something

add_100     = lambda i: i + 100

vectorized_add_100  = np.vectorize( add_100 )


## the book is unclear and doesnot work as advertised, as the mat is treated as immutable and vectorization does not persist. 
# apply vectorized function to the vector
print( vectorized_add_100( mat ) )

print( mat )

#this is a broadcast
mat += 100

print( mat )
