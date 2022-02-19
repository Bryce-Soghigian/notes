# SP 171 List of completion

This is the fully archive of my approaches and solutions as well as optimal solutions to SP



# Editorials 

[Two Sum](https://leetcode.com/problems/two-sum/discuss/1770089/SP-171-or-Two-Pointers-or-Hashmap-With-Complement-or-Python)

[Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/discuss/1770156/SP-171-or-Seen-Set-or-Modify-List-or-Floyd-Slow-and-Fast-or-Python)

[Middle Of Linked List](https://leetcode.com/problems/middle-of-the-linked-list/discuss/1770287/SP171-or-Get-Length-or-Slow-and-Fast-Pointers-or-Python)

[Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/discuss/1770377/SP-171-or-String-Reverse-or-Reverse-List-or-Fast-and-Slow-or-OOP-or-Python)

[Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/discuss/1770412/SP-171-or-Dummy-Node-Pattern-or-Python)

[Add Two Numbers](https://leetcode.com/problems/add-two-numbers/discuss/1770439/SP-171-or-Elementary-Math-or-Python)

 

## Template For Editorials



#### Problem Description

```md
Copy Paste of Problem Description from leetcode
```

#### Clarifying Questions

#### Ideas or Intuitions 

#### Approaches

#### [Approach] Approach 1

```python
class Solution:
	def solve():
        pass
```

##### Time Complexity

##### Space Complexity

#### [Approach] Approach 2

```python
class Solution:
	def solve():
        pass
```

##### Time Complexity O(N)

##### Space Complexity: O(N)

# Linked List Problems and Two Pointers



## Fast and Slow

### [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/discuss/1770156/SP-171-or-Seen-Set-or-Modify-List-or-Floyd-Slow-and-Fast-or-Python)

#### Problem Description

```md
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 
```

#### Clarifying Questions

1. Are the values in the linked list unique ? 
2. How many cycles are there in the list?
3.  Can we Modify the linked list?

#### Ideas or Intuitions 

Store things we have seen before, use floyd slow and fast pointers or modify the list

#### Approaches

1. Seen SET
2. Slow And Fast Pointers
3. Modify the original linked list

#### [Approach] Seen Set

A simple approach would be to iterate through all of the list nodes, storing each one in a seen set. If we ever encounter a node we have seen before, we found a cycle.

This is expensive in terms of space, we have to store all of the nodes in this set. Each class object can be hashed as they have a unique id for each class instance. So duplicates wont really be a problem as if we store the entire linked list wont be a problem.

```python
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        seen: set = set()
            
        curr = head
        while curr:
            if curr in seen:
                return True
            seen.add(curr)
            curr = curr.next
       return False # got through the entire list without getting stuck.

```

##### Time Complexity: O(N) to iterate through all nodes

##### Space Complexity O(N) worst case we store every list node.

#### [Approach] Modify Original Linked List

Iterate through the linked list. Modify each nodes .val attribute to be a string. If we ever see a value that has been modified, we can return True cause we found the target node.

```python
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        curr = head
        while curr:
            if isinstance(curr.val, str):
                return True
            curr.val = str(curr.val)
            curr = curr.next
       return False
```

##### Time Complexity O(N)

##### Space Complexity: O(1)

#### [Approach] Slow and Fast Pointers

We Can move one pointer through the linked list faster than the other pointer. we will eventually reach that other pointer.



Lets Prove that with a parity proof(Prove even case and odd case) simulating our pointers



1 -> 2 -> 3 -> 4  cycle-> 1

s

​      f

1 -> 2 -> 3 -> 4  cycle-> 1

​      s

​                       f

1 -> 2 -> 3 -> 4  cycle-> 1

​               s

​      f

1 -> 2 -> 3 -> 4  cycle-> 1

​                       s

​                       f

Our pointers meet at 4 for the odd case where the cycle starts

1 -> 2 -> 3 cycle-> 1

s

​     f 

1 -> 2 -> 3 cycle-> 1

​      s

f

1 -> 2 -> 3 cycle-> 1

​               s

​               f   

Our pointers then meet where the cycle starts

```python
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head:
            return False
        
        slow = head
        fast = head.next
        
       	while slow != fast:
            if not fast or not fast.next:
                return False # reached teh end of a list
            slow = slow.next
            fast = fast.next.next
       return True
```

##### Time Complexity O(N)

##### Space Complexity: O(1)

### [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/discuss/1770287/SP171-or-Get-Length-or-Slow-and-Fast-Pointers-or-Python)

#### Problem Description

```md
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
```

#### Clarifying Questions

1. In the case of  an even list do we take the average of the two middlemost nodes? or should we return the second one?
2. will we ever have a number of nodes greater than 2 ^ 32? 

#### Ideas or Intuitions 

First intution is to move a pointer with double the speed of another pointer. our slower pointer will reach the middle of the linked list 

#### Approaches

1. Get length of list and then iterate through linked list again until we find the middle val (middle_val = length // 2)
2. Slow and Fast pointers

#### [Approach] Midpoint Strategy

1. Iterate through list and get the length
2. Reiterate till we reach teh middle of the list

```python
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        midpoint = 0
        while curr:
            midpoint += 1
            curr = curr.next
        midpoint = midpoint // 2
        curr = head
        while midpoint != 0:
            midpoint -= 1
            curr = curr.next
        return curr
        
```

##### Time Complexity: O(2n)

##### Space Complexity: O(1)

#### [Approach] Slow and Fast

If we want to find the middle element, it stands to reason that moving a pointer twice as fast as another pointer, when the fast pointer reaches the end the slow pointer will have reached the middle.



Basic proof

midpoint = len(list) // 2

1/2 * len(list) == midpoint 

```python
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
       return slow
```

##### Time Complexity O(N)

##### Space Complexity: O(1)

### [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/discuss/1770377/SP-171-or-String-Reverse-or-Reverse-List-or-Fast-and-Slow-or-OOP-or-Python)

#### Problem Description

```md
Given the Head of a singly linked list, return true if it is a palindrome.
```

#### Clarifying Questions

1. Will be given even and odd linked list lengths?
2. Will we be given null linked lists
3. Will we only have integers as values in the linked list?
4. Is the linked list only singly linked list

#### Ideas or Intuitions 

A palindrome is the same reversed as it is normal

1 -> 4 -> 5 -> 4 -> 1

is the same as 

1 <- 4 <- 5 <-4 <- 1



So if we reverse a linked list and look at the lists side by side we can see if they are palindromic.

But reversing the linked list and then iterating through both lists is expensive. O(2n). In the case of 

10000000000000000 nodes this is too slow.

What if we only reverse half of the list? 

We can then compare the head to the tail and so on



1 -> 4 -> 5 <- 4 <- 1

s

​							e

is start same as end? 

​	if true move list forward

else:

​	reutrn False



#### Approaches

#### [Approach] Reverse String

1. Store values in string

2. Reverse string

3. Compare reversed String and original string

   ```python
   class Solution:
       def isPalindrome(self, head: Optional[ListNode]) -> bool:
           output = ""
           curr = head
           while curr:
               output += str(curr.val)
               curr = curr.next
           return output[::-1] == output
   
   ```

   ##### Time Complexity: O(2N)

   ##### Space Complexity O(N)

#### [Approach] Reverse Linked List and compare the two lists

1. Create a copy of the list
2. Reverse our copy
3. Check to see if reverse has all of the same values. 

Since some of these actions are reusable, lets create a linked list class where each linked list has these special methods

```python
class ListNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
        
class LinkedList:
    def __init__(self, head):
        self.head = head
    def reverse(self):
        prev = None
        curr = self.head
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        self.head = prev
    
    def copy(self):
        curr = self.head
        new_head = ListNode("*")
        pt = new_head
        while curr:
            pt.next = ListNode(val=curr.val)
            pt = pt.next
            curr = curr.next
        return new_head.next
    
    def __eq__(self, other):
        other_pt = other.head
        local_pt = self.head
        while other_pt or local_pt:
            if local_pt and not other_pt:        
                return False
            if not local_pt and other_pt:
                return False
            if other_pt.val != local_pt.val:
                return False
            other_pt = other_pt.next
            local_pt = local_pt.next
        return True
    
    def __str__(self):
        string_rep = []
        curr = self.head
        while curr:
            string_rep.append(str(curr.val))
            string_rep.append('->')
            curr = curr.next
        string_rep.pop()
        return "".join(string_rep)
            
class Solution:
    def isPalindrome(self, head):
        original_list = LinkedList(head=head)
        copy_list = LinkedList(head=original_list.copy())
        copy_list.reverse()
        return original_list == copy_list
```

##### Time Complexity O(3n)

##### Space Complexity O(N) For the copy of the linked list.

#### [Approach] Reverse Half of the Linked List

We can find the middle of the linked list, and then reverse half of that linked list.

Then we move our pointers inward.

1. Find middle of linked list [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/discuss/1770287/SP171-or-Get-Length-or-Slow-and-Fast-Pointers-or-Python)
2.  Reverse from middle to end
3. move pointers and see if our linked lists are equal

```python
class ListNode:
    def __init__(self, val, next=None):
        self.val = val[Add Two Numbers](https://leetcode.com/problems/add-two-numbers/discuss/1770439/SP-171-or-Elementary-Math-or-Python)
        self.next = next
class LinkedList:
    def __init__(self, head):
        self.head = head
    def reverse(self):
        prev = None
        curr = self.head
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        self.head = prev
    
    @property
    def val(self):
        if not self.head:
            return None
        return self.head.val
    
    def _next(self):
        if not self.head:
            return
        self.head = self.head.next
        return
            
class Solution:
    def find_middle_node(self, head): # TC O(N//2)
        fast = head
        slow = head
        while fast.next is not None and fast.next.next is not None:
            fast = fast.next.next
            slow = slow.next
        return slow
    
    def isPalindrome(self, head):
   
        reversed_half = LinkedList(self.find_middle_node(head))
        reversed_half.reverse()
        
        
        while reversed_half.val is not None and head:
            if reversed_half.head is None:
                return True
            if reversed_half.val != head.val:
                return False
            
            reversed_half._next()
            head = head.next
        return True
```

##### Time Complexity O(N)

##### Space Complexity: O(1) Since this approach only uses references of the original head.

### [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/discuss/1770412/SP-171-or-Dummy-Node-Pattern-or-Python)

#### Problem Description

```md
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
```

#### Clarifying Questions

1. Will we ever have these items at the tail of our list? 
2. Will they ever be at the head?
3. What constitutes a deletion? Do we need to free the memory or can we simply remove the pointer

#### Ideas or Intuitions 

Ok so if we want to delete a node in the linked list there are a couple of ways to do this. One would be to create a doubly linked list, where we have easy access to the prev and next pointer of a given list item.  We can remove from the list and then get a singly linked list. 



A less expensive way and less Object oriented way would be to simply keep a prev pointer and every time we see a value we want to delete, we simply do that.

#### Approaches

#### [Approach] Sentinel Node pattern

1. Declare Sentinel or dummy Node
2. Iterate through linked list
3. Every time we see target deletion value, we simply delete the node by setting prev.next = curr.next if curr.next is not none

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        curr = head
        sentinel = ListNode("*", head)
        prev = sentinel
        while curr:
            if curr.val == val:
                prev.next = curr.next
            else:
                prev = curr
            curr = curr.next
        
        return sentinel.next
```

##### Time Complexity O(N)

##### Space Complexity O(1)

##### 

### Remove Duplicates from Sorted List

### Linked List Cycle II 

### [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/discuss/1770439/SP-171-or-Elementary-Math-or-Python)

#### Problem Description

```md
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
```

#### Clarifying Questions

1. Are Linked Lists of equal length? 
2. Are linked list nodes the best way to store this data?
3. What is the shape of our nodes
4. Can we add some special properties or define our own nodes? 

#### Approaches

1. Elementary Math

#### [Approach] Elementary Math

We can simulate math as we did it in elementary school. We add teh numbers one by 1. 

Since we are essentially adding linked lists lets abscract this list to a class.



1. We need a carry variable and two pointers which are pointing to the start of each linked list.

2. while we have numbers or a carry value

3. add together the current two pointers.

   1. if a node is none we want to set its value equal to zero

      

4.  add together our two operands

5. if the sum of our operands exceeds 10 

6. transfer sum to the carry

7. add value to our output list

8. after all these iterations have been completed we want to return our output list

```python

class ListNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
    

class LinkedList:
    def __init__(self, head):
        self.head = head
    
    def __add__(self, other):
        if not self.head and not other:
            return None
        if not self.head:
            return other.head
        if not other:
            return self.head
        
        c_l1, c_l2 = self.head, other.head
        output = ListNode(val="*")
        output_pt = output
        carry = 0
        
        while c_l1 or c_l2 or carry:
        
        
            operand_one, operand_two = c_l1.val if c_l1 else 0, c_l2.val if c_l2 else 0
            summation = operand_one + operand_two + carry

            if summation < 10:
                output_pt.next = ListNode(val=summation)
                carry = 0

            else:
                ref = str(summation)
                output_pt.next = ListNode(ref[1])
                carry = int(ref[0])


            output_pt = output_pt.next
            c_l1 = (c_l1.next if c_l1 else None)
            c_l2 = (c_l2.next if c_l2 else None)
        
        return output.next
        
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        return LinkedList(l1) + LinkedList(l2)
```

##### Time Complexity O(max(M, N))

##### Space Complexity O(max(M, N))

### Remove Nth Node From End Of List

### Sort List

### Reorder List

## In place Reversal of Linked List

### Reverse Linked List

### Reverse Linked List II

### Rotate List

### Swap Nodes in Pairs

### Odd Even Linked List

### Reverse Nodes in K-Group





## Two Pointers

### Is Palindrome

```python
class Solution:
	"""
	Docstring explaining problem
	
	# Clarifying Questions
	
	# New Ideas or intuitons
	This problem is about identifying that a string is a palindrome.
	
	What are some of the things we can do to a
	# Approaches (Have at least 2)
	## Reverse and Compare
	## Two pointers converging Inward
	
	"""
    def is_pal_reverse(self, string):
        """
        Compare the string with itself reversed.
        O(N) Time O(N) Space
        """
        return string[::-1] == string
    
    def is_palindrome(self,some_string):
        """
        TC: O(N) SC O(2)
        1. Declare two Pointers start and end
        2. Iterate these pointers moving them inward
		3. check each time if they are equal
        
        """
        start = 0
        end = len(some_string) - 1
        while start <= end:
            if some_string[start] != some_string[end]:
                return False
            start += 1
            end -= 1
        return True
    
```

### [Two Sum](https://leetcode.com/problems/two-sum/discuss/1770089/SP-171-or-Two-Pointers-or-Hashmap-With-Complement-or-Python)

#### Problem Description

```md
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
```



#### Clarifying Questions

1. Is the input array sorted?
2.  What is the largest int we will deal with
3. Are we only going to have integers?\
4. is this going to be repeatedly called for many numbers? 
5. Will we always be given a valid input array?

#### Ideas or Intuitions 

If the input array is sorted we can use a greedy approach and converge pointers inward. We can also use identity math to search for complements 

#### Approaches

#### [Approach] Search For Complements

For each number we want to check to see if complement exists. 

since we are only returning the one sum we can create some sort of mapping

1. create a map for storing complements

2. Iterate through nums

   2a. create a complement ( complement == target - nums[i])

   2b. check to see if complement exists in hashmap

   2c. add num and its index to hashmap

```python
class Solution:
	def two_sum(self, nums, target):
        complements = {} # number -> index
        
        for i,val in enumerate(nums):
            complement = target - val
            if complement in complements:
                return [i, complements[complement]]
            complements[val] = i
       return [-1, -1]
```

##### Time Complexity: O(N)

O(N) to iterate through entire list

##### Space Complexity: O(N)

To store each number because worst case we have a list of entirely unique numbers, so worst case we have to store up to n values.

#### [Approach] Two Pointers

If the input array is sorted, we can have two pointers, starting at the smallest item in list, the other on the largest value.

1. Declare a start and end pointer 

2. Iterate while our pointers arent at the same index

   2a. if nums[start] + nums[end] is less than target:

   ​	increase the start pointer as to try the next largest

   2b else 

   ​	this means we were too large  so we want to decrease our big number

   ```python
   class Solution:
       def two_sum(self, nums, target):
           start = 0
           end = len(nums) - 1
           while start <= end:
               small_num, large_num = nums[start], nums[end]
               summation = small_num + large_num
               if summation < target:
                   start += 1
              	elif summation > target:
                   end -= 1
               else:
                   return [start, end]
          return [-1, -1]
   ```

   ##### Time Complexity O(N)

   ##### Space Complexity: O(N)

   

### Merge Two Sorted Lists

### Squares of a Sorted Array

### Backspace String Compare

### Find the duplicate Number 

### 3 Sum

### 3 Sum Closest

### Subarrays with Product Less than K

### Sort Colors

### Container with the most Water

