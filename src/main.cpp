#include "Grid.hpp"
#include "Evolution.hpp"
#include "Program_Options.hpp"
#include "RunSimulation.hpp"


#include <iostream>


int main(int argc, char*argv[])
{
	try
	{
		CGOL::utility::Program_Options po(argc, argv);
		CGOL::run_simulation( po );
	}
	catch( std::exception& e )
	{
		std::cout << "*** ERROR ENCOUNTERED *** " << std::endl  << std::endl;
		std::cout << e.what() << std::endl  << std::endl;
		std::cout << "************************* " << std::endl  << std::endl;
		std::cout << CGOL::utility::Program_Options::help_text() << std::endl;
		return 1;
	}

	return 0;
}