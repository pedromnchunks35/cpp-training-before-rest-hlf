# Matters
- Unique pointers
- Shared pointers
- Weak pointers
## Unique Pointers
- Manages a single object
- Only one unique_ptr can own the object at a time
- Ownership can be transferred but not shared
- We can create more instances of the object with different unique pointers but only one pointer will refer to a object
- If the value that we want to retrieve a class is static then the conversation is another since static means class level values which means that we have the same value shared across all the instances of the class
- `usage`
  - For singleton patterns
    - THIS IS A LIE BECAUSE WE CANNOT HAVE ACCESS TO THE DESCONSTRUCTOR
    - If we dont have access to the desconstructor de unique pointer does not work
  - For multithreading environments along with mutex
- [`Exercises`](./exercises/unique-pointers/)
## Shared Pointers
- Instances can manage the same pointer but only when the last pointer ceases it dies
- [`Exercises`](./exercises/shared-pointers/)
## Weak Pointers
- A weaker pointer is a weaker reference of a given object
- Basicly we can get a weak pointer by wrapping a shared pointer
- If we have a weak pointer then that means that if all the shared pointers got converted to weak when we do lock() the reference will be null
- A weak pointer ceases to exist if the shared pointer it wrapped ceases to exist even if there are other shared pointers of that pointer
- We should always verify if the wrapped shared pointer that we got actually got erased or not by using .lock()
- By using .lock() we increase the number of shared pointers
- [`Exercise`](./exercises/weak-pointers/)