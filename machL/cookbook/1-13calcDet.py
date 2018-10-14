import numpy as np

matrix  = np.array([[ 1, 3, 4],
                    [ 3, 5, 8 ], 
                    [ 5, 7, 11 ]] )

print( matrix, "\n" )

determinant  = np.linalg.det( matrix )

print( "det: ", determinant, "\n" )
