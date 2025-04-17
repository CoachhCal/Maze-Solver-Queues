# Maze Solver

## Overview
A C++ console application designed to solve mazes using **queues**. The program reads a **25x25 maze** from a text file, processes it, and outputs the solved maze in another text file, marking the correct path with `#`.  

## Features
- **Queue-Based Pathfinding:** Utilizes a custom queue implementation to find the shortest path.
- **Text File Handling:** Reads maze data from a file and writes the solution to a new file.
- **Dead-End Avoidance:** Ensures only the correct path is marked without unnecessary branching.

## Implementation Details
This project **avoids recursion** by utilizing **queues** to manage traversal efficiently.

- **Queue Data Structure:** Stores coordinates to explore next.
- **File Processing:** Reads `.txt` maze files and outputs solved `.txt` files.
- **Maze Representation:** Uses a **2D character array** to process maze data.

## Usage
Three empty mazes are provided in the tests folder:
- test.txt
- test2.txt
- test3.txt

  
To execute the program from the command line, navigate into the cmake-build-debug folder and run:

```sh
Maze_Solver.exe ../tests/<filename>
```

The solved maze will be saved in the 'solved' folder.
