#include "RunSimulation.hpp"
#include "FileSpec.hpp"
#include "Program_Options.hpp"
#include "Grid.hpp"
#include "Evolution.hpp"
#include "GridPrinter.hpp"

#include <fstream>

namespace CGOL
{
	void run_simulation( const CGOL::utility::Program_Options& a_program_options )
	{
		const utility::FileSpec fileSpecification(a_program_options.get_run_info());

		Grid grid(fileSpecification.grid_size().first,fileSpecification.grid_size().second,&(CGOL::evolution_function));

		const GridPrinter gridPrinter(grid, a_program_options.get_format_type());

		std::ofstream file(a_program_options.get_output_info());

		for(size_t i=0; i<fileSpecification.alive_cells().size(); ++i)
		{
			if(fileSpecification.alive_cells()[i].first>=grid.current().x_size()  ||
				fileSpecification.alive_cells()[i].second>=grid.current().y_size() )
			{
				throw std::runtime_error("void run_simulation( const CGOL::utility::Program_Options& a_program_options ) : alive cell index out of bounds");
			}
			grid.set(fileSpecification.alive_cells()[i].first, fileSpecification.alive_cells()[i].second, true);
		}

		std::ostream& o(file);
		
		o << "gridsize:" << grid.current().x_size() << "," << grid.current().y_size() << std::endl;
		

		for(size_t i=0; i<fileSpecification.ticks(); ++i)
		{
			o << "ticks:" << i << std::endl;
			o << gridPrinter << std::endl;
			grid.evolve();
		}

		o << "ticks:" << fileSpecification.ticks() << std::endl;
		o << gridPrinter << std::endl;
	}
}
