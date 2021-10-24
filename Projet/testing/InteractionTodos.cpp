#include "../headers/Contact.h"
#include "../headers/InteractionTodo.h"

#include <stdexcept>
#include <iostream>
#include <list>

/**
 * @brief testing if adding Log class to Logs class work ( Logs contain a list of Log )
 * 
 * @return int 0 = test passed
 */
void testingInteraction(){
  Interaction i = Interaction(Date(),"The quick brown fox @TODO jumps over @TODO the lazy dog");
  std::list<InteractionTodo> it = std::list<InteractionTodo>();
  InteractionTodo::listAllInteractionTodos(&i , &it);
  //std::cout << i << std::endl;
  /*std::cout << "test";
  for(std::list<InteractionTodo>::iterator iter = it.begin() ; iter != it.end() ; iter++ ){
        std::cout << iter->getI() << std::endl ;
    }*/
}

int main(){
  testingInteraction();
  return 0;
}