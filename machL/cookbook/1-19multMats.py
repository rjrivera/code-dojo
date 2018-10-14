import numpy as np


vect_A  = np.array( [ 1, 2, 3 ] )
vect_B  = np.array( [ 2, 2, 2 ] )

print( "vect A: ", vect_A, "\nvect B:", vect_B,
    "\nmult: ", np.dot( vect_A, vect_B ) )

print( "\n NOW WITH * OPERATORS\nvect A: ", vect_A, "\nvect B:", vect_B,
    "\nmult: ", vect_A * vect_B )
