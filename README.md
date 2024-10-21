# IntegerSet-Class-Implementation

This project implements an `IntegerSet` class that provides functionalities for set operations like union, intersection, difference, and complement, as well as methods to insert or delete elements in a set. The class uses an array to represent a set of integers within a fixed range (0-100).

## Features

- **Union of two sets**: Combines two sets by adding all elements from both sets.
- **Intersection of two sets**: Finds the common elements between two sets.
- **Insert an element**: Adds an element to a set if it's within the range.
- **Delete an element**: Removes an element from the set if it exists.
- **Check set equality**: Compares two sets for equality.
- **Set difference**: Returns elements that exist in one set but not the other.
- **Set complement**: Returns the complement of a set (all elements that are not in the set).
- **Print set**: Displays all elements in the set.

## Code Structure

- **`IntegerSet` class**: Contains a private array of size 101 to hold elements. The public methods handle set operations like union, intersection, and insertion/deletion.
- **Global variable `Size`**: Set to 101 to define the maximum size of sets (elements range from 0 to 100).
  
## Member Functions
1. **Default constructor**: Initializes the set to be empty (all elements set to 0).
2. **Parameterized constructor**: Takes an array and its size as arguments, and sets corresponding indices to 1 if the array elements are within the range.
3. **unionOfSets()**: Combines two sets into one.
4. **intersectionOfSets()**: Finds the common elements between two sets.
5. **insertElement()**: Inserts an element into the set.
6. **deleteElement()**: Deletes an element from the set.
7. **PrintSet()**: Prints the elements in the set.
8. **isEqualTo()**: Checks if two sets are equal.
9. **operator -**: Finds the difference between two sets.
10. **operator !**: Finds the complement of a set.

