# Hashing

- It is an efficient way of mapping keys of arbitrary size to fixed length keys.
- It provides insertion, deletion and retrieval in constant time.
- Collision is an inevitable part of hashing. Collision Handling is done in two ways :
a. Chaining
b. Open Addressing (Linear Probing, Double Hashing)

In Open Addressing, all elements are stored in the hash table itself. So at any point, the size of the table must be greater than or equal to the total number of keys

## Chaining
- Most basic implementation
- Mostly used when it is unknown how many and how frequently keys may be inserted or deleted.
- Uses lots of space
- Cache performance is not good

> Performance of chaining :
 m = Number of slots in hash table
 n = Number of keys to be inserted in hash table
 a = n/m
 Expected time to search = O(1 + α)
 Expected time to delete = O(1 + α)
 Time to insert = O(1)

## Linear Probing
- Computes the hash function for a key, and puts the key in that location.
- If the location is pre-occupied, the next location is probed for vacancy.
- Inserting a value is good, but deleting from this hash implementation is interesting.


## Double Hashing
- Implementing double hash functions
- First H1(k) is called for getting the place to insert the key. 
- If the first place is already occupied, second hash function H2(k) is called recursively, until we get an empty location or run out of space.
- For linear probing, H2(k) = 1;
