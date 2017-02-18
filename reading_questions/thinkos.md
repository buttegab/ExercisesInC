## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.
A development environment

2) Name two advantages of static typing over dynamic typing.
There is never any confusion for the user or the computer what the type of something is.
Code readability is much higher with unambiguous types.

3) Give an example of a static semantic error.
Passing a float as an index of an array.

4) What are two reasons you might want to turn off code optimization?
You might be doing something that could be considered inefficient deliberately.
You want to avoid seemingly nonexistant bugs that appear only after compiling.

5) When you run `gcc` with `-S`, why might the results look different on different computers?
Assembly functions differently on different machines, because it's so close to machine code, so different machines would go about the same process with slightly different commands.

6) If you spell a variable name wrong, or if you spell a function name wrong, 
the error messages you get might look very different.  Why?
The code will misinterpret you as trying to declare a new variable incorrectly or a new function incorrectly and, in it's attempt to figure out if that's ok, misreads the rest of the code too, which is why the first error message is usually the only one worth reading.

7) What is a segmentation fault?
An error that occurs when you try to access memory outside of the program's alloted range.

## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).
Amazon. We never have to know if what we are ordering is housed anywhere near where we order it to be delivered to, but it will end up there anyway.

2) What is the difference between a program and a process?
A process does one thing, while a program might use many processes to do many things at once.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?
It allows the user to easily switch between windows without using a ton of processing power. It creates the illusion that the computer is always running all of the windows currently open, while instead having all but the active ones sleeping.

4) What is the kernel?
A part of the operating system responsible for core processes.

5) What is a daemon?
A process that runs in the background.
 

## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?
6 bits

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?
4294967296 characters


3) What is the difference between "memory" and "storage" as defined in Think OS?
Memory is volatile and consists of RAM, storage is hard disk space and is not volatile. Volatile meaning that if the system suddenly lost power, volatile data would be lost and non volatile data would be safe.


4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?
GiB is equal to 2^20 where GB is equal to 10^6.
GiB is 104% as much as GB.

5) How does the virtual memory system help isolate processes from each other?
Virtual memory allows the OS to work with virtual addresses and ultimately map them to physical addresses in the hardware. The virtual space allows the OS to give different processes different spaces to work in in which they cannot interact with the same information at the same time. Also, if two processes manage to generate the same virtual address, there is no collision problem because everything is managed by the OS which keeps any conflict from happening.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?
The heap is essentially unused stack space, so there is no reason to allow them to mix. A logical progression of turning heap into stack and stack back into heap is much easier to understand and work with when they each have their own sections of address space. Also, they technically aren't at opposite ends of the address space, they're right next to each other with stack being on top of heap.

7) What Python data structure would you use to represent a sparse array?
A hashmap, or list of lists with some hashing function that roughly equally distributed elements to the sublists.


8) What is a context switch?
When the OS interrupts a running process, saves its state, and changes to another process.

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.
  
1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).  
It does: 
Address of p is 0x17f7010
Address of n is 0x17f70a0 //new allocated memory


2) Add a function that prints the address of a local variable, and check whether the stack grows down.  
It does:
Address of local is 0x7ffcd78bea0c
Address of local2 is 0x7ffcd78be9ec

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.
20 bytes.

## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.
Opening a file and having it be read all at once is the abstraction we get, but in reality the file is likely read in parts, across different blocks of storage. The reading of subsequent blocks to get the information is so fast that we don't notice it, and on a small scale it doesn't slow the program down very much, but it is there.

2) What information do you imagine is stored in an `OpenFileTableEntry`?
The pointer that keeps track of where in the file has already been read and where still needs to be read. I think it's possible there is other information like the file size and address stored in the structure.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?
They tend to do other things during the loading, like throw cycles at things that need work done, saving information, or preloading information that is likely to be used soon.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?
The file was still in memory and had not been moved to storage yet. Therefore, when the power was cut, memory, being volatile, lost all state information, so the file was missing.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?
FAT would be more effective at adding new blocks because of its implementation being similar to that of a linked list. An inode would be more effective for searching because searches wouldn't have to go in order, and the search could look for metadata like file size and last modified, when FAT could not.

6) What is overhead?  What is fragmentation?
Overhead is the amount of space required for the allocator to reside. It is ideal for this to be minimized so there is more room for information to be stored. Fragmentation is when blocks are partially or completely unfilled. 

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?
Imagining everything as a stream of data is useful for understanding how programs receive information. It falls short because in the end, it is an abstraction and not everything is read from or written to the same way. In most cases that won't matter, but the lower level you go, the more likely it is to have an effect.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

b) Writing to unallocated memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.


3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the `gcc flag -lpthread` do?

3) What does the argument of `pthread_exit` do?

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?


 
## Chapter 11


### Semaphores in C
