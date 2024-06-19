# Sorting Algorithms Analysis 

Welcome to the Sorting Analysis project! This repository contains a comprehensive analysis and comparison of various sorting algorithms, focusing on their performance (speed) in different scenarios using mainly C language. This project is my Final Project for my 
Algorithms and Programming course.


## Project Overview
Sorting algorithms are fundamental to computer science, and understanding their efficiency is crucial for optimizing applications. This project aims to:

- Implement Various Sorting Algorithms: Includes implementations of **Bubble Sort, Heap Sort, Insertion Sort, Quick Sort, and Selection Sort**.
- Analyze Performance: Measure and compare the performance of each algorithm using time complexity and practical runtime.
- Visualization: Provide visual representations of the sorting process for better understanding.


## Features
- Algorithm Implementations: Clean, easy to edit (which will be explained in the 'Edit' section).
- Performance Metrics: Detailed analysis of time and space complexity.
- Visualizations: Graphical visualizations of the sorting process.

## How To Use
For the main program, you can run the program immediately or analyze a different algorithm by making a new .h file, put the code, and import it in the main program (Sorting Analysis.c). The program will ask the user the add three data; 
- Initial Length: The number of the first array length of given to the algorithms.
- Length Ratio: The ratio between each array length of row of data.
- Epoch: The number of rows of the table.
A table will then be initialized and the user can run the simulation to see how the algorithm speed changes across different array sizes. The output of the main program will be a table showing all of the data with colors such as green, yellow, and red, depending on their time taken to sort the array. The output/table example can be seen here below.

<div align="center">
    <img alt="Program Output" src="images/Program Output.jpg">
</div>

The matlab program is just to analyze the data more mathematically, it uses fminsearch to get the function created by the data of the particular algorithm which is taken from the average time complexity of that current algorithm. The output of the program can be seen below.

<div align="center">
    <img alt="Matlab Output" src="images/Matlab Output.png">
</div>