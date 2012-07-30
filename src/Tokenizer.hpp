#ifndef __Tokenizer_hpp
#define __Tokenizer_hpp

#include <cstring>

namespace CGOL
{
	namespace utility
	{
		/* tokenizes string by given delimiters */
		template<typename Operator>
		void tokenize(Operator& op, const char* input, const char* delimiters) 
		{
			const char* s = input;
			const char* e = s;
			while (*e != 0) 
			{
				e = s;
				while (*e != 0 && strchr(delimiters, *e) == 0) ++e;
				if (e - s > 0) 
				{
					op(s, (unsigned)(e - s));
				}
				s = e + 1;
			}
		}
	}
}

#endif // !__Tokenizer_hpp
