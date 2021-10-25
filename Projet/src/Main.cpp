#include "../headers/Contact.h"
#include "../headers/Logs.h"

#include <iostream>

/*! \mainpage Contact Management App with QT and SQLite! (Including : Neither QT (yet) nor SQLite (sorry) )
 *
 * \section intro_sec Introduction
 *
 * Documentation made by Valentin Verstracte and Evan Petit for an app development university project.
 * The entirety of our work can be found on a public github repository :<br>
 * <a href="https://github.com/KieceDonc/L3_CDAA/tree/prod/Projet">GitHub - L3_CDAA / Projet</a><br><br>
 * 
 * Valentin Verstracte : <a href="https://github.com/KieceDonc/">GitHub - KieceDonc</a><br>
 * Evan Petit : <a href="https://github.com/RenardBOT/">GitHub - RenardBOT</a>
 *
 * 
 * \subsection runStep Running the app 
 * 
 * For now, the app works only in console. Please use<br>
 * make build <br>
 * In the build repertory.
 *
 */

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