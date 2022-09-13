# Solve 0hh1 Puzzle!

## Abstract
An auto-solver for the [0hh1](https://github.com/florisluiten/0hh1) game, using backtracking.

## Introduction
### The Game 0hh1
0hh1 is a free puzzle game. Get the game on its [Official Website](https://0hh1.com/) / [Google Play](https://play.google.com/store/apps/details?id=com.q42.ohhi) / [IOS Store](https://itunes.apple.com/us/app/0h-h1). 
The game has these rules:
1. Three adjacent tiles of the same color in a row or column isn't allowed. 
2. Rows and columns have an equal number of each color. 
3. No two rows and no two columns are the same. 

### The solver
Since this game could kill plenty of time, we made a auto-solver to free our brains.

## Example / How to use
Start a new game and see the initial board may looks like: 

```
_ Y _ _ B Y
_ B Y _ _ B
_ _ _ _ _ _
B Y _ Y B _
B _ _ _ _ _
_ _ _ _ B B
```

It's $6 \times 6$ matrix, so the size of problem is $6$. 

Write the color in number presentation, 0 for empty blocks, 1 and 2 for two types of blocks: 

```
0 1 0 0 2 1
0 2 1 0 0 2
0 0 0 0 0 0
2 1 0 1 2 0
2 0 0 0 0 0
0 0 0 0 2 2
```

Now run the solver and you'll get output below. I use character `-` and `|` to present 2 types of blocks. You can feel free to mofify it. 

```
| - - | | - 
- | - | - | 
- | | - - | 
| - | - | - 
| | - | - - 
- - | - | | 
```

## Conflict of Interest
I'm not the person who made this game, and I have no conflict of interest to declare.
