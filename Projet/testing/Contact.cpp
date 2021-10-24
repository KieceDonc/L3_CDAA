#include "../headers/Contact.h"
#include "../headers/Logs.h"

#include <stdexcept>

/**
 * @brief test equal operator of contact class
 * 
 * @return int 0 = test passed
 */
int testingEquals(){
  Logs * logs0 = new Logs();
  Logs * logs1 = new Logs();
  
  Contact c0 = Contact(logs0,"Valentin","Verstracte","vvdev","v@gmail.com","0102030405",Photo("tmp"));
  Contact c1 = Contact(logs0,"Valentin","Verstracte","vvdev","v@gmail.com","0102030405",Photo("tmp"));

  if(!(c0 == c1)){
    throw "Invalid test. bool Contact::operator== return false or it should return true. Please check test function";
  }

  c0.setEnterprise("oui");
  if(c0 == c1){
    throw "Invalid test. bool Contact::operator== return true or it should return false. setEnterprise not working. Please check test function";
  }

  c0.setEnterprise("vvdev");
  c0.setMail("oui@gmail.yolo.com");
  if(c0 == c1){
    throw "Invalid test. bool Contact::operator== return true or it should return false. setMail not working. Please check test function";
  }

  c0.setMail("v@gmail.com");
  c0.setPhone("0708090405");
  if(c0 == c1){
    throw "Invalid test. bool Contact::operator== return true or it should return false. setPhone not working. Please check test function";
  }

  Contact c2 = Contact(logs1,"Valentin","Verstracte","vvdev","v@gmail.com","0102030405",Photo("tmp"));

  if(c0 == c1){
    throw "Invalid test. bool Contact::operator== return false or it should return true. Please check test function";
  }

  

  delete logs0;
  delete logs1;
  return 0;
}

int main(){
  return testingEquals();
}