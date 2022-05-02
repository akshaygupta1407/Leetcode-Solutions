Taking two pointers, one at the starting index and other at the ending index. If the first pointer contains odd number and second pointer contains even number, we have to swap those numbers because they are not at the correct position as the even numbers have to come first. If first pointer contains even number, we will increment it and if second pointer contains odd number, we will decrement it.
​
nums = [**3**,1,2,**4**] //p1 is odd and p2 is even, both contains incorrect parity, so we will swap
nums = [**4**,1,2,**3**] // now both contains correct parity numbers, so we will increment p1 pointer and decrement p2 pointer.
nums = [4,**1**,**2**,3] //p1 is odd and p2 is even, both contains incorrect parity, so we will swap
nums = [4,**2**,**1**,3] //now both contains correct parity numbers, so we will increment p1 pointer and decrement p2 pointer.
Hence the output will be: nums = [4,2,1,3]