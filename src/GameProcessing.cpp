#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include "../include/KenoBet.hpp"
#include "../include/GameProcessing.hpp"

using namespace std;


bool invalid_characters(string str, int type){

    string valid_numbers = "0123456789\n";
    int c=0; int ok=0;
    string outp{};
    for(int i=0; i < str.size(); ++i){
        for(int j=0; j < valid_numbers.size(); ++j){
            if(str[i] == valid_numbers[j]){
                ++c;
                outp.push_back(str[i]);
            }
            else{
                if(((type == 1) && (str[i] == '.')) && ok == 0){
                    ++c;
                    ++ok;
                    continue;
                }
                else if(((type == 0) && (str[i] == ' ')) && ok == 0){
                    ++c;
                    ++ok;
                    continue;
                }
            }
        }
        if(type == 0){
            ok=0;
        }
    }

    if(c == str.size())
        return false;
    return true;
}


void process_sumary(KenoBet p, double wage_p_round){

    cout << "======= Sumário =======" << endl;

    cout << ">>> Você gastou um total de $" << wage_p_round*p.get_nr() << " créditos" << endl;

    if( p.get_wage() - (wage_p_round*p.get_nr()) > 0)
        cout << ">>> Você ganhou $" <<  p.get_wage() - (wage_p_round*p.get_nr()) << " créditos." << endl;
    else if(p.get_wage() - (wage_p_round*p.get_nr()) == 0)
        cout << "Você não perdeu e nem ganhou nada." << endl;
    else{
        cout << ">>> Você perdeu $" <<  (p.get_wage() - (wage_p_round*p.get_nr()))*(-1) << " créditos." << endl;
    }

    cout << ">>> Você está saindo do jogo com um total de $" << p.get_wage() << endl;
    p.reset();
}


void process_rounds(KenoBet p, double wage_p_round, set_of_numbers_type p_spots, double return_table[16][16]){

    srand(time(nullptr));
    for(int i=1; i <= p.get_nr(); ++i){

        set_of_numbers_type random_numbers;
        cout << "Esta é a rodada #" << i << ", sua aposta é $" << wage_p_round << ". Boa sorte!" << endl;
        p.set_wage(p.get_wage()-(wage_p_round)); // update player wage
        cout << "Os números sorteados são: [ ";

        for(int j=0; j < 20; ++j){
            int r=rand()%81;
            if(p.not_in(random_numbers, r) == true){
                random_numbers.push_back(r);
                cout << random_numbers[j] << ' ';
            }
            else{
                --j;
            }
        }

        cout << "]\n" << endl;
        
        cout << "Você acertou os números [ ";

        set_of_numbers_type hits = p.get_hits(random_numbers);
        for(int i=0; i < hits.size(); ++i){
            cout << hits[i] << ' ';
        }
        cout << "], um total de " << hits.size() << " hits de " << p.size() << endl;
        cout << "Sua taxa de retorno é " << return_table[p.size()-1][hits.size()] << ". Assim, você sai com $" << (wage_p_round)*return_table[p.size()-1][hits.size()] << endl;
        p.set_wage(p.get_wage()+(wage_p_round*return_table[p.size()-1][hits.size()])); // update player wage
        cout << "Você possui um total de: $" << p.get_wage() << endl;
        cout << "-------------------------------------------" << endl;
         
    }
    cout << ">>> Fim das rodadas!" << endl;
    cout << "-------------------------------------------\n" << endl;
    process_sumary(p, wage_p_round);
}


void home_interface(KenoBet p){
    set_of_numbers_type p_spots = p.get_spots();
    double wage_p_round = p.get_wage()/p.get_nr();
    double return_table[16][16] = {{0, 3}, 
                                   {0, 1, 9}, 
                                   {0, 1, 2, 16},
                                   {0, 0.5, 2, 6, 12}, 
                                   {0, 0.5, 1, 3, 15, 50},
                                   {0, 0.5, 1, 2, 3, 30, 75}, 
                                   {0, 0.5, 0.5, 1, 6, 12, 36, 100}, 
                                   {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720}, 
                                   {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200},
                                   {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},
                                   {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},
                                   {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000},
                                   {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000},
                                   {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500},
                                   {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}};


    cout << ">>> Aposta lida com sucesso!" << endl;

    cout << "Você apostará um total de $" << p.get_wage() << " créditos." << endl;

    cout << "Jogará um total de " << p.get_nr() << " rodadas, apostando $" <<  wage_p_round << " por rodada.\n" << endl;

    cout << "Sua aposta tem " << p.size() << " números, eles são: [ ";
    for(int i=0; i < p.size(); ++i){
       cout << p_spots[i] << ' '; 
    }
    cout << "]" << endl;
    //maybe in other func.
    cout << "----------+-----------" << endl;
    cout << "Hits      | Retorno" << endl;
    cout << "0         | 0" << endl;
    for(int i=1; i <= p.size(); ++i){
    cout << i << "         | " << return_table[p.size()-1][i] << endl;
    }
    cout << "----------------------" << endl;

    process_rounds(p, wage_p_round, p_spots, return_table);
}
