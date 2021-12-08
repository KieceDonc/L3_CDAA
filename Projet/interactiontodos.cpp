#include "interactiontodos.h"

/**
 * @class InteractionTodos
 * A container class for InteractionTodos. Represents the idea that a Relational Database only has <b>atomic values</b><br>
 * It is not a list of pointers because an InteractionTodo has no reason to exist out of this list. Therefore every time there is the need to use an element of this list,
 * a pointer towards it has to be created.
 *
 * \subsection ex Example
 * Here is an example of the itList attribute of an InteractionTodos object with the following interaction :<br>
 * Interaction * i = new Interaction("Please Valentin we really need to finish this school project. @TODO Brew some coffee @TODO Rush the remaining work")
 *
 * <table><tr><td colspan="2"><b>1st element of itList (InteractionTodo type)</b></td></tr>
 * <tr><td><b>attribute I</b></td><td><b>attribute T</b></td></tr><tr><td>i</td><td>new Todo("Brew some coffee")</td></tr>
 * <tr><td colspan="2"><b>2nd element of itList (InteractionTodo type)</b></td></tr>
 * <tr><td><b>attribute I</b></td><td><b>attribute T</b></td></tr><tr><td>i</td><td>new Todo("Rush the remaining work")</td></tr></table><br><br>
 *
 * \subsection db Relational Database point of view
 * The whole point of this hard work is to be able to easily work with the database.
 * The previous <b>example</b> easily translates into a Relational Database table :<br>
 * <table><tr><td colspan="2"><b>InteractionTodo Relation</b></tr></td>
 * <tr><td><b>Interaction_ID</b></td><td><b>Todo_ID</b></td>
 * <tr><td>. . .</td><td>. . .</td></tr>
 * <tr><td>548</td><td>24</td></tr>
 * <tr><td>548</td><td>25</td></tr>
 * <tr><td>. . .</td><td>. . .</td></tr>
 * </table><br>
 *
 * <table><tr><td colspan="2"><b>Interaction Relation</b></tr></td>
 * <tr><td><b>Interaction_ID</b></td><td><b>Interaction_Content</b></td>
 * <tr><td>547</td><td>. . .</td></tr>
 * <tr><td>548</td><td>Please Valentin we really need to finish this school project. @TODO Brew some coffee @TODO Rush the remaining work</td></tr>
 * <tr><td>549</td><td>. . .</td></tr>
 * </table><br>
 *
 * <table><tr><td colspan="2"><b>Todo Relation</b></tr></td>
 * <tr><td><b>Todo_ID</b></td><td><b>Todo_Content</b></td>
 * <tr><td>23</td><td>. . .</td></tr>
 * <tr><td>24</td><td>Brew some coffee</td></tr>
 * <tr><td>25</td><td>Rush the remaining work</td></tr>
 * <tr><td>26</td><td>. . .</td></tr>
 * </table><br>
 * <i>/!\ In those tables, dates are not taken into account!!!</i>
 *
 *
 *
 *
 */

/**
 * @brief Constructs a new InteractionTodos object with an empty list of InteractionTodo objects
 *
 */
InteractionTodos::InteractionTodos() {
    this->setItList(new std::list<InteractionTodo>());
}

/**
 * @brief Destroys the Interaction Todos:: Interaction Todos object
 *
 */
InteractionTodos::~InteractionTodos(){
    delete this->itList;
}

/**
 * @brief Sets itList with a pointer on a a list of Interaction Todo
 *
 * @param itList
 */
void InteractionTodos::setItList(std::list<InteractionTodo> * itList){
    this->itList = itList;
}

/**
 * @brief Returns a pointer on the list of InteractionTodos
 *
 * @return std::list<InteractionTodo>*
 */
std::list<InteractionTodo> * InteractionTodos::getItList() {
    return this->itList;
}


/**
 * @brief Method adding to the container the list of InteractionTodo objects from a given Interaction.<br>
 * As in, the set of links between the given Interaction and all its todos. <br>
 *
 * \subsection ex Example
 * Interaction * i new Interaction("The quick brown fox @TODO jumps over @TODO the lazy dog");<br>
 * addInteraction(i);<br><br>
 * Should add two elements to the list :<br>
 * new InteractionTodo(i,new Todo("jumps over")) and new InteractionTodo(i,new Todo("the lazy dog"))
 *
 * @param interaction The interaction to retrieve the Todos from.
 */
void InteractionTodos::addInteraction(Interaction * interaction) {


    // 1 - Let's split the interaction between the TODO tags and push the substrings in a list. For self-harm purposes, we will use regex and according smatch.
    std::list<std::string> splits = std::list<std::string>();
    std::string contenu = interaction->getContent();
    std::regex pattern("@TODO");
    std::smatch match;


    while(regex_search(contenu,match,pattern)){
        int positionTodo = match.position();                        // 1st @TODO position in the string
        splits.push_back(contenu.substr(0,positionTodo));           // Adding the content of the string before the first @TODO in the list
        contenu = contenu.substr(positionTodo + match.length());    // Removing the @TODO
        if(contenu[0] == ' ')                                       // Removing the first space character if there is one
            contenu = contenu.substr(1,contenu.length());
    }
    if(!contenu.empty())                                            // Adding the last todo element
        splits.push_back(contenu);

    // 2 - If there is any text before the first TODO, remove it
    if(!splits.front().find("@TODO") != std::string::npos)          //Checking for any list element that does not contain @TODO
        splits.pop_front();

    // 3 - Fill the InteractionTodo list with freshly created todos from the splits list (and an iterator)
    for(std::list<std::string>::iterator it = splits.begin() ; it != splits.end() ; it++ ){
        this->getItList()->push_back(InteractionTodo(new Todo(*it) , interaction));
    }
}

/**
 * @brief returns the debug values.
 *
 * @param nbTabulations Number of tabulations needed to show informations.
 * If called outside of getDebugValues function this value should be set to 0.
 * Inside DebugValue this value should be set to nbTabulations+1 for others getDebugsValues()
 * @return std::string
 */
std::string InteractionTodos::getDebugValues(int nbTabulations) {
    return " ";
}

/**
* @brief Overloading of the << operator. Redirects the following string in the output stream :<br><br>
 * [InteractionTodo]<br>[InteractionTodo]<br>. . . . .<br>[InteractionTodo]
 *
 * @param os The out stream
 * @param it The InteractionTodo object to get values from
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, InteractionTodos& it){
    for(std::list<InteractionTodo>::iterator iter = it.getItList()->begin() ; iter != it.getItList()->end() ; iter++ ){
        os << *iter << "\n";
    }
    return os;
}

