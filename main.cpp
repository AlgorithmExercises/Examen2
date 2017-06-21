#include "Test.h"
#include <iostream>
#include<string>
#include<map>
#include <sstream>
using namespace std;
void greedy(vector<int> sorted_coins, int amount, vector<int> *answer){
  if(amount <=0
    || sorted_coins.size() == 0)
    return;

    vector<int> copy = sorted_coins;
    int resta = 0;
    if(copy[copy.size()-1] <= amount){
      answer->push_back(copy[copy.size()-1]);
      resta = copy[copy.size()-1];
    }else
      copy.pop_back();
    greedy(copy, amount - resta, answer);
}

void printVector(vector<int>* printable){
  for(int i =0; i< printable->size(); i++){
    cout<<(*printable)[i]<<endl;
  }
}
#include <limits>
#define INT_MAX std::numeric_limits<int>::max()
void printVectorInLine(std::vector<int>* v){
  for(int i =0; i < v->size(); i++){
    cout<<(*v)[i]<<",";
  }
  cout<<endl;
}

vector<int>* makeVector(int n, vector<int>* last){
  vector<int> * nuevo = new vector<int>();
  nuevo->push_back(n);
  for(int i =0; i< last->size(); i++)
    nuevo->push_back((*last)[i]);
  return nuevo;
}

vector<int> dynamicPrograming(vector<int> coins, int amount)
{
    int table[amount+1];
    vector<vector<int>* > tableCoins;
    table[0] = 0;
    tableCoins.push_back(new std::vector<int>());
    for (int i=1; i<=amount; i++){
        table[i] = INT_MAX;
        tableCoins.push_back(new std::vector<int>());
      }
    for (int i=1; i<=amount; i++)
    {
        for (int j=0; j<coins.size(); j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i]){
                  table[i] = sub_res + 1;
                  tableCoins[i] =makeVector(coins[j], tableCoins[i-coins[j]]);
              }
          }
    }
    return *(tableCoins[amount]);
}

vector<int> makeChange(vector<int> sorted_coins, int amount)
{
    vector<int>answer;
    cout<<"amount "<<amount<<endl;
    cout<<"coins "<<endl;
    for(int i = 0; i < sorted_coins.size(); i++)
      cout<<sorted_coins[i]<<endl;
    //GREEDY
    //greedy(sorted_coins, amount, &answer);

    //DYNAMICPROGRAMMING
    answer = dynamicPrograming(sorted_coins,amount);
    printVectorInLine(&answer);
    return answer;
}

int main ()
{
    test();
    return 0;
}
