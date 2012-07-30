#ifndef __Program_Options_hpp
#define __Program_Options_hpp

#include <utility>
#include <string>

namespace CGOL
{
	namespace utility
	{
		/* handles command line arguments */

		/*
			Conway's Game of Life
			Usage: ConwaysGameOfLife.exe [<option> <value>]
			options	:
			-run	: <test case file>
			-output	: <test case result file>
			-format	: grid|text
		*/
		class Program_Options
		{
		public:

			enum EFormat
			{
				GRID, TEXT, END
			};

			typedef std::pair< bool, std::string > run_info_t;
			typedef std::pair< bool, std::string > output_info_t;
			typedef std::pair< bool, EFormat > format_type_t;

			Program_Options(int argc, char* argv[]);

			static std::string help_text();

			const std::string& get_run_info() const;
			const std::string& get_output_info() const;
			const EFormat& get_format_type() const;

		private:
			run_info_t run_info;
			output_info_t output_info;
			format_type_t format_type;
		};
	}
}
#endif // !__Program_Options_hpp
