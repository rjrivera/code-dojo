import numpy as np

matrix  = np.array([[ 1, 3, 4, 1, 5],
                    [ 3, 5, 8 ,1, 6 ], 
                    [ 3, 5, 8, 1, 70 ], 
                    [ 13, 25, 68, 13, 24 ], 
                    [ 5, 7, 11, 1, 49 ]] )

# np retains a linear algebra library - it would be beneficial to learn it
# to learn more about matrix ranks, google it. by-hand, collapse a matrix to echelon form, and count the number of non-zero rows,
# if R < C, rnk = R, else rnk = C

print( np.linalg.matrix_rank( matrix ), "\n" )


