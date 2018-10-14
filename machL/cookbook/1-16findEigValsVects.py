import numpy as np

matrix  = np.array([[ 1, 3],
                    [ 3, 5 ] 
                    ] )

print( matrix, "\n" )

eigenvalues, eigenvectors = np.linalg.eig( matrix )

print( "eigV: ", eigenvalues, "eigVect: ", eigenvectors, "\n" )
