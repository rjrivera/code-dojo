import numpy as np

matrix  = np.array([[ 1, 3, 4],
                    [ 3, 5, 8 ], 
                    [ 5, 7, 11 ]] )

print( matrix, "\n" )

print( "trace: ", matrix.trace() )

#trace calculated
print( "\ntrace as a sum of diagonal: ", sum( matrix.diagonal() ) )
