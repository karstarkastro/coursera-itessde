<h1> Final Assignment Brief </h1>

In this programming assignment, you will get more experience with Git Version control, write more C-programming code, and integrate your code
with your build system. You will reuse your version control repository and add some new c-programming functions that manipulate memory. You 
will test your code on your host machine, but your code should compile for both the target platform and host platform. We will use the target
platform in future assignments.

### After completing this assignment, you will be able to:

 1. Incorporate a c-program application into your Make and GCC build system
 2. Write c-program functions that manipulate memory
 3. Execute and test your application by simulating it on the host machine
 
### Environment Resources

If you have not already, the VM to develop with is available for download in our supplementary materials.  
Here is a link to those instructions: https://www.coursera.org/learn/introduction-embedded-systems/resources/jDf20

### Version Control and Directory Structure

You are going to reuse your repository that you created in the Course 1 Module 1 final assessment. To get the final assessment provided files, 
download the git repository ese-coursera-assessment.git from github with the following clone link
```
git clone https://github.com/afosdick/ese-coursera-course1.git
```
If you already have this repository cloned to your local machine, be sure to do a git fetch to pull down the latest changes.
```
git fetch origin
```
Complete the following steps to get started:

 1. Open your repository. 
 2. Create a directory called course1. 
 3. Copy your stats code you worked on in Course 1 Module 1 
 4. Copy over your build system that you created in Course 1 Module 2.
 5. Create any new files (as necessary).
 6. Make your first commit here for your altered repository directory structure.
 
```
git commit -m “Reconfiguring repository for Course 1 Final Assessment”
```
Your source tree should look like the following:

karstarkastro_coursera/course1:
 * Makefile
 * sources.mk
 * msp432p401r.lds
 * src/
   - data.c
   - course1.c
   - main.c
   - memory.c
   - stats.c
   - interrupts_msp432p401r_gcc.c
   - startup_msp432p401r_gcc.c
   - system_msp432p401r.c
 * include/
   - common/
     - course1.h
     - data.h
     - memory.h
     - platform.h
     - stats.h
   - msp432/
     - msp.h
     - msp432p401r.h
     - mps_compatibility.h
     - system_msp432p401r.h
   - CMSIS/
     - cmsis_gcc.h
     - core_cm4
     - core_cmFunc.h
     - core_cmInst.h
     - core_cmSimd.h
     
### File Requirements
For this part you will add some new files and new code to some existing files. You will be building off of your
previous work from this course including using your build system from module 2. All code provided must be your 
own work. You may move your makefiles or add multiple makefiles if you choose to do so. You may not use any online
example code or pre-written code.

### main.c

Your main function will be very simple. You will just need to call a function that is defined in the course1.c source file.
However, you need to use a compile time switch to wrap this function to call. This way we can have a simple main() function
that can switch which course deliverable we wish to call by specifying the **-DCOURSE1** compile time switch.
```C
#ifdef COURSE1
  course1();
#endif
```

### stats.c/stats.h

You need to modify your **print_array()** function in **stats.c** so that you can enable/disable debug printing with a compile time switch. 
This compile time switch should be enabled with a VERBOSE flag in the makefile (**-DVERBOSE**). If enabled, the print_array function 
should print as normal. If not defined, nothing should print. Additionally, you need to modify your use of printf to use the PRINTF
macro defined in platform.h

### memory.c/memory.h Requirements

This file should already have some basic memory movement options. Now we will add some memory manipulation functions.

#### uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);
 1. This function takes two byte pointers (one source and one destination) and a length of bytes to move from the source location to the destination.
 2. The behavior should handle overlap of source and destination. Copy should occur, with no data corruption.
 3. All operations need to be performed using pointer arithmetic, not array indexing
 4. Should return a pointer to the destination (dst).
 
 #### uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);
 1. This function takes two byte pointers (one source and one destination) and a length of bytes to copy from the source location to the destination.
 2. The behavior is undefined if there is overlap of source and destination. Copy should still occur, but will likely corrupt your data.
 3. All operations need to be performed using pointer arithmetic, not array indexing
 4. Should return a pointer to the destination (dst).
 
 #### uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);
 1. This should take a pointer to a source memory location, a length in bytes and set all locations of that memory to a given value.
 2. All operations need to be performed using pointer arithmetic, not array indexing
 3. Should return a pointer to the source (src).
 4. You should NOT reuse the set_all() function.
 
 #### uint8_t * my_memzero(uint8_t * src, size_t length);
 1. This should take a pointer to a memory location, a length in bytes and zero out all of the memory.
 2. All operations need to be performed using pointer arithmetic, not array indexing
 3. Should return a pointer to the source (src).
 4. You should NOT reuse the clear_all() function.
 
 #### uint8_t * my_reverse(uint8_t * src, size_t length);
 1. This should take a pointer to a memory location and a length in bytes and reverse the order of all of the bytes.
 2. All operations need to be performed using pointer arithmetic, not array indexing
 3. Should return a pointer to the source.
 
 #### int32_t * reserve_words(size_t length);

 1. This should take number of words to allocate in dynamic memory
 2. All operations need to be performed using pointer arithmetic, not array indexing
 3. Should return a pointer to memory if successful, or a Null Pointer if not successful.
 
 #### void free_words(int32_t * src);

 1. Should free a dynamic memory allocation by providing the pointer src to the function.
 2. All operations need to be performed using pointer arithmetic, not array indexing.
 
 ### data.c/data.h Requirements
 
 This file should do some very basic data manipulation.
 
 #### uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)

 1. *Integer-to-ASCII* needs to convert data from a standard integer type into an *ASCII* string.
 2. All operations need to be performed using pointer arithmetic, not array indexing
 3. The number you wish to convert is passed in as a signed 32-bit integer.
 4. You should be able to support bases 2 to 16 by specifying the integer value of the base you wish to convert to (base).
 5. Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
 6. The signed 32-bit number will have a maximum string size (Hint: Think base 2).
 7. You must place a null terminator at the end of the converted c-string
 8. Function should return the length of the converted data (including a negative sign). Example my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 (including the null terminator).
 9. This function needs to handle signed data.
 10. You may not use any string functions or libraries.
 
 #### int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)

 1. *ASCII-to-Integer* needs to convert data back from an ASCII represented string into an integer type.
 2. All operations need to be performed using pointer arithmetic, not array indexing
 3. The character string to convert is passed in as a uint8_t * pointer (ptr).
 4. The number of digits in your character set is passed in as a uint8_t integer (digits).
 5. You should be able to support bases 2 to 16.
 6. The converted 32-bit signed integer should be returned.
 7. This function needs to handle signed data.
 8. You may not use any string functions or libraries.
 
 ### course1.c/course.h Requirements
 
 These files are new and will hold some final course assessment functions. You will be provided these files from your assessment zip file.
 
 #### int8_t course1();

For this function you will need to call a handful of functions and test your function outputs. You only need to call each of the following 
functions once. These include test_data1(), test_data2(), test_memmove1(), test_memmove2(), test_memmove3(), test_memcopy(), test_memset(),
and test_reverse().

#### int8_t test_data1();

This function will test to atoi and itoa conversions for you.

#### int8_t test_data2();

This function will test to atoi and itoa conversions for you.

#### int8_t test_memmove1();

This function will test non-overlapped memmove.

#### int8_t test_memmove2();

This function will test overlapped memmove where there is overlap of the end of destination and start of the source regions.

#### int8_t test_memmove3();

This function will test overlapped memmove where there is overlap of the start of destination and end of the source regions.

#### int8_t test_memcopy();

This function will test memcopy.

#### int8_t test_memset();

This function will test memset and memzero.

#### int8_t test_reverse();

This function will test reverse.
