#include "../headers/Contact.h"
#include "../headers/InteractionTodos.h"

#include <stdexcept>
#include <iostream>
#include <list>

/**
 * @brief testing if adding Log class to Logs class work ( Logs contain a list of Log )
 * 
 * @return int 0 = test passed
 */
void testingInteraction(){
  Interaction * i = new Interaction(Date(),"Yo wtf the quick brown fox @TODO jumps over @TODO the lazy dog");
  InteractionTodos * itL = new InteractionTodos();
  itL->addInteraction(i);
  //std::cout << *itL->getItList()->front().getT() << "\n";
  //std::cout << i << std::endl;
  std::cout << "Interaction :\n\t" << *i << "\n\nMatching Todo(s) :\n\t";
  for(std::list<InteractionTodo>::iterator iter = itL->getItList()->begin() ; iter != itL->getItList()->end() ; iter++ ){
        std::cout << *iter->getT()<< "\n\t" ;
    }
}

int main(){
  testingInteraction();
  return 0;
}