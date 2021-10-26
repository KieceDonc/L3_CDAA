#include "../headers/Contact.h"
#include "../headers/InteractionTodos.h"

#include <stdexcept>
#include <iostream>
#include <list>
#include <regex>

/**
 * @brief testing if adding Log class to Logs class work ( Logs contain a list of Log )
 * 
 * @return int 0 = test passed
 */
bool testingInteraction(){
  Interaction * i = new Interaction(Date(),"Yo wtf man @TODO the quick brown fox born in @DATE 25/05/2031 @TODO jumps over @TODO the lazy dog born in @DATE 22/05/1980");
  InteractionTodos * itL = new InteractionTodos();
  itL->addInteraction(i);
  std::cout << *itL << std::endl;
  return 0;
}

bool testRegex(){
  std::string s = "The quick brown fox born in @DATE 25/05/2022 jumps over the lazy dog";
  std::string dateStr;
  Date date;
  std::cout << "Todo :\n\t" << s << "\n\n" ;
  int match = s.find("@DATE");
  if(match != std::string::npos){
    std::cout << "Date tag found at position " << match << std::endl << std::endl;
    s.erase(match,6);
    dateStr = s.substr(match,10);
    std::cout << "Date supposée :\n\t" << dateStr << "\n\n" << "Todo sans tag : \n\t" << s << std::endl;
    std::regex pattern("^([0][1-9]|[1|2][0-9]|[3][0|1])[/]([0][1-9]|[1][0-2])[/]([1][9][7-9][0-9]|[2][0-2][0-9][0-9])$");
    if(std::regex_match(dateStr,pattern)){
      date = Date(std::stoi(dateStr.substr(0,2)),std::stoi(dateStr.substr(3,2)),std::stoi(dateStr.substr(6,4)));
      std::cout << "\n\t" <<date << "\n";
    }

    return 0;
  }
  else 
    std::cout << "Date tag not found" << std::endl;
    return 1;
}

bool testRegexInteraction(){
  std::string s = "The quick brown fox born in @DATE asd5/05/2020 jumps over the lazy dog";
  Todo * t = new Todo(s);
  std::cout << "Todo :\n\t" << s << "\n\nMatching Todo :\n\t" << *t << std::endl;
  return 0;
}

void testDelete(){
  
}

int main(){
  return testingInteraction() && testRegex() && testRegexInteraction();
}