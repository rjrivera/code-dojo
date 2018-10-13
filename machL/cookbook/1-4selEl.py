import numpy as np

vect    = np.array([1,2,3,4,5])

mat     = np.mat([[1,2,3],
                    [1,4,7],        
                    [4,7,1]])

print( vect[2], "\n", mat[1,2], "\n" )


print( vect[:], "\n", vect[:3], "\n", vect[3:], "\n", vect[-1] )

print( mat[:,:], "\n" )
