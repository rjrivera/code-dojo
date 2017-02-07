#Chapter 7 QuickSort

## Overview

Another reading on quicksort. I've implemented the algorithm SEVERAL times. This is an exercise in seasoning and simple practice, akin to instrument practice (I think, I am not a musician). Perhaps a better metaphor is practicing my dt rush on an AI? Sure why not. 

## Details

worst case runtime (n^2)
average case nlgn.

most practical choice as it scales very well with large numbers and is on average efficient. 

Sorts in place. so constant space complexity (or linear depending how you look at it, but let's not complicate things, (1))

## Personal Note
I always f!ck this up by failing to properly track the bounds of a partiction, by either dropping the left bound offset or calculating the midpoint erroneously. 

## Bottomline

Commonly known algorithm and is a bitch to implement on the fly if you have little exposure to it. Built around the idea of a pivot value. 
