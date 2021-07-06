#ifndef GameProcessing_h
#define GameProcessing_h
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
/*! checks if a specific element n is not in a vector v.
    @return True if that element is not in; False otherwise.
*/
bool not_in(std::vector<int> v, int n);


/*! checks if there are some different character other than expected.
    @param str string in the file that will be checked.
    @param type type of data. 0 for double, 1 for int.
    @return True if there are any invalid character; False otherwise. */
bool invalid_characters(string str, int type);


/*! Processes the summary after the end of the rounds.
    @param p KenoBet object.
    @param wage_p_round wage spent on each round. */
void process_summary(KenoBet p, double wage_p_round);


/*! Processes each round.
    @param p KenoBet object.
    @param wage_p_round wage spent on each round. 
    @param p_spots player spots
    @param return_table return table with each specific return value*/
void process_rounds(KenoBet p, double wage_p_round, set_of_numbers_type p_spots, double return_table[16][16]);


/*! Show the initial interface when game starts
    @param p KenoBet object
    */
void home_interface(KenoBet p);


#endif // GameProcessing_h