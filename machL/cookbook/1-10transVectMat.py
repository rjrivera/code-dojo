import numpy as np

matrix  = np.array([[ 1, 3, 4],
                    [ 3, 5, 8 ], 
                    [ 5, 7, 11 ]] )

# use the T method to perform a transpose
# if we are getting technical, transpose is a MATRIX operation, not a vector operation. 
print( matrix, "\n" )

matrix  = matrix.T

print( matrix, "\n" )
