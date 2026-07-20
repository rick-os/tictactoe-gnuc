Simple tictactoe cli game made with gnu c.

# How to execute:
To play, open your terminal and type:
```
cd <PATH-TO-REPO>

gcc tictactoe.c -o game

./game
```

# Controls:
It will request the row and column you want to place your number, then you insert using you keybord. After player 1 places his number, player 2 need to do the same, using the same logic, he'll need to insert the row and column that he wants to place his number.
The game will continue until someone complete one row/column/diagonal or the number of iterations is equal to 9 ( i = 8 — because it starts at 0).
After that, you can choose between y, to continue playing, or n, to stop the algorithm.
