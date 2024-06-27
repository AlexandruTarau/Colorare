# Colorare

 - Method: Math
 - Complexity:
   - Time: O(k)
      - Explanation: The for loop => O(k).
   - Space: O(1)
      - Explanation: We do not use any vectors except the ones we used to read the data.
 - I implemented an efficient power function that calculates (b^e) % MOD.
 - In the beginning we set the initial value of the result depending on what is the first input.
    - If it is Horizontal, the result is 6 * power(3, nr - 1) where nr is the number of Horizontal rectangles.
        - Explanation: 2 overlapped horizontal rectangles, each painted in 3 possible colors with the restriction that 2 adjacent rectangles are not the same color result in 6 possible paintings.
        Then for each other such pair of rectangles we multiply by 3 (there are 3 possible color transmutations).
    - If it is Vertical, the result is 3 * power(2, nr - 1).
        - Explanation: 1 vertical rectangle can only have 3 colors so 3 possible paintings. Then for each other following vertical rectangle we multiply by 2 (2 possible color transmutations).
 - For the rest of the input values we do the same thing as above but also adding the cases when after a Horizontal comes a Vertical and when after a Vertical comes a Horizontal.
    - If it's a Vertical after a Horizontal, nothing changes as the vertical one will just take the remaining color (2 colors are already taken by the 2 overlapped horizontal rectangles).
    - If it's a Horizontal after a Vertical, we multiply by 2 (number of possible color transmutations).
 - Each time we modify the result we also do % MOD.
