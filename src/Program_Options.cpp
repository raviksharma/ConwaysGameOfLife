#include "Program_Options.hpp"
#include "Tokenizer.hpp"
#include "Appender.hpp"

#include <exception>
#include <vector>
#include <string>
#include <sstream>

namespace
{
	const std::string valid_tags[]  = {"-run", "-format", "-output"};
	const std::string format_tags[]  = {"grid", "text"};
	namespace TagTypes
	{
		enum ETag
		{
			RUN=0,
			FORMAT,
			OUTPUT,
			END
		};
	}

	TagTypes::ETag get_tag( const std::string& a_str )
	{
		for(size_t tag = static_cast<size_t>(TagTypes::RUN); tag < static_cast<size_t>(TagTypes::END); ++tag)
		{
			if( valid_tags[tag] == a_str )
			{
				return static_cast<TagTypes::ETag>(tag);
			}
		}

		throw std::runtime_error( std::string("TagTypes::ETag get_tag( const std::string& a_str ) : ") + a_str + std::string(" tag not recognised") );
	}

	CGOL::utility::Program_Options::EFormat get_format_tag( const std::string& a_str )
	{
		for(size_t tag = static_cast<size_t>(CGOL::utility::Program_Options::GRID); 
			tag < static_cast<size_t>(CGOL::utility::Program_Options::END); 
			++tag)
		{
			if( format_tags[tag] == a_str )
			{
				return static_cast<CGOL::utility::Program_Options::EFormat>(tag);
			}
		}

		throw std::runtime_error("CGOL::utility::Program_Options::EFormat get_format_tag( const std::string& a_str ) : Invalid Format");
	}


}

namespace CGOL
{
	namespace utility
	{
		Program_Options::Program_Options(int argc, char* argv[])
		{
			if(argc < 3)
			{
				throw std::runtime_error("Program_Options::Program_Options(int argc, char* argv[]) : Too few arguments");
			}
			if( argc % 2 != 1 )
			{
				throw std::runtime_error("Program_Options::Program_Options(int argc, char* argv[]) : Arguments mismatch");
			}

			std::vector<std::string> strings;

			for(size_t i=1; i<static_cast<size_t>(argc); ++i)
			{
				strings.push_back(std::string(argv[i]));
			}


			for(size_t i=0; i<strings.size(); i+=2)
			{
				switch( get_tag(strings[i]))
				{
				case TagTypes::RUN:
					run_info.first = true;
					run_info.second = strings[i+1];
					break;
				case TagTypes::FORMAT:
					format_type.first = true;
					format_type.second = get_format_tag(strings[i+1]);
					break;
				case TagTypes::OUTPUT:
					output_info.first = true;
					output_info.second = strings[i+1];
					break;
				default:
					throw std::runtime_error("Program_Options::Program_Options(int argc, char* argv[]) : Invalid option");
				};
			}

			if(!run_info.first)
				throw std::runtime_error("Program_Options::Program_Options(int argc, char* argv[]) : -run is compulsory");

			if(!format_type.first)
				throw std::runtime_error("Program_Options::Program_Options(int argc, char* argv[]) : -format is compulsory");

			if(!output_info.first)
				throw std::runtime_error("Program_Options::Program_Options(int argc, char* argv[]) : -output is compulsory");
		}

		const std::string& Program_Options::get_run_info() const { return run_info.second; }
		const std::string& Program_Options::get_output_info() const { return output_info.second; }
		const Program_Options::EFormat& Program_Options::get_format_type() const { return format_type.second; }


		std::string Program_Options::help_text()
		{
			std::stringstream ss;
			ss << "Conway's Game of Life" << std::endl << std::endl;
			ss << "Usage: ConwaysGameOfLife.exe [<option> <value>]" << std::endl << std::endl;
			ss << "options\t:" << std::endl;
			ss << "-run\t: <test case file>" << std::endl;
			ss << "-output\t: <test case result file>" << std::endl;
			ss << "-format\t: grid|text" << std::endl;

			return ss.str();
		}
	}
}

