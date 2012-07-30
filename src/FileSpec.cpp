#include "FileSpec.hpp"
#include "Tokenizer.hpp"
#include "Appender.hpp"
#include "NoAssignmentOperator.hpp"

#include <fstream>
#include <iostream>
#include <algorithm>

namespace
{
	const std::string valid_tags[]  = {"gridsize", "ticks", "alive"};
	namespace TagTypes
	{
		enum ETag
		{
			GRIDSIZE=0,
			TICKS,
			ALIVE,
			END
		};
	}

	TagTypes::ETag get_tag( const std::string& a_str )
	{
		if( a_str.empty() )
		{
			throw std::runtime_error("TagTypes::ETag get_tag( const std::string& a_str ) : Empty tag found");
		}

		for(size_t tag = static_cast<size_t>(TagTypes::GRIDSIZE); tag < static_cast<size_t>(TagTypes::END); ++tag)
		{
			if( valid_tags[tag] == a_str )
			{
				return static_cast<TagTypes::ETag>(tag);
			}
		}

		throw std::runtime_error( std::string("TagTypes::ETag get_tag( const std::string& a_str ) : ") + a_str + std::string(" tag not recognised") );
	}

	std::pair<size_t, size_t> get_gridsize_tokens(const std::string & a_str)
	{
		std::vector<std::string> gridSizeTokens;
		CGOL::utility::Appender gridAppender(gridSizeTokens);
		CGOL::utility::tokenize(gridAppender, a_str.c_str(), ",");
		if(gridSizeTokens.size()!=2)
			throw std::runtime_error("std::pair<size_t, size_t> setGridSizeTokens(const std::string & a_str) : Invalid Grid Size Tokens");
		return (std::make_pair(atoi(gridSizeTokens[0].c_str()), atoi(gridSizeTokens[1].c_str())));
	}

	unsigned int getTickCount(const std::string & a_str)
	{
		return (atoi(a_str.c_str()));
	}

	struct ParseAndPopulate
	{
		ParseAndPopulate(std::vector<std::pair<size_t, size_t> >& a_alive_cells):m_alive_cells(a_alive_cells){}
		void operator()(const std::string& a_str)
		{
			std::vector<std::string> aliveCellIndex;
			CGOL::utility::Appender aliveCellIndexAppender(aliveCellIndex);
			CGOL::utility::tokenize(aliveCellIndexAppender, a_str.c_str(), ",");
			if(aliveCellIndex.size()!=2)
				throw std::runtime_error(" void ParseAndPopulate::operator()(const std::string& a_str) : Invalid alive cell index");
			
			m_alive_cells.push_back(std::make_pair(atoi(aliveCellIndex[0].c_str()), atoi(aliveCellIndex[1].c_str())));

		}
	private:
		std::vector<std::pair<size_t, size_t> >& m_alive_cells;
		NO_ASSIGNMENT_OPERATOR(ParseAndPopulate);
	};

	void set_alive_cells(const std::string & a_str, std::vector<std::pair<size_t, size_t> >& alive_cells)
	{
		std::vector<std::string> aliveCellTokens;
		CGOL::utility::Appender aliveCellAppender(aliveCellTokens);
		CGOL::utility::tokenize(aliveCellAppender, a_str.c_str(), ";");

		std::for_each(aliveCellTokens.begin(), aliveCellTokens.end(), ParseAndPopulate(alive_cells));
	}
}

namespace CGOL
{
	namespace utility
	{
		FileSpec::FileSpec( const std::string& a_file_name ) 
			: m_grid_size(), m_ticks(0), m_alive_cells()
		{
			std::ifstream file(a_file_name.c_str());
			if(!file)
				throw std::runtime_error(std::string("FileSpec::FileSpec( const std::string& a_file_name ) : cant open file ")+a_file_name);

			std::string line;
			std::vector<std::string> strings;
			while( std::getline(file, line) )
			{
				if(!line.empty() && line[0] != '#')
					strings.push_back(line);
			}

			for(size_t i=0; i<strings.size(); ++i)
			{
				std::vector<std::string> lineTokens;
				Appender lineAppender(lineTokens);
				tokenize(lineAppender, strings[i].c_str(), ":");
				if(lineTokens.size()!=2)
					throw std::runtime_error("FileSpec::FileSpec( const std::string& a_file_name ) : Invalid line in file");

				switch( get_tag(lineTokens[0]))
				{
				case TagTypes::GRIDSIZE:
					m_grid_size = get_gridsize_tokens(lineTokens[1]);
					break;
				case TagTypes::TICKS:
					m_ticks = getTickCount(lineTokens[1]);
					break;
				case TagTypes::ALIVE:
					set_alive_cells(lineTokens[1], m_alive_cells);
					break;
				default:
					throw std::runtime_error("FileSpec::FileSpec( const std::string& a_file_name ) : Invalid tag");
				};
			}
		}
	}
}
