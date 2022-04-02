## Rotate n x n matrix by 90 degree

1) Transpose matrix (every i, j cell becomes j, i cell)
2) reverse matrix (every k, i cell becomes, k, j cell)

## Shifting Elements in an array

- use (i + k) % n formula to find new index of a shifted item, where i is the 
    ith element, k is the number of spots element is shifted and n is the size 
    of an array.


-----

# String

to find if string has balanced parentheses. If at some point balance is < 0 this means that at that char there are more closed parentheses which makes it unbalanced.

pseudo-code for checking if string has balanced parentheses:

```
function is_balanced_parentheses(string)
    balance = 0
    for each char in the string
        if char == "("
            balance = balance + 1
        if char == ")"
            balance = balance - 1
        if balance < 0
            return false
    return balance == 0
```
