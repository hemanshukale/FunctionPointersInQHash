# FunctionPointersInQHash
A way to store function pointers in QHash to map with a key so you can easily call the functions by using key as input.  

When we want to call a function when some event is triggered or some keyword is received, we generally use if-else or switch-case. This is another way to implement that.  

Ex. below make a hashmap of using a key i.e. a QString in this case and function pointer as the value.
We have mapped the QString hour to the function getHour in class SomeClass. 
https://github.com/hemanshukale/FunctionPointersInQHash/blob/100d0908aa32b3da853cb4dfc7a0469dee9418bd/FuncPointers/SomeClass.cpp#L13

Hence, whenever you receive the keyword "hour", you can invoke the function using the code below
https://github.com/hemanshukale/FunctionPointersInQHash/blob/100d0908aa32b3da853cb4dfc7a0469dee9418bd/FuncPointers/SomeClass.cpp#L121
badTimeRequest is the function that will get called when the key does not exist in the QHash

Please find declaration in the header file 
https://github.com/hemanshukale/FunctionPointersInQHash/blob/100d0908aa32b3da853cb4dfc7a0469dee9418bd/FuncPointers/SomeClass.h#L24
and  
https://github.com/hemanshukale/FunctionPointersInQHash/blob/100d0908aa32b3da853cb4dfc7a0469dee9418bd/FuncPointers/SomeClass.h#L30

I have made this example using Qt, but it can be implemented similarly in C++ as well.  
