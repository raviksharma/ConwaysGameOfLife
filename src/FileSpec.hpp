#ifndef __FileSpec_hpp
#define __FileSpec_hpp

#include <utility>
#include <vector>
#include <string>


namespace CGOL
{
	namespace utility
	{
		/* test case specification input from file */
		/* test case format */
		/*
		* gridsize:X,Y
		* ticks:N
		* alive:x1,y1;x2,y2;x3,y3;...
		*
		* example test case - 
		*
		* gridsize:50,50
		* ticks:20
		* alive:1,24;1,25;2,24;2,25;3,11;3,16;3,27;
		*/

		class FileSpec
		{

		public:
			FileSpec( const std::string& /*file_name*/ );

			typedef std::pair<size_t, size_t> grid_size_t;
			typedef std::vector<std::pair<size_t, size_t> > alive_cells_t;

			const grid_size_t& grid_size() const
			{
				return m_grid_size;
			}

			const unsigned int& ticks() const
			{
				return m_ticks;
			}

			const alive_cells_t& alive_cells() const
			{
				return m_alive_cells;
			}

		private:
			grid_size_t m_grid_size;	/* Grid size */
			unsigned int m_ticks;		/* generations */
			alive_cells_t m_alive_cells;/* alive cells */

		};
	}
}

#endif // !__FileSpec_hpp
