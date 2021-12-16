    #include "./View/mainwindow.h"

#include <QApplication>
#include "./Model/contact.h"
#include "./Others/sqlinterface.h"
#include "./View/findcontact.h"



#include <iostream>

/*! \mainpage Contact Management
 *
 * \section intro_sec Introduction
 *
 * Documentation made by Valentin Verstracte and Evan Petit for an app development university project.
 * The entirety of our work can be found on a public github repository :<br>
 * <a href="https://github.com/KieceDonc/L3_CDAA/tree/prod/Projet">GitHub - L3_CDAA / Projet</a><br><br>
 *
 * <img src="../assets/Welcome.png">
 *
 * \subsection what What can I do with this?
 *
 * Tons of things! <br>
 * In general : Allows to manage a list of custom contacts.<br>
 *  - Creation, edition and deletion of contacts and their informations (name, company, profile picture, phone number, mail...)<br>
 *  - Creation, edition and deletion of interaction. An interaction is a block of text, a <i>note</i> related to a specific contact at a specific date.
 *  It can contain @TODO tags.<br>
 *  - Extracting the Todos from those interactions, also at a specific date. They can contain @DATE tags followed by dates in "dd-MM-yyyy" or "dd/MM/yyyy" format.<br>
 *  - Displaying those contacts, interactions and todos, allowing the user to sort and search through them according to different criterias. <br>
 *  - Extracting interactions and todos between two dates <br>
 *  - Exporting a JSON file containing a Contacts informations and its todos for various purposes.<br>
 *
 *  All of the informations is stored in a local SQLite database.
 *
 * \subsection runStep Running the app
 *
 * Run ContactManagement.sh
 *
 */

/**
 * <p></p>
 * @brief main program. Launches the main window.
 */
int main(int argc, char *argv[]){

    bool withUI = true;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    if(withUI){
        return a.exec();
    }else{
        return 1;
    }
}
