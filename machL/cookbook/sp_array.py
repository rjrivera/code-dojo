import numpy as np
from scipy import sparse

matrix  = np.array([[0,0],
                    [0, 0],
                    [3, 7]])


# the 'csr' stands for, compressed sparse row, how neat is that? (that's pretty neat)
sp_mat  = sparse.csr_matrix( matrix )

print( sp_mat, "\ndont forget to install scipy, kids!\n" )
