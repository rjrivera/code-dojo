import numpy as np


vect_A  = np.array( [ 1, 2, 3 ] )
vect_B  = np.array( [ 2, 2, 2 ] )



print( "vect A: ", vect_A, "\nvect B:", vect_B,
    "\nadd: ", np.add( vect_A, vect_B ),
    "\nsub: ", np.subtract( vect_A, vect_B ) )

print( "\n USING + - OPERATORS\nvect A: ", vect_A, "\nvect B:", vect_B,
    "\nadd: ", vect_A + vect_B,
    "\nsub: ", vect_A - vect_B )



