# Move semantics
- Move objects around
- We need to recognize what are lvalues and rvalues to understand it
- A way to move a value without copying it
- [Exercise](./exercises/move-semantics.cpp) `THIS IS FOR MOVE BY CONSTRUCTOR`
- [Exercise 2](./exercises/move-semantics2.cpp) `THIS IS FOR MOVE BY OPERATOR`
# Argument evaluation
- [Exercise](./exercises/argument-evaluation.cpp)
# Macros
- Defining variables or functions almost like a header
- Its usually confusing so we usually should not use
- Basicly we can replace any simbol using preprocessor mechanisms from the compiler
- Its good to use this for creating different logging functions
- We can also create condition macros
- These are very useful for logging systems
- In vscode we can define preprocessor variables in the `tasks.json` passing the variable in the compiler args using `"-DPR_DEBUG"`, in case the variable is `PR_DEBUG` for example
- [Exercise](./exercises/macros.cpp)
# lvalues and rvalues
- Location values
- [Exercise](./exercises/lvalues-and-rvalues.cpp)
# Rule of Zero
- Advices in dont create the basic functions because the compiler already does that for us
  - destructor,copy constructor,copy assignment operator,move constructor and move assignment operator
# Rule of Five
- It says that if a user requires a custom implementation for one of the five normal implementations that we should do it for the five
  - destructor,copy constructor,copy assignment operator,move constructor and move assignment operator
- [Exercise](./exercises/rule-five.cpp)
# Rule of Three
- The same as the five rule but we need the following
  - Destructor,Copy Constructor and Copy Assignment Operator
# RAII
- Life cycle of object (allocation and deallocation of memory)
# PIMPL
- Creating a interface and a IMPL
# CRTP
- Use a template to implement a interface and put there its type
# NON-COPYABLE/NON-MOVEABLE
- We use this in Singleton patterns.. equal the copy and move to delete
# ERASE-REMOVE
- erase and remove are what we should use in containers to remove members
# COPY AND SWAP
- Basicly almost the same as the copy and move but the argument is not a Lvalue or a Rvalue but a value simply
# COPY ON WRITE
- Only copy when a object needs a write, we will be pointing always to that object
- We use a counter to keep track of the number of objects that share de copy