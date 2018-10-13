import numpy as np

matrix	= np.array([[ 1, 2, 3], 
			[ 4, 7, 10],
			[ 24, 55, 79 ]])

print( matrix, "\n" )

print( "mean: ", np.mean( matrix ), "\nvariance: ", np.var(matrix), "\nstdev: ", np.std( matrix ), "\n" )
