#include "../headers/InteractionsTodo.h"

/**
 * @brief Construct a new Interactions Todo:: Interactions Todo object
 * 
 */
InteractionsTodo::InteractionsTodo(){
  this->interactionsTodo = new std::list<InteractionTodo>();
}

/**
 * @brief Destroy the Interactions Todo:: Interactions Todo object
 * 
 */
InteractionsTodo::~InteractionsTodo(){
  delete this->interactionsTodo;
}

/**
 * @brief 
 * 
 * @param interactionTodo 
 */
void InteractionsTodo::add(InteractionTodo interactionTodo){
  this->interactionsTodo->emplace_back(interactionTodo);
}

/**
 * @brief 
 * 
 * @return int 
 */
int InteractionsTodo::getSize(){
  return this->interactionsTodo->size();
}

/**
 * @brief 
 * 
 * @param index 
 * @return InteractionsTodo 
 */
InteractionTodo InteractionsTodo::get(int index){
  int size = this->getSize();
  if(index>size){
    throw std::invalid_argument("Error in method getLog of class InteractionsTodo :\n\narray index out of bound\n"+getDebugValues());
  }else{
    std::list<InteractionTodo>::iterator it = this->interactionsTodo->begin();
    std::advance(it,index);
    return *it;
  }
}

/**
 * @brief 
 * 
 * @param interactionTodo
 * @return InteractionsTodo 
 */

InteractionsTodo InteractionsTodo::get(InteractionTodo interactionTodo){
  InteractionsTodo foundedInteractionsTodo = InteractionsTodo();
  
  for(int x=0;x<this->getSize();x++){
    InteractionTodo currentInteractionTodo = this->get(x);
    if(currentInteractionTodo==interactionTodo){
      foundedInteractionsTodo.add(currentInteractionTodo);
    }
  }

  return foundedInteractionsTodo;
}

/**
 * @brief 
 * 
 * @return std::string 
 */
std::string InteractionsTodo::getDebugValues(){
  std::string toReturn = "InteractionsTodo{\n";
  for(int x=0;x<this->getSize();x++){
    toReturn+=+"  "+this->get(x).getDebugValues()+"\n";
  }
  toReturn+="}";
  return toReturn;
}