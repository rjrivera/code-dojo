import numpy as np

matrix  = np.array([[ 1, 3, 4],
                    [ 3, 5, 8 ], 
                    [ 3, 5, 8 ], 
                    [ 5, 7, 11 ]] )

#reshape matrix -- there are many implications how the new shape is drafted, so pay close attention. 

print( "before: ", matrix )

#the book doesn't explain that in python you have to explicitly redefine, otherwise, the reshape isn't persistent
matrix  = matrix.reshape( 2, 6 )

print( "after: ", matrix )

matrix  = matrix.reshape( -1, 1 )

print( "after: ", matrix )

matrix  = matrix.reshape( 1, -1 )

print( "after: ", matrix )
