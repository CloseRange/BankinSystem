# BankinSystem
This system is just a self created bank application.
The system starts by creating 1000 randomly generated 'users' with unque card numbers and pins

you are also free to register for your own account. Just type your name and a desired pin.
A unique card number will automaticlly be assigned to you.

------------------------

The bank's data structure is a mock up of binary tree, except using 10 links instead of 2
Account numbers are generated by finding treversing the tree and finding a leaf that is empty. The number is based on the path taken.

Every leaf is also connected via LinkedList style so that saving the accounts is quicker.
This works because only the leaves need to be saved and connecting them directly means there is no need to treverse the whole tree.

The tree will also remember what paths have available card numbers.
This means when creating a new card there is no wasted time trying to find an available number, the search time for finding an empty card is O(n) time
n is how big the card numbers are (by default it's 6 digits, so O(6))

As well finding a card using just a card number is also O(n) time
The biggest time waster comes in saving the bank system.
The system currently treverses every single leaf and saves the card holder's information (if there is any)
This works on O(10^n) time



