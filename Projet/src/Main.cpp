#include "../headers/Contact.h"
#include "../headers/Logs.h"

#include <iostream>

int main(){
  Logs* logs = new Logs();
  Contact* client0 = new Contact(logs,"Valentin","Verstracte","vvdev","valentinverst.developer@gmail.com","0102030405", Photo("oui"));
  Contact* client1 = new Contact(logs,"Evan","Petit","EvanIndustry","evan.petit@ouawe.com","0689130218", Photo("oui"));

  client0->setEnterprise("ValentinIndustry");
  client0->setMail("valentin.verstracte@ValentinIndustry");
  client0->setPhone("5414315341");

  std::cout << logs->getDebugValues(0);

  delete logs;
  delete client0;
  delete client1;
  return 1;
} 