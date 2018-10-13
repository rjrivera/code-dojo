import numpy as np

matrix = np.array([[ 1, 2, 3],
                    [ 3, 10, 45 ],
                    [ 2, 24, 41 ]])

print( "max: ", np.max(matrix), "\nmin: ", np.min(matrix) )


# so this is the first legit cool thing I've seen that isn't just a 
# "how to do this thing you can in cpp but in python"
# finding a max/min via axis

print( "axis args mapping:\n0 => column\n1 => row\n" )

print( "max val in each column: \n", np.max( matrix, axis=0), "\n min val in each row: \n", np.min( matrix, axis=1) )
