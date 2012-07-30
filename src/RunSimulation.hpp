#ifndef __RunSimulation_hpp
#define __RunSimulation_hpp

namespace CGOL
{
	namespace utility
	{
		class Program_Options;
	}
	/* runs test case - Game of life simulation for N generations over X,Y Grid */
	void run_simulation( const CGOL::utility::Program_Options& );
}

#endif // !__RunSimulation_hpp
