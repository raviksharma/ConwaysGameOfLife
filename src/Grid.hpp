#ifndef __Grid_hpp
#define __Grid_hpp

#include "BitSet2D.hpp"
//#include "NoCopyConstructor.hpp"
//#include "NoAssignmentOperator.hpp"

namespace CGOL
{
	/* Game of life grid(X_MAX,Y_MAX) */
  struct Grid
  {
    typedef BitSet2D BitSet2D_t;
    typedef bool (*EvolutionFunction_t)(const BitSet2D_t&, const size_t& /*x*/, const size_t& /*y*/);

	Grid( const size_t& /*X_max*/,
		  const size_t& /*Y_max*/,
		  const EvolutionFunction_t&);

	Grid( const Grid& other);
	Grid& operator=( const Grid& other);

    void set( const size_t& /*x*/, const size_t& /*y*/, const bool&);

    const BitSet2D_t& current() const;

    void evolve();

  private:

    void switch_current();

    BitSet2D_t m_data_1;
    BitSet2D_t m_data_2;

    BitSet2D_t* m_current;
    BitSet2D_t* m_other;

    EvolutionFunction_t m_evolution_function;

    //NO_ASSIGNMENT_OPERATOR(Grid);
    //NO_COPY_CONSTRUCTOR(Grid);
  };

}

#endif // !__Grid_hpp
