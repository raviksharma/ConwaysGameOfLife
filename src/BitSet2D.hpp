#ifndef __BitSet2D_hpp
#define __BitSet2D_hpp

//#include "NoAssignmentOperator.hpp"

#include <ostream>
#include <vector>

namespace CGOL
{
	/* Dimensions */
	///
	/// (x,y) x -------->
	///   y
	///   |
	///   |
	///   |
	///   V


	/* 2D Boolean Grid */
	class BitSet2D 
	{
	public:
		BitSet2D( const size_t& /*X_max*/, const size_t& /*Y_max*/ );

		bool operator()( const size_t& /*x*/, const size_t& /*y*/ ) const;

		void set( const size_t& /*x*/, const size_t& /*y*/, const bool& );

		const size_t& x_size() const;
		const size_t& y_size() const;

	private:
		/* 2D wrapper for a linear array */
		size_t index(const size_t& /*x*/, const size_t& /*y*/) const;

		std::vector<bool> m_data;
		//const size_t m_X_max, m_Y_max;
		size_t m_X_max, m_Y_max;

		//NO_ASSIGNMENT_OPERATOR(BitSet2D);
	};

	std::ostream& operator << ( std::ostream&, const BitSet2D&);

}

#endif // !__BitSet2D_hpp
