#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>
#include <random>
#include <cstdlib>  
#include <ctime> 
#include "../include/KenoBet.hpp"
#include "../include/GameProcessing.hpp"

using namespace std;


int main(int argc, char *argv[]){

    fstream f;
    KenoBet player;
    string values; stringstream ss;


    f.open(argv[1], ios::in); 

    cout << ">>> Lendo arquivo de apostas [" << argv[1] << "], por favor aguarde..." << endl;
    cout << "-------------------------------------------------------------------" << endl;
    
    if(f.is_open()){
        int c=0; // counter
        int error=0; // 'break'
        while(getline(f, values)){
            if(c == 0){
                if(invalid_characters(values, 1) == false){ //dont have any invalid char
                    stringstream ss0;
                    ss0 << values;
                    float wage_=0, aux=-1;
                    ss0 >> wage_;
                    ss0 >> aux;
                    if(aux == -1){
                        if(player.set_wage(wage_)){
                            //ok, wage was setted
                        }
                        else
                            cout << "Erro ao processar o saldo do jogador. Por favor, digite um saldo maior que $0." << endl; 
                    }
                    else{
                        cout << "Erro ao processar o saldo do jogador. Por favor, selecione um único saldo, mantendo a formatação desejada." << endl;
                        f.close();
                        ++error;
                        break;
                    }
                }
                else{
                    cout << "Ocorreu um erro ao processar o arquivo. Por favor, mantenha a formatação desejada." << endl;
                    f.close();
                    ++error;
                    break;                    
                }
            }
            else if(c == 1){
                if(invalid_characters(values, 0) == false){
                    stringstream ss1;
                    ss1 << values;
                    int nr=0, aux2=-1;
                    ss1 >> nr;
                    ss1 >> aux2;
                    if(aux2 == -1){
                        if(nr > 0)
                            player.set_nr(nr);
                        else{
                            cout << "Ocorreu um erro ao processar o arquivo. Por favor, digite um número de rodadas superior à zero." << endl;                        
                            f.close();
                            ++error;
                            break;
                        }
                    }
                    else{
                        cout << "Ocorreu um erro ao processar o número de rounds. Por favor, mantenha a formatação do arquivo desejada." << endl;
                        f.close();
                        ++error;
                        break;
                    }
                }
                else{
                     cout << "Ocorreu um erro ao processar o arquivo. Por favor, digite apenas números." << endl;
                     f.close();
                     ++error;
                     break;
                }
            }//nr
            else if(c == 2){
                if(invalid_characters(values, 0) == false){              
                    stringstream ss2;
                    ss2 << values;
                    int n1=0; int number_counter=0;
                    while(ss2 >> n1){
                        ++number_counter;
                        if(number_counter > 15){
                            cout << "Não foi possível processar o número " << n1 << ". Por favor, selecione até 15 números." << endl;
                            f.close();
                            ++error;
                            break;
                        }
                        else if(player.add_number(n1)){
                            //ok
                        }
                        else{
                            cout << "Número inválido: "<< n1 <<". Por favor, digite números únicos e que sejam maiores ou iguais à 0 e menores ou iguais à 80." << endl;
                            f.close();
                            ++error;
                            break;                       
                        }
                    }                    
                }
                else{
                    cout << "Ocorreu um erro ao processar o arquivo. Por favor, digite apenas números." << endl;     
                    f.close();
                    ++error;
                    break;
                }
            }//spots
            else{
                cout << "Erro ao processar o arquivo. Formatação diferente da esperada." << endl;
                f.close();
                ++error;
                break;
            }
            if(error > 0)
                break;
            ++c;

        }
        if(error > 0){
            cout << "Encerrando o jogo... Tente novamente." << endl;
        }
        else{
            player.sorting();
            home_interface(player);
        }
    }
    else{
        cout << "Não foi possível abrir o arquivo." << endl;
    }

    return 0;
}