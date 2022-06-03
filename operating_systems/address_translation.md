# Mechanism: Address Translation

In developing the virtualization of the CPU we focused on a general mechanism known as the LDE(LLimited direct execution). 

The idea of the LDE is very simple. For the most part we let the program run directly on the hardware, except for key points in time where we need the OS to handle special cases.


## The Crux: How to Efficently and flexiby virtualize memory? 

how can we build an efficent virtualization of memory? How do we provide the flexiblity needed by applications? How do we maintain control over which memory locations aan application can access, and thus ensure that application memery accesses are properly restricted? How do we do all of this efficently?


### Address Translation(AKA Hardware based address translation)
THE Goal. We want each user to have their own peach. Each user should have the illusion that they have their own memory. So the OS needs to get involved and keep track of what memory is available and in what ranges that memory is available. Then we can tell the different users you have 1gb of memory and you have 1gb of memory, then the operating system makes sure that user doesn't overuse their memory or assign to another users address space.

#### Interposition is Powerful.
Interposition is a generic and powerful technique that is often used to great effect in computer systems. In virtualzing memory  the hardweare will interpose on each memory access, and translate each virtual address issued by the process to a physical address where the desired information is actually stored. However the general technique of interposition
