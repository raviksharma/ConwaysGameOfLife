#ifndef __GridPrinter_hpp
#define __GridPrinter_hpp

#include "Program_Options.hpp"
#include "NoAssignmentOperator.hpp"
#include <ostream>

namespace CGOL
{
 struct Grid;
 /* Grid Printer - writes a Grid out as grid|text to output stream */
 class GridPrinter
	{
	public:
		GridPrinter( const Grid&, const utility::Program_Options::EFormat& );

	private:
		const Grid&  m_grid;
		utility::Program_Options::EFormat m_format;
		
		friend std::ostream& operator<<( std::ostream& , const GridPrinter& );

		NO_ASSIGNMENT_OPERATOR(GridPrinter);
	};

	std::ostream& operator<<( std::ostream& , const GridPrinter&  );

}

#endif // !__GridPrinter_hpp
