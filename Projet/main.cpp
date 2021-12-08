#include "mainwindow.h"

#include <QApplication>
#include "contact.h"
#include "logs.h"
#include "interactiontodos.h"
#include "sqlinterface.h"

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
 * \subsection what What can I do with this?
 *
 * Not much (yet)<br>
 * It allows the manipulation of simple objects that will later be core to the application.<br>
 *  - Creation, edition and deletion of contacts.<br>
 *  - Creation, edition and deletion of Interactions.<br>
 *  - Extracting Todos from Interactions.<br>
 *  - Maintaining a conceptually correct link between Todos and Interactions.<br>
 *  - Getting a complete log history of all the actions performed. <br><br>
 * Although it is not implemented yet, it has been developped according to the principles of relational databases (here SQLite) :<br>
 * Therefore the <b>ACID</b> database properties are here ascertained (the most important one being atomicity)
 *
 *
 *
 * \subsection runStep Running the app
 *
 * For now, the app works only in console. The object files are in the build repertory. Run them using the ./ command
 * The main will test basic functions : Creating two contacts, changing their logs, adding their todos, printing debug values, deleting everything and closing.
 *
 *
 *
 */

int main(int argc, char *argv[]){

    bool withUI = true;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*
    Logs* logs = new Logs();
    InteractionTodos* itList = new InteractionTodos();

    Contact* client0 = new Contact("Valentin","Verstracte","vvdev","valentinverst.developer@gmail.com","0102030405", Photo("oui"),logs);
    Contact* client1 = new Contact("Evan","Petit","EvanIndustry","evan.petit@ouawe.com","0689130218", Photo("oui"),logs);

    client0->setEnterprise("ValentinIndustry",logs);
    client0->setMail("valentin.verstracte@ValentinIndustry",logs);
    client0->setPhone("5414315341",logs);

    Interaction* interaction1 = new Interaction(Date(),std::string("Groceries @TODO @DATE 30/08/2022 buy cheese"));
    Interaction* interaction2 = new Interaction(Date(),std::string("Todoless interaction"));
    Interaction* interaction3 = new Interaction(Date(),std::string("Important project to get done with @TODO brew some coffee @TODO play video games @TODO rush it last minute tomorrow (@DATE 27/10/2021)"));


    client0->addInteraction(interaction1,logs);
    client0->addInteraction(interaction2,logs);
    client1->addInteraction(interaction3,logs);
    client1->addInteraction(interaction2,logs);

    client1->removeInteraction(2);

    itList->addInteraction(interaction1);
    itList->addInteraction(interaction2);
    itList->addInteraction(interaction3);

    std::cout << *logs << std::endl;
    std::cout << "ok" << std::endl;


    delete logs;
    delete client0;
    delete client1;
    delete itList;
    delete interaction1;
    delete interaction2;
    delete interaction3;
    */

    std::list<ContactID> lst;
    SQLInterface db;
    db.getAllContacts(lst);

    // std::cout << lst.front().contact->getDebugValues(0);
    std::list<ContactID>::iterator it;
    for (it = lst.begin(); it != lst.end(); ++it){
        std::cout << it->contact->getFirstName() << std::endl;
    }

    if(withUI){
        return a.exec();
    }else{
        return 1;
    }
}
