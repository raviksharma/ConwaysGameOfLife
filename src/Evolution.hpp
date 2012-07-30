#ifndef __Evolution_hpp
#define __Evolution_hpp

namespace CGOL
{
	class BitSet2D;
	/* 
	* Game of Life evolution function
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

	bool evolution_function( const BitSet2D& , const size_t& /*x*/, const size_t& /*y*/ );
}

#endif // !__Evolution_hpp
