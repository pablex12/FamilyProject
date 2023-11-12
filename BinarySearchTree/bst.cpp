#include "bst.h"

using namespace std;

Node::Node(Person &Partner1, Person &Partner2)
{
    this->boyFriend = Partner1;
    this->girlFriend = Partner2;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(Node *leftBranch, Person &Partner1, Person &Partner2, Node *rightBranch)
{
    this->boyFriend = Partner1;
    this->girlFriend = Partner2;
    this->left = leftBranch;
    this->right = rightBranch;
}

string Node::nodeValue()
{
    return boyFriend.getFullName() + " es pareja de " + girlFriend.getFullName();
}

Node *Node::leftSubTree()
{
    return left;
}

Node *Node::rightSubTree()
{
    return right;
}

BST::BST() : root(nullptr)
{
}

BST::BST(Node *r) : root(r)
{
}

Node *BST::newTree(Node *LeftSubTree, Person &Partner1, Person &Partner2, Node *RightBranch)
{
    return new Node(LeftSubTree, Partner1, Partner2, RightBranch);
}

void BST::insert(Person &Partner1, Person &Partner2)
{
    root = insert(root, Partner1, Partner2);
}

Node *BST::insert(Node *currentRoot, Person &Partner1, Person &Partner2)
{

    if (currentRoot == nullptr)
    {

        return new Node(Partner1, Partner2);
    }
    else if (currentRoot->right == nullptr && isMatchingParents(currentRoot, Partner1, Partner2))
    {

        currentRoot->right = insert(currentRoot->right, Partner1, Partner2);
    }
    else if (currentRoot->left == nullptr && isMatchingParents(currentRoot, Partner1, Partner2))
    {

        currentRoot->left = insert(currentRoot->left, Partner1, Partner2);
    }
    else
    {

        if (isMatchingParentLastName(currentRoot, Partner1, Partner2) && isMatchingParents(currentRoot->right, Partner1, Partner2))
        {

            currentRoot->right = insert(currentRoot->right, Partner1, Partner2);
        }
        else if (isMatchingParentLastName(currentRoot, Partner1, Partner2) && isMatchingParents(currentRoot->left, Partner1, Partner2))
        {

            currentRoot->left = insert(currentRoot->left, Partner1, Partner2);
        }
        else if (isMatchingParentSecondLastName(currentRoot, Partner1, Partner2) && isMatchingParents(currentRoot->left, Partner1, Partner2))
        {

            currentRoot->left = insert(currentRoot->left, Partner1, Partner2);
        }
        else if (isMatchingParentSecondLastName(currentRoot, Partner1, Partner2) && isMatchingParents(currentRoot->right, Partner1, Partner2))
        {

            currentRoot->right = insert(currentRoot->right, Partner1, Partner2);
        }
    }

    return currentRoot;
}

bool BST::isMatchingParents(Node *node, Person &Partner1, Person &Partner2)
{
    return (node->boyFriend.getLastName() == Partner1.getLastName() && node->girlFriend.getLastName() == Partner1.getSecondLastName()) ||
           (node->boyFriend.getLastName() == Partner2.getLastName() && node->girlFriend.getLastName() == Partner2.getSecondLastName());
}

bool BST::isMatchingParentLastName(Node *node, Person &Partner1, Person &Partner2)
{
    return (node->boyFriend.getLastName() == Partner1.getLastName()) ||
           (node->boyFriend.getLastName() == Partner2.getLastName());
}

bool BST::isMatchingParentSecondLastName(Node *node, Person &Partner1, Person &Partner2)
{
    return (node->boyFriend.getLastName() == Partner1.getSecondLastName()) ||
           (node->boyFriend.getLastName() == Partner2.getSecondLastName());
}

void BST::printBT()
{
    printBT("", this->root, false);
}

void BST::printBT(const string &prefix, Node *node, bool isLeft)
{
    if (node != nullptr)
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──");

        // print the value of the node
        cout << node->nodeValue() << endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "│   " : "    "), node->leftSubTree(), true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->rightSubTree(), false);
    }
}

////////////////////////////////////////////////

// Para iniciar el recorrido en orden desde la raíz del árbol, puedes llamar a esta función desde fuera de la clase BST de la siguiente manera:

Person *BST::postOrderArray()
{
    // Inicializa el arreglo
    memset(people, 0, sizeof(people));

    postOrderArray(root, 0);
    return people;
}

int BST::postOrderArray(Node *node, int index)
{
    if (node == nullptr)
        return index;

    // Recursivamente, agrega las personas al arreglo en el orden correcto
    index = postOrderArray(node->leftSubTree(), index);
    index = postOrderArray(node->rightSubTree(), index);

    people[index++] = node->boyFriend;
    people[index++] = node->girlFriend;

    return index;
}

Person *BST::preOrderArray()
{
    // Inicializa el arreglo
    memset(people, 0, sizeof(people));

    preOrderArray(root, 0);
    return people;
}

int BST::preOrderArray(Node *node, int index)
{
    if (node == nullptr)
        return index;

    // Recursivamente, agrega las personas al arreglo en el orden correcto
    people[index++] = node->boyFriend;
    people[index++] = node->girlFriend;
    index = preOrderArray(node->leftSubTree(), index);
    index = preOrderArray(node->rightSubTree(), index);

    return index;
}

Person *BST::inOrderArray()
{
    // Inicializa el arreglo
    memset(people, 0, sizeof(people));

    inOrderArray(root, 0);
    return people;
}

int BST::inOrderArray(Node *node, int index)
{
    if (node == nullptr)
        return index;

    // Recursivamente, agrega las personas al arreglo en el orden correcto
    index = inOrderArray(node->leftSubTree(), index);
    people[index++] = node->boyFriend;
    people[index++] = node->girlFriend;
    index = inOrderArray(node->rightSubTree(), index);

    return index;
}

Person *BST::findRelativeMember(const string &fullName, Relationship relationship)
{
    Person *result = findRelativeMember(root, fullName, relationship);
    return result ? new Person(*result) : nullptr;
}

Person *BST::findRelativeMember(Node *node, const string &fullName, Relationship relationship)
{
    size_t firstSpacePos = fullName.find(' ');
    size_t secondSpacePos = fullName.find(' ', firstSpacePos + 1);

    string name = fullName.substr(0, firstSpacePos);
    string lastName = fullName.substr(firstSpacePos + 1, secondSpacePos - firstSpacePos - 1);
    string secondLastName = fullName.substr(secondSpacePos + 1);

    if (node == nullptr)
        return nullptr;

    if (isValidRelationship(fullName, relationship) == false)
    {
        return nullptr;
    }

    Person currentPerson = node->boyFriend;
    string currentFullName = currentPerson.getFullName();

    // Verificar si la persona actual coincide con el nombre proporcionado
    if (currentFullName == fullName)
        return nullptr; // No se puede ser pariente de uno mismo

    // Verificar la relación con la persona actual
    switch (relationship)
    {
    case GRANDFATHER:
        return findGrandParent(node, fullName, lastName, secondLastName, relationship);
        break;
    case GRANDMOTHER:
        return findGrandParent(node, fullName, lastName, secondLastName, relationship);
        break;
    case FATHER:
        return findParent(node, fullName, lastName, secondLastName, relationship);
        break;
    case MOTHER:
        return findParent(node, fullName, lastName, secondLastName, relationship);
        break;
    case BROTHER:
        return findSibling(node, fullName, lastName, secondLastName, relationship);
        break;
    case SISTER:
        return findSibling(node, fullName, lastName, secondLastName, relationship);
        break;
    case BROTHERINLAW:
        return findInLaw(node, fullName, lastName, secondLastName, relationship);
        break;
    case SISTERINLAW:
        return findInLaw(node, fullName, lastName, secondLastName, relationship);
        break;
    default:
        break;
    }
    return nullptr;
}

int BST::getHeight(const string &fullName)
{
    return getHeight(root, fullName, 0);
}

int BST::getHeight(Node *node, const string &fullName, int currentHeight)
{
    if (node == nullptr)
    {
        // La persona no se encontró en el árbol
        return -1;
    }

    // Verificar si la persona actual coincide con el nombre proporcionado
    if (node->boyFriend.getFullName() == fullName || node->girlFriend.getFullName() == fullName)
    {
        // La persona se encontró, devuelve la altura actual
        return currentHeight;
    }

    // Buscar en el subárbol izquierdo y derecho
    int leftHeight = getHeight(node->leftSubTree(), fullName, currentHeight + 1);
    int rightHeight = getHeight(node->rightSubTree(), fullName, currentHeight + 1);

    // Devolver la altura máxima entre el subárbol izquierdo y derecho
    return max(leftHeight, rightHeight);
}

bool BST::isValidRelationship(const string &fullName, Relationship relationship)
{
    int height = getHeight(fullName);

    if (height == -1)
    {
        // La persona no se encontró en el árbol
        return false;
    }
    // Caso Abuelo
    if ((height == 0) && (relationship == GRANDFATHER || relationship == GRANDMOTHER || relationship == BROTHER || relationship == SISTER || relationship == BROTHERINLAW || relationship == SISTERINLAW || relationship == FATHER || relationship == MOTHER))
    {
        return false;
    }
    // Caso FATHER
    else if ((height == 1) && (relationship == GRANDFATHER || relationship == GRANDMOTHER))
    {
        return false;
    }
    else
    {
        return true;
    }
}

string BST::getGender(Relationship relationship)
{
    if (relationship == GRANDFATHER || relationship == BROTHER || relationship == BROTHERINLAW || relationship == FATHER)
        return "Hombre";
    else
        return "Mujer";
}

Person *BST::findGrandParent(const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship)
{
    return findGrandParent(root, fullName, lastName, secondLastName, relationship);
}

Person *BST::findGrandParent(Node *node, const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship)
{
    if (node == nullptr)
        return nullptr;

    if ((getGender(relationship) == "Hombre") && (node->boyFriend.getLastName() == lastName || node->boyFriend.getLastName() == secondLastName))
    {
        return &node->boyFriend;
    }
    else if ((getGender(relationship) == "Mujer") && (node->boyFriend.getLastName() == lastName || node->boyFriend.getLastName() == secondLastName))
    {
        return &node->girlFriend;
    }
    else
    {
        return nullptr;
    }
}

Person *BST::findParent(const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship)
{
    return findParent(root, fullName, lastName, secondLastName, relationship);
}

Person *BST::findParent(Node *node, const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship)
{
    if (node == nullptr)
        return nullptr;

    if (getGender(relationship) == "Hombre")
    {

        if (node->leftSubTree() != nullptr && (node->leftSubTree()->boyFriend.getFullName() == fullName || node->leftSubTree()->girlFriend.getFullName() == fullName))
        {
            if (node->boyFriend.getLastName() == lastName && node->girlFriend.getLastName() == secondLastName)
            {
                return &node->boyFriend;
            }
            else
            {
                return nullptr;
            }
        }
        else if (node->rightSubTree() != nullptr && (node->rightSubTree()->boyFriend.getFullName() == fullName || node->rightSubTree()->girlFriend.getFullName() == fullName))
        {
            if (node->boyFriend.getLastName() == lastName && node->girlFriend.getLastName() == secondLastName)
            {
                return &node->boyFriend;
            }
            else
            {
                return nullptr;
            }
        }
        else
        {
            // Llama a las funciones recursivas y utiliza los resultados
            Person *leftResult = findParent(node->leftSubTree(), fullName, lastName, secondLastName, relationship);
            Person *rightResult = findParent(node->rightSubTree(), fullName, lastName, secondLastName, relationship);

            return (leftResult != nullptr) ? leftResult : rightResult;
        }
    }
    else if (getGender(relationship) == "Mujer")
    {

        if (node->leftSubTree() != nullptr && (node->leftSubTree()->girlFriend.getFullName() == fullName || node->leftSubTree()->boyFriend.getFullName() == fullName))
        {

            if (node->boyFriend.getLastName() == lastName && node->girlFriend.getLastName() == secondLastName)
            {
                cout << node->girlFriend.getFullName() << endl;
                return &node->girlFriend;
            }
            else
            {
                return nullptr;
            }
        }

        else if (node->rightSubTree() != nullptr && (node->rightSubTree()->girlFriend.getFullName() == fullName || node->rightSubTree()->boyFriend.getFullName() == fullName))
        {

            if (node->boyFriend.getLastName() == lastName && node->girlFriend.getLastName() == secondLastName)
            {
                cout << node->girlFriend.getFullName() << endl;
                return &node->girlFriend;
            }
            else
            {
                return nullptr;
            }
        }
        else
        {
            // Llama a las funciones recursivas y utiliza los resultados
            Person *leftResult = findParent(node->leftSubTree(), fullName, lastName, secondLastName, relationship);
            Person *rightResult = findParent(node->rightSubTree(), fullName, lastName, secondLastName, relationship);

            return (leftResult != nullptr) ? leftResult : rightResult;
        }
    }
    else
    {
        return nullptr;
    }
}

Person *BST::findSibling(const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship)
{
    return findSibling(root, fullName, lastName, secondLastName, relationship);
}

Person *BST::findSibling(Node *node, const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship)
{
    if (node == nullptr)
        return nullptr;

    if (getGender(relationship) == "Hombre")
    {

        if (node->leftSubTree() != nullptr && (node->leftSubTree()->boyFriend.getFullName() == fullName || node->leftSubTree()->girlFriend.getFullName() == fullName))
        {
            if (node->rightSubTree() != nullptr && (node->rightSubTree()->boyFriend.getLastName() == lastName && node->rightSubTree()->boyFriend.getSecondLastName() == secondLastName))
            {

                return &node->rightSubTree()->boyFriend;
            }
            // else if (node->rightSubTree() != nullptr && (node->rightSubTree()->girlFriend.getLastName() == lastName && node->rightSubTree()->girlFriend.getSecondLastName() == secondLastName))
            // {
            //     return &node->rightSubTree()->girlFriend;
            // }
            else
            {
                return nullptr;
            }
        }
        else if (node->rightSubTree() != nullptr && (node->rightSubTree()->boyFriend.getFullName() == fullName || node->rightSubTree()->girlFriend.getFullName() == fullName))
        {
            if (node->leftSubTree() != nullptr && (node->leftSubTree()->boyFriend.getLastName() == lastName && node->leftSubTree()->boyFriend.getSecondLastName() == secondLastName))
            {

                return &node->leftSubTree()->boyFriend;
            }
            // else if (node->leftSubTree() != nullptr && (node->leftSubTree()->girlFriend.getLastName() == lastName && node->leftSubTree()->girlFriend.getSecondLastName() == secondLastName))
            // {
            //     return &node->leftSubTree()->girlFriend;
            // }
            else
            {
                return nullptr;
            }
        }
        else
        {
            // Llama a las funciones recursivas y utiliza los resultados
            Person *leftResult = findSibling(node->leftSubTree(), fullName, lastName, secondLastName, relationship);
            Person *rightResult = findSibling(node->rightSubTree(), fullName, lastName, secondLastName, relationship);

            return (leftResult != nullptr) ? leftResult : rightResult;
        }
    }
    else if (getGender(relationship) == "Mujer")
    {

        if (node->leftSubTree() != nullptr && (node->leftSubTree()->girlFriend.getFullName() == fullName || node->leftSubTree()->boyFriend.getFullName() == fullName))
        {

            // if (node->rightSubTree() != nullptr && (node->rightSubTree()->boyFriend.getLastName() == lastName && node->rightSubTree()->boyFriend.getSecondLastName() == secondLastName))
            // {

            //     return &node->rightSubTree()->boyFriend;
            // }
            if (node->rightSubTree() != nullptr && (node->rightSubTree()->girlFriend.getLastName() == lastName && node->rightSubTree()->girlFriend.getSecondLastName() == secondLastName))
            {
                return &node->rightSubTree()->girlFriend;
            }
            else
            {
                return nullptr;
            }
        }

        else if (node->rightSubTree() != nullptr && (node->rightSubTree()->girlFriend.getFullName() == fullName || node->rightSubTree()->boyFriend.getFullName() == fullName))
        {

            // if (node->leftSubTree() != nullptr && (node->leftSubTree()->boyFriend.getLastName() == lastName && node->leftSubTree()->boyFriend.getSecondLastName() == secondLastName))
            // {

            //     return &node->leftSubTree()->boyFriend;
            // }
            if (node->leftSubTree() != nullptr && (node->leftSubTree()->girlFriend.getLastName() == lastName && node->leftSubTree()->girlFriend.getSecondLastName() == secondLastName))
            {
                return &node->leftSubTree()->girlFriend;
            }
            else
            {
                return nullptr;
            }
        }
        else
        {
            // Llama a las funciones recursivas y utiliza los resultados
            Person *leftResult = findSibling(node->leftSubTree(), fullName, lastName, secondLastName, relationship);
            Person *rightResult = findSibling(node->rightSubTree(), fullName, lastName, secondLastName, relationship);

            return (leftResult != nullptr) ? leftResult : rightResult;
        }
    }
    else
    {
        return nullptr;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Person *BST::findInLaw(const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship)
{
    return findInLaw(root, fullName, lastName, secondLastName, relationship);
}

Person *BST::findInLaw(Node *node, const string &fullName, const string &lastName, const string &secondLastName, Relationship relationship)
{
    if (node == nullptr)
        return nullptr;
    if (getGender(relationship) == "Hombre")
    {

        if (node->leftSubTree() != nullptr && (node->leftSubTree()->boyFriend.getFullName() == fullName || node->leftSubTree()->girlFriend.getFullName() == fullName))
        {
            if (node->rightSubTree() != nullptr && (node->rightSubTree()->boyFriend.getLastName() != lastName && node->rightSubTree()->boyFriend.getSecondLastName() != secondLastName))
            {
                return &node->rightSubTree()->boyFriend;
            }
            else
            {
                return nullptr;
            }
        }
        else if (node->rightSubTree() != nullptr && (node->rightSubTree()->boyFriend.getFullName() == fullName || node->rightSubTree()->girlFriend.getFullName() == fullName))
        {
            if (node->leftSubTree() != nullptr && (node->leftSubTree()->boyFriend.getLastName() != lastName && node->leftSubTree()->boyFriend.getSecondLastName() != secondLastName))
            {

                return &node->leftSubTree()->boyFriend;
            }

            else
            {
                return nullptr;
            }
        }
        else
        {
            // Llama a las funciones recursivas y utiliza los resultados
            Person *leftResult = findSibling(node->leftSubTree(), fullName, lastName, secondLastName, relationship);
            Person *rightResult = findSibling(node->rightSubTree(), fullName, lastName, secondLastName, relationship);

            return (leftResult != nullptr) ? leftResult : rightResult;
        }
    }
    else if (getGender(relationship) == "Mujer")
    {

        if (node->leftSubTree() != nullptr && (node->leftSubTree()->girlFriend.getFullName() == fullName || node->leftSubTree()->boyFriend.getFullName() == fullName))
        {

            // if (node->rightSubTree() != nullptr && (node->rightSubTree()->boyFriend.getLastName() == lastName && node->rightSubTree()->boyFriend.getSecondLastName() == secondLastName))
            // {

            //     return &node->rightSubTree()->boyFriend;
            // }
            if (node->rightSubTree() != nullptr && (node->rightSubTree()->girlFriend.getLastName() != lastName && node->rightSubTree()->girlFriend.getSecondLastName() != secondLastName))
            {
                return &node->rightSubTree()->girlFriend;
            }
            else
            {
                return nullptr;
            }
        }

        else if (node->rightSubTree() != nullptr && (node->rightSubTree()->girlFriend.getFullName() == fullName || node->rightSubTree()->boyFriend.getFullName() == fullName))
        {

            // if (node->leftSubTree() != nullptr && (node->leftSubTree()->boyFriend.getLastName() == lastName && node->leftSubTree()->boyFriend.getSecondLastName() == secondLastName))
            // {

            //     return &node->leftSubTree()->boyFriend;
            // }
            if (node->leftSubTree() != nullptr && (node->leftSubTree()->girlFriend.getLastName() != lastName && node->leftSubTree()->girlFriend.getSecondLastName() != secondLastName))
            {
                return &node->leftSubTree()->girlFriend;
            }
            else
            {
                return nullptr;
            }
        }
        else
        {
            // Llama a las funciones recursivas y utiliza los resultados
            Person *leftResult = findInLaw(node->leftSubTree(), fullName, lastName, secondLastName, relationship);
            Person *rightResult = findInLaw(node->rightSubTree(), fullName, lastName, secondLastName, relationship);

            return (leftResult != nullptr) ? leftResult : rightResult;
        }
    }
    else
    {
        return nullptr;
    }
}
