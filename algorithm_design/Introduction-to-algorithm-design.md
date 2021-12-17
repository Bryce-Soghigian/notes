# Introduction to Algorithm Design


## What is an algorithm?
AN algorithm must slove a general, well-speificed problem. An algorithmic problem is specified by describing a complete set of instances or usecases, and providing some expected output.


Lets take a simple example of sorting

### Problem: Sorting
### Input: A sequence of n numbers ranging from a1, ..., an
### Output: The reordering of the input sequence is a strictly increasing sequence of numbers. 

Now you may say, well that works for numbers, but what if we want a more generalized algorithm. What if we are given a list of strings instead of numbers?


Our set is {Mike, Bob, Sally, Jill, Jan} or a list of numbers {1,2,3,4,5,6}. Or what if we want to change what we sort by? What if we want to go in descending order? or what if we want to sort strings based on a different lexographical ordering?

When working through algorithms it is important that we first 

1. Understand The Problem
2. Come up with some generalization of the rules that problem entails
3. Come up with an approach that given that input, we get an output.
4. Reflect on your approach. Are there any bottlenecks? Repeated work?
5. Implementation( Just code it)

Ok so now you get the general idea take a couple minutes to define what you think a general purpose sorting algorithm should cover.

Steven Skinea Defines 3 desirable properties to every algorithm.

1. Correct Consistently
2. Efficient
3. Easy Implementation


Lets look at a solution for sorting


```python

def insertion_sort(s: list, n: int):
	i,j
	for i in range(1, n+1):
	    while j > 0 and (s[j] < s[j-1]):
	    	s[j] , s[j-1] = s[j-1], s[j]
		j = j - 1
```

An algorithm like this i would say meets 2 of those three desired traits.

1. Correctness
for strings and numbers we will always sort in ascending and lexographical order. So our algorithm is correct.
2. Easy implementation
This algorithm took me 1 minute to code out. In interviews if it is taking you longer than 5-7 minutes to code out your algorithm, you did not think through the approach throughly enough.

We failed to reach step 2. This algorithm runs in O(n^2) worst case. But we can sort a list of numbers and strings in nlogn through a variety of other methods. That brings me to our next point

### TRADEOFFS
Easy implementation/Readablity are not always simultaneously acheievable. To sort in n log n there are plenty of ways to acheive this, but all of them are much more complex than a basic insertion sort. 

