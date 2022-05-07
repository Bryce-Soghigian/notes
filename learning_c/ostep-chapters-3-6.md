[[__TOC__]]
# The Absctaction: The Process Chapter 4

The most fundemental abscraction that the OS provides us users is a **process**

## What is the process
The defintion of a process, infromally is quite simple. Its a running program. 


## **CRUX OF THE PROBLEM** How do we provide the illusion of many CPUs?
ALnthough there are only a few Physical cpus available, how can the OS provide the illusion of a neaerly endless supply of said CPUS

The OS creates this illusion by virtualizing the CPU. By running one process, then stopping it and running another and so forth the OS can promote the illusion that many virutal CPUS exist when in fact there is onlyt one Physical CPU. This basic technique, known as time sharing of the CPU allows us to run many concurrent processes.


So in reality if we want to share a resource, the most simple solution is to just take turns. Now my question is how do we choose who takes their turn first? and how can we properly judge which process should take priority? 



Now back to the tangent on concurrent processes and sharing one physical resource. We can use this concept called **Time Sharing**. Time sharing is a basic techinque used by an OS to share a reso8urce. By allowing the resource to be used for a little while by one entity and then a little while by antoher and so forth the resource in question can be shared by many.



The counter part of this concept of timesharing is spacesharing. Where a resource is divided into chunks among those who wish to use it. For example disk space is naturally a shared resource, once a block is assigned to a  file it is normally not assigned to another file until the user deletes the file. 


The OS uses this concept called a **context switch** which allows it to switch between the execution of many programs. The complicated part is storing the transitional state. 


Back to the question I had on priority. The OS has a process for this called the scheduling policy. The OS uses historical data on a given process to determine its priority and when/if we will execute that process. 


SO we now have the main high level components and concepts to virtualize a CPU POG



## Process API 


At a high level the process api has a couple of core components i will list below


1. Create: Creates a new process.
2. Destroy: Terminaltes a process or allows for exiting a process. OS.EXIT() uses the destroy part of the process api.
3. Wait: Sleeping a process is sometimes useful and this helps the scheduling policy as well so it's included. 
4. Miscellaneous Control: Other than killing or waiting for a process. There are soemtimes other controls that are possible. Like Pausing a program to allow others to run. 
5. Status: Informational Struct that allows us to get info on how long a process has been running, how frequently it runs, what its transitional state is ETC


### Process Creation: IN greater Depth.

One mystery that we should unmask a bit is how programs are transformed into processes. Specifically how does the OS get a program up and running? how do we actually create a process.

1. Load Variables and other state into memory.
2. Allocate memory for the programs runtime stack. 
3. Allocate memory for the programs runtime heap.
4. Label input and output of the program.
5. OS transfers control of new process to the CPU 


### Process States


Now we know what a process is (KIND OF LOL) and how they are created, lets talk about the different stats a process can be in at a given time. The notaion that a process can be in one of thse states arose in early computer systwems . In a simplified view a process can be in one of three states.

1. RUnning: IN the running state a process is running on a processor . This means it is executing instructions. 
2. Ready: iIn the ready steate, a process is ready to run by for some reasion the OS has chosen to wait. 
3. Blocked: IN the blocked state a process ahs performed some type of operation that makes it not ready to run until some other event takes place. 


## Datastructures POG POG POG
THe OS is a program, and like any program it has some key dsa that tracks various relevant pieces of information. To track the state of each process the os will keep some type of process list for all processes that are ready and some additional information to track which process is currently running. The os must also track in some way the blocked processes. 

```c
// the registers xv6 will save and restore
// to stop and subsequently restart a process
struct context {
    int eip;
    int esp;
    int ebx;
    int ecx;
    int edx;
    int esi;
    int edi;
    int ebp;
};
// the different states a process can be in
enum proc_state { UNUSED, EMBRYO, SLEEPING,
RUNNABLE, RUNNING, ZOMBIE };
// the information xv6 tracks about each process
// including its register context and state
struct proc {
char *mem; // Start of process memory
uint sz; // Size of process memory
char *kstack; // Bottom of kernel stack
// for this process
enum proc_state state; // Process state
int pid; // Process ID
struct proc *parent; // Parent process
void *chan; // If !zero, sleeping on chan
int killed; // If !zero, has been killed
struct file *ofile[NOFILE]; // Open files
struct inode *cwd; // Current directory
struct context context; // Switch here to run process
struct trapframe *tf; // Trap frame for the
// current interrupt
};
```

## Interlude: Process API 

### CRUX: HOW TO CREATE AND CONTROL PROCESSES? 
What iterfaces should teh OS present for process creation and control? How should these interfaces be designed to enable powerful functionality, ease of use, and high performance. 

### 5.1 The fork System Call
The fork system call is used to create a new process. However this mf weird on god. Look at this nonsense


```c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("SHEEEESH (pid:%d) \n", (int) getpid());

    int rc = fork();

    if (rc < 0) {
        //We didnt fork bruh
        fprintf(stderr, "Fork Failed \n")
        exit(1);
    }else if (rc == 0){
        // child(new process)
        printf("hello, I am child (pid: %d) \n", (int) getpid())

    }else{
        //parents go down this path.
    }

}
```

## Process key terms
• Each process has a name; in most systems, that name is a number
known as a process ID (PID).
• The fork() system call is used in UNIX systems to create a new process. The creator is called the parent; the newly created process is
called the child. As sometimes occurs in real life [J16], the child
process is a nearly identical copy of the parent.
• The wait() system call allows a parent to wait for its child to complete execution.
• The exec() family of system calls allows a child to break free from
its similarity to its parent and execute an entirely new program.
• A UNIX shell commonly uses fork(), wait(), and exec() to
launch user commands; the separation of fork and exec enables features like input/output redirection, pipes, and other cool features,
all without changing anything about the programs being run.
• Process control is available in the form of signals, which can cause
jobs to stop, continue, or even terminate.
• Which processes can be controlled by a particular person is encapsulated in the notion of a user; the operating system allows multiple
users onto the system, and ensures users can only control their own
processes.
• A superuser can control all processes (and indeed do many other
things); this role should be assumed infrequently and with caution
for security reasons.
