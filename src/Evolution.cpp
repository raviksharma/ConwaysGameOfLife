
#include "Evolution.hpp"
#include "BitSet2D.hpp"

namespace
{
	unsigned int get_value(const CGOL::BitSet2D& a_bitset2D, const size_t& a_x, const size_t& a_y)
	{
		if((a_x<0)||(a_y<0)||(a_x>=a_bitset2D.x_size())||(a_y>=a_bitset2D.y_size()))
			return 0;
		else
			return static_cast<unsigned int>(a_bitset2D(a_x,a_y));
	}

	unsigned int get_alive_neighbour_count(const CGOL::BitSet2D& a_bitset2D, const size_t& a_x, const size_t& a_y)
	{
		return   get_value(a_bitset2D, a_x-1, a_y-1)
				+get_value(a_bitset2D,   a_x, a_y-1)
				+get_value(a_bitset2D, a_x+1, a_y-1)
				+get_value(a_bitset2D, a_x-1,   a_y)
				+get_value(a_bitset2D, a_x+1,   a_y)
				+get_value(a_bitset2D, a_x-1, a_y+1)
				+get_value(a_bitset2D,   a_x, a_y+1)
				+get_value(a_bitset2D, a_x+1, a_y+1);
	}
}

namespace CGOL
{
	bool evolution_function( const BitSet2D& a_bitset2D, const size_t& a_x, const size_t& a_y ) 
    {
      const unsigned int count = get_alive_neighbour_count(a_bitset2D,a_x,a_y);
	  return a_bitset2D(a_x,a_y) ? (2==count || count ==3) : (count == 3);
    }
}
