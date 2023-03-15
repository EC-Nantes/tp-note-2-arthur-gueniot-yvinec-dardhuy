#include <iostream>
#include <vector>
  int main(){
    std::vector <char> test;
    test.push_back('a');
    test.push_back('b');
    test.push_back('c');
    test.push_back('d');
    test.erase(test.begin());
    for(int i=0;i<4;i++){
      std::cout<<"voici l'it : "<<i<<" voici la valeur vecteur : "<< test[i]<<std::endl;
    }
  }