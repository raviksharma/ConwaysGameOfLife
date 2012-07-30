#ifndef __Appender_hpp
#define __Appender_hpp

#include "NoAssignmentOperator.hpp"

#include <string>
#include <vector>

namespace CGOL
{
	namespace utility
	{
		class Appender
		{
		public:
			Appender( std::vector<std::string>& a_data ):
			  m_data(a_data){}

			void operator() (const char* s, unsigned length) 
			{
				m_data.push_back(std::string(s,length));
			}

		private:
			std::vector<std::string>& m_data;
			NO_ASSIGNMENT_OPERATOR(Appender);
		};
	}
}

#endif // !__Appender_hpp
