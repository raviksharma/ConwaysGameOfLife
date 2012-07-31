
#include "Grid.hpp"

namespace CGOL
{
	Grid::Grid( const size_t& a_X_max,
		  const size_t& a_Y_max,
		  const Grid::EvolutionFunction_t& a_evolution_function )
		  :
	m_data_1(a_X_max, a_Y_max),
	m_data_2(a_X_max, a_Y_max),
	m_current(&m_data_1),
	m_other(&m_data_2),
	m_evolution_function(a_evolution_function)
	{
	}

	Grid::Grid( const Grid& other)
		  :
	m_data_1(other.m_data_1),
	m_data_2(other.m_data_2),
	m_current(other.m_current==&other.m_data_1?&m_data_1:&m_data_2),
	m_other(other.m_current==&other.m_data_2?&m_data_2:&m_data_1),
	m_evolution_function(other.m_evolution_function)
	{
	}

	Grid& Grid::operator=( const Grid& other)
	{
		if(this != &other)
		{
			m_data_1 = other.m_data_1;
			m_data_2 = other.m_data_2;
			m_current = other.m_current==&other.m_data_1?&m_data_1:&m_data_2;
			m_other = other.m_current==&other.m_data_2?&m_data_2:&m_data_1;
			m_evolution_function = other.m_evolution_function;
		}
		return *this;
	}

    void Grid::set( const size_t& a_x, const size_t& a_y, const bool& a_val )
    {
      m_current->set(a_x, a_y, a_val);
    }

    const Grid::BitSet2D_t& Grid::current() const { return *m_current; }

    void Grid::evolve()
    {
      for( size_t y=0; y < m_current->y_size(); ++y )
      {
        for( size_t x=0; x < m_current->x_size(); ++x )
        {
          m_other->set( x, y, m_evolution_function( *m_current, x, y ));
        }
      }
      switch_current(); /* switch current grid with other */
    }


    void Grid::switch_current()
    {
      if( m_current != &m_data_1 )
      {
        m_current = &m_data_1;
        m_other = &m_data_2;
      }
      else
      {
        m_current = &m_data_2;
        m_other = &m_data_1;
      }
    }

}
