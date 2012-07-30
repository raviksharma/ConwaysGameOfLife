

#include "GridPrinter.hpp"
#include "Grid.hpp"

namespace CGOL
{

	GridPrinter::GridPrinter( const Grid& a_grid, const utility::Program_Options::EFormat& a_format )
			:m_grid(a_grid),m_format(a_format){}

	std::ostream& operator<<( std::ostream& o, const GridPrinter& a_gridPrinter )
	{
		switch( a_gridPrinter.m_format )
		{
		case utility::Program_Options::GRID:/* 2D views of Grid */
			o << a_gridPrinter.m_grid.current();
			break;
		case utility::Program_Options::TEXT: /* text view - same format as test case input */
			o << "alive:";
			for(size_t i=0; i<a_gridPrinter.m_grid.current().x_size(); ++i)
				for(size_t j=0; j<a_gridPrinter.m_grid.current().y_size(); ++j)
					if(a_gridPrinter.m_grid.current()(i,j))
						o << i <<","<< j << ";";
			
			break;
		default:
			throw std::runtime_error("std::ostream& operator<<( std::ostream& o, const GridPrinter& a_gridPrinter ) : Invalid Format");
		};

		return o;
	}
}
