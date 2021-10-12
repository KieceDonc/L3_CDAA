#include "../headers/Contact.h"
#include "../headers/Logs.h"

#include <stdexcept>
#include <iostream>

/**
 * @brief testing if adding Log class to Logs class work ( Logs contain a list of Log )
 * 
 * @return int 0 = test passed
 */
int testingAdd(){
  Logs * logs0 = new Logs();

  if(logs0->getSize()>0){
    throw "logs contain one/multiple log after initiate. Sus. Please checkout Logs testing";
  }

  Contact * c0 = new Contact(logs0,"Valentin","Verstracte","vvdev","v@gmail.com","0102030405",Photo());

  if(logs0->getSize()>0){
    throw "logs contain one/multiple log after initiate and adding them to a contact. Sus. Please checkout Logs testing";
  }

  logs0->add(Log(c0,Log::ACTION_EDIT_ENTERPRISE));
  
  if(logs0->getSize()!=1){
    throw "Invalid test. We added a log in logs but size hasn't increase. Please checkout Logs testing";
  }

  delete logs0;
  delete c0;

  return 0;
}

/**
 * @brief testing if we can get certain list of Logs sorted with some parameters
 * 
 * @return int 0 = test passed
 */
int testingGet(){
  Logs * logs0 = new Logs();

  Contact * c0 = new Contact(logs0,"Valentin","Verstracte","vvdev","v@gmail.com","0102030405",Photo());

  logs0->add(Log(c0,Log::ACTION_EDIT_ENTERPRISE));
  
  if(logs0->get(c0,-1,Date()).getSize()==1){
    throw "Invalid test. We suppose to have one log inside returned logs. Please checkout Logs testing";
  }

  delete logs0;
  delete c0;

  return 0;
}

int main(){
  return testingAdd() && testingGet();
}