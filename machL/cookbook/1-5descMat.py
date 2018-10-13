import numpy as np

mat = np.matrix([[0,2,3],
                    [1,2,3],
                    [4,3,2]])

# view rows and columns
print( mat.shape )

# view number of elements (rows * columns)
print( mat.size )

# view number of dimensions
print( mat.ndim )
