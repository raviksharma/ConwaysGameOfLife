ConwaysGameOfLife
=================

Toy Implementation of Conway's game of life to practice C++/OOP

	/* 
	* Conway's Game of Life
	* =====================
	*
	* Evolution rules - 
	*
	* Any live cell with fewer than two live neighbours dies, as if by loneliness.
	* Any live cell with more than three live neighbours dies, as if by overcrowding.
	* Any live cell with two or three live neighbours lives, unchanged, to the next generation.
	* Any dead cell with exactly three live neighbours comes to life.
	*
	* Assumption: cells outside the Grid are considered dead
	*/

Usage: executable [<option> <value>]
=====
options	:
-run	: <test case file>		//contains test case
-output	: <test case result file>	//contains result of the test case
-format	: grid|text			//grid - 2D view of the Grid (X - alive cell, . - dead cell), text - test case compliant view, contains alive cell indices.

********All command line arguments are mandatory********

Directory - 
=========
home
	/src 			- Source code
	/test_data		- test data
		/test_cases 	- test cases 	(each file case<x>.txt contains 1 test case, see file for details, x = case Id)
		/results	- test results	(each file filename<x>_<y>.txt contains 1 result, x = test case case<x>.txt in test_cases, if y=1 : grid format and if y=2 text format  )


Test case format - 
================
gridsize:X,Y
ticks:N
alive:x1,y1;x2,y2;x3,y3;...

example test case - 

gridsize:50,50
ticks:20
alive:1,24;1,25;2,24;2,25;3,11;3,16;3,27;

