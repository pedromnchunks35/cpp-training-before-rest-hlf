# Vector
- Dynamic array
- O(1) access time
- O(n) insertion and deletion in the middle (shift of elements)
- O(1) end of the list
- `usage`  
  - When we want to add or remove elements ocassionally but access by position frequently
# Deque (Double-ended queue)
- Allows fast deletion
- Slower for random access
- Fast access to end and start
- More memory overhead
- Good to add or remove elements in the start and in the end
# List 
- Double Linked List
- Const time inserting and deleting in the middle of the list (constant time)
- Good for lot of insertions and deletes in the middle of the list
- O(n) for access
- Bad for random access
# SET
- O(log n) for insertions,deletions and lookups
- Does not allow duplicate elements
- Ideal for maintaining a collection of unique elements with automatic sorting
# Multiset
- Similar to set but allows duplicate elements
- For maintain multiple elements in sorted order
# Map
- Collection of key value pairs, keys unique
- O(log n) for insertions,deletions and lokups
- Keys are automatically sorted
- Ideal to associative arrays (a key per value)
# MultiMap
- Same as map but allows duplicate values
# HASH COLLISION CONCEPT
- Unsorted map,unsorted set,set,map
# [Exercises](./exercises/)