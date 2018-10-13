import numpy as np

#creating a matrix

# the ley man's way
matrix = np.array([[1, 3],
                    [3, 5], 
                    [4, 7]])

# the scientist's way
matrix_obj = np.mat([[1, 3],
                    [3, 5], 
                    [4, 7]])

print( matrix_obj, "===\n" )

#BUT WAIT THERES MORE!! THIS ONE'S A SCREAMER!!!
# turns out mats are not rec'd because most numpy operations return arrays, derp
