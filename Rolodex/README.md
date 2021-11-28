`Author(s)`: Billy-Bertrand

`Project Description`:

I was given a Rolodex program that reads rolodex data in form of a `CSV` file. <br>
Parts of the code was left for me to complete, for the program to work as intented.
The program was all written in the `main.cpp` file.

_Note: No additional `getters` and `setters` should be added to the `Contact` class._

`Why This Project?`:

This project is the fifth for my Programming class. I learned while working on the project, so I archive it here.

`Program Specification`:

- `Contact` class has its own `.h/.cpp`

- `Rolodex` class has its own `.h/.cpp`

- `Rolodex::DeleteContact` was successfully implemented.

- `Rolodex::DuplicateContact` was 1) successfully implemented 2) using `Contact` class' copy constructor.

- `Rolodex::UpdateContact` was 1) successfully implemented 2) using `Contact` class assignment operator overload.

- `Rolodex::SortBy` was successfully implemented.

`Result`:

```
Enter Rolodex Filename: data_small.csv
Retrieved 5 contacts from file

What would you like to do?
   1) Print Rolodex
   2) Add A Contact
   3) Delete A Contact
   4) Duplicate A Contact
   5) Update A Contact
   6) Sort Rolodex
   7) Exit
Selection: 1

   ID                  Name                                           Address          Phone
--------------------------------------------------------------------------------------------
    1           Butt, James          6649 N Blue Gum St, New Orleans LA 70116   504-845-1427
    2    Darakjy, Josephine            4 B Blue Ridge Blvd, Brighton MI 48116   810-374-9840
    3           Venere, Art         8 W Cerritos Ave #54, Bridgeport NJ 80140   856-264-4130
    4       Paprocki, Lenna                   639 Main St, Anchorage AK 99501   907-921-2010
    5       Foller, Donette                   34 Center St, Hamilton OH 45011   513-549-4561

What would you like to do?
   1) Print Rolodex
   2) Add A Contact
   3) Delete A Contact
   4) Duplicate A Contact
   5) Update A Contact
   6) Sort Rolodex
   7) Exit
Selection:
.
.
.
```
There are many options! Try them out 👻

`Complications & Takeways`:

- I used to think that the destructor in a `C++` class was responsible for destroying a previously created object. But, _No_. Its job is to: _Deallocate any *dynamically* allocated memory locations associated with the object_, before the object itself is destroyed. In that sense, the destructor _prevents_ memory leaks, after an object is destroyed.

- To implement the `Rolodex::SortBy` member function, I knew I had to swap nodes. I first tried to acheive that by swaping the _contents_ (the data) of nodes. It was _not_ the right way do this. Okay, when the nodes are "light" but too much efforts when the nodes "grow," in my opinion. <br> I achieved "node swapping" by using the pointers. <br> After the swap, the pointers had to be re-assigned.

`Potential Improvements`:

- I implemented `Rolodex::SortBy` using the `insertion sort` algorithm. I could implement the algorithm as a function to reduce redundency.

- Implement another sorting function using `merge sort`. I read somewhere that Merge sort performs better on singly linked list.

`Useful Resources`:

N/A