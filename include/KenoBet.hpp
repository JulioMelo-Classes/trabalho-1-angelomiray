#ifndef KenoBet_hpp
#define KenoBet_hpp


using number_type = unsigned short int; //<! data type for a keno hit.
using cash_type = float; //<! Defines the wage type in this application.
using set_of_numbers_type = std::vector< number_type >; 


class KenoBet {
    public:
        //! Creates an empty Keno bet.
        KenoBet( ) : m_wage(0), m_nr(0), m_hits(0)
        { /* empty */ };


        /*! Checks if an specific element is not in an vector.
            @param v the vector that will be checked
            @param n a specific number 
            @return False if the element is not in the vector; True otherwise.*/
        bool not_in(set_of_numbers_type v, number_type n) const ;

        /*! Sort an array in ascending order.
        */
        void sorting( void );

        /*! Adds a number to the spots only if the number is not already there.
            @param spot_ The number we wish to include in the bet.
            @return T if number chosen is successfully inserted; F otherwise. */
        bool add_number( number_type spot_ );

        /*! Sets the amount of money the player is betting.
            @param wage_ The wage.
            @return True if we have a wage above zero; false otherwise. */
        bool set_wage( cash_type wage_ );

        /*! Sets the amount of rounds that will be played.
            @param nr_ The number of rounds. 
            @return True if the number of rounds is greater zero; false otherwise.*/
        bool set_nr(number_type nr_);

        /*! Returns the number of rounds.
            @return Number of rounds. */
        number_type get_nr( void ) const;


        //! Resets a bet to an empty state.
        void reset( void );

        /*! Retrieves the player's wage on this bet.
            @return The wage value. */
        cash_type get_wage( void ) const;

        /*! Returns to the current number of spots in the player's bet.
            @return Number of spots present in the bet. */
        size_t size( void ) const;

        /*! Determine how many spots match the hits passed as argument.
            @param hits_ List of hits randomly chosen by the computer.
            @return An vector with the list of hits. */
        set_of_numbers_type
        get_hits( const set_of_numbers_type & hits_ ) const;

        /*! Return a vector< spot_type > with the spots the player has picked so far.
            @return The vector< spot_type > with the player's spots picked so far. */
        set_of_numbers_type get_spots( void ) const;

    private:
        set_of_numbers_type m_spots;  //<! The player's bet.
        cash_type m_wage;             //<! The player's wage
        number_type m_nr; //<! Number of rounds
        set_of_numbers_type m_hits;
};

#endif //KenoBet_hpp