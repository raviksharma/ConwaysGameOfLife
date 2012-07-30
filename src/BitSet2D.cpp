#include "BitSet2D.hpp"

namespace CGOL
{
	BitSet2D::BitSet2D( const size_t& a_X_max, const size_t& a_Y_max )
		: m_X_max(a_X_max) ,m_Y_max(a_Y_max)
	{
		m_data.resize( m_X_max*m_Y_max, false );
	}

	bool BitSet2D::operator()( const size_t& a_x, const size_t& a_y ) const
	{
		return m_data[ index(a_x, a_y) ];
	}
	 
	void BitSet2D::set( const size_t& a_x, const size_t& a_y, const bool& a_val )
	{
		m_data[index(a_x, a_y)] = a_val;
	}

	const size_t& BitSet2D::x_size() const { return m_X_max; }
	const size_t& BitSet2D::y_size() const { return m_Y_max; }

	size_t BitSet2D::index(const size_t& a_x, const size_t& a_y) const
	{
		return (a_x*m_Y_max) + a_y;
	}

	/* X - alive cell, . - dead cell */ 
	std::ostream& operator << ( std::ostream& o, const BitSet2D& a_bitset2D )
	{
		for( size_t y=0; y < a_bitset2D.y_size(); ++y )
		{
			for( size_t x=0; x < a_bitset2D.x_size(); ++x )
			{
				o << ( a_bitset2D(x,y) ? "X" : "." );
			}
			o << "\n";
		}
		return o;
	};


}