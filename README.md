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

###Usage###
executable [&lt;option> &lt;value>]

options	:<br/>
-run		: <test case file>		//contains test case<br/>
-output	: <test case result file>	//contains result of the test case<br/>
-format	: grid|text			//grid - 2D view of the Grid (X - alive cell, . - dead cell), text - test case compliant view, contains alive cell indices.

********All command line arguments are mandatory********

###Directory###
/home<br/>
&nbsp;&nbsp;&nbsp;&nbsp;/src 			- Source code<br/>
&nbsp;&nbsp;&nbsp;&nbsp;/test\_data		- test\_data<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/test\_cases 	- test cases 	(each file case<x>.txt contains 1 test case, see file for details, x = case Id)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/results	- test results	(each file <br/>filename<x>\_<y>.txt contains 1 result, x = test case case<x>.txt in test_cases, if y=1 : grid format and if y=2 text format)<br/>


###Test case format###

gridsize:X,Y<br/>
ticks:N<br/>
alive:x1,y1;x2,y2;x3,y3;...<br/>

example test case - <br/>

gridsize:50,50<br/>
ticks:20<br/>
alive:1,24;1,25;2,24;2,25;3,11;3,16;3,27;<br/>

