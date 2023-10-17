# Solve Takuzu Puzzle!

## Abstract
An auto-solver for the [Takuzu](https://en.wikipedia.org/wiki/Takuzu) game, using dfs and backtracking.

## Introduction
### The Game Takuzu
Takuzu, also known as Binairo, is a logic puzzle involving placement of two symbols, often 1s and 0s, on a rectangular grid. The objective is to fill the grid with 1s and 0s, where there is an equal number of 1s and 0s in each row and column and no more than two of either number adjacent to each other. Additionally, there can be no identical rows or columns. Similar to [Sudoku](https://en.wikipedia.org/wiki/Sudoku), each puzzle begins with several squares in the grid already filled. 

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
