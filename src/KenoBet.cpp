#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <utility> 
#include "../include/KenoBet.hpp"

bool KenoBet::not_in(set_of_numbers_type v, number_type n) const {

    for(int i=0; i < v.size(); ++i){
        if(n == v[i])
            return false;
    }
    return true;
}


void KenoBet::sorting( void ){
    for(int i=0; i < m_spots.size(); ++i){
        for(int j=0; j < m_spots.size(); ++j){
            if(m_spots[j] > m_spots[i]){
                std::swap(m_spots[j], m_spots[i]);
            }
        }
    }
}


bool KenoBet::add_number( number_type spot_ ){

    if(spot_ < 0)
        return false;
    else if(spot_ > 80)
        return false;

    for(int i=0; i < m_spots.size(); ++i){
        if(spot_ == m_spots[i])
            return false;
    }
    m_spots.push_back(spot_);
    return true;
}


bool KenoBet::set_wage( cash_type wage_ ){
    m_wage = wage_;
    
    if(wage_ > 0)        
        return true;

    return false;
}


bool KenoBet::set_nr(number_type nr_){
    if(nr_ > 0){
        m_nr = nr_;
        return true;
    }
    return false;
}


number_type KenoBet::get_nr( void ) const{
    return m_nr;
}


void KenoBet::reset( void ){
    m_wage = 0;
    m_nr = 0;
    m_spots.clear();
    m_hits.clear();
}
        

cash_type KenoBet::get_wage( void ) const{
    return m_wage;
}


size_t KenoBet::size( void ) const{
    return m_spots.size(); 
}


set_of_numbers_type KenoBet::get_spots( void ) const{
    return m_spots;
}


set_of_numbers_type KenoBet::get_hits( const set_of_numbers_type & hits_ ) const{

        set_of_numbers_type return_vector;

        for(int j=0; j < m_spots.size(); ++j){//verificando a quantidade de hits na rodada específica.
            if(not_in(hits_, m_spots[j]) == false){
                return_vector.push_back(m_spots[j]);
            }
        }
        return return_vector;
}