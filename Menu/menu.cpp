#include "menu.h"

Menu::Menu()
{
}

void Menu::display()
{
    Reader reader;
    reader.getPeopleInfo("familia.txt");
    reader.setPeoplePartners("relaciones.txt");
    // Person *peopleArray = reader.getPeople();
    Person *partnerArray = reader.getPartners();
    BST bst;
    for (int i = 0; i < 7; i++)
    {
        bst.insert(partnerArray[i], *partnerArray[i].getPartner());
    }
    bool Heap = true;
    // bool HeapSelected = true;
    string familyMember;
    int order = 0;
    string maxOrMin = "";
    string feature = "";
    cout << "~o~o~o~o|    BinarySearchTree    |~o~o~o~o" << endl
         << endl;
    bst.printBT();
    cout << endl;
    string selection;

    Person *postOrderArray = bst.postOrderArray();
    Person *preOrderArray = bst.preOrderArray();
    Person *inOrderArray = bst.inOrderArray();
    HeapTree heapTreeMax(true);
    HeapTree heapTreeMin(false);

    bool exit = true;
    int option;
    Person *relative = nullptr;

    do
    {
        // Mostrar el menú
        cout << "~o~o~o~o|    Menú    |~o~o~o~o" << endl;
        cout << "1. Abuelo     |       2. Abuela" << endl;
        cout << "3.  Papá      |       4.  Mamá" << endl;
        cout << "4. Hermano    |       6. Hermana" << endl;
        cout << "7. Cuñado     |       8. Cuñada" << endl;
        cout << "9. Heap Tree" << endl;
        cout << "~o~o~o~o~o~o~o~o~o~o~o" << endl;
        cout << "      0. Salir" << endl
             << endl;
        cout << "Ingrese su opción: ";
        // cin >> option;
        if (cin >> option)
        {
            // Si la lectura falla, limpiar el estado de error y el buffer

            if (option >= 0 && option <= 9)
            {
                cout << endl;
                switch (option)
                {
                case 1:
                    cout << "Abuelo de: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer del teclado
                    getline(cin, familyMember);
                    relative = bst.findRelativeMember(familyMember, GRANDFATHER);
                    if (relative != nullptr)
                    {

                        cout << "El pariente es: " << relative->getFullName() << endl
                             << endl;
                    }
                    else
                    {
                        cout << "No se encontró el familiar especificado." << endl
                             << endl;
                    }
                    break;

                case 2:
                    cout << "Abuela de: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer del teclado
                    getline(cin, familyMember);
                    relative = bst.findRelativeMember(familyMember, GRANDMOTHER);
                    if (relative != nullptr)
                    {

                        cout << "El pariente es: " << relative->getFullName() << endl
                             << endl;
                    }
                    else
                    {
                        cout << "No se encontró el familiar especificado." << endl
                             << endl;
                    }
                    break;
                case 3:
                    cout << "Papá de: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer del teclado
                    getline(cin, familyMember);
                    relative = bst.findRelativeMember(familyMember, FATHER);
                    if (relative != nullptr)
                    {

                        cout << "El pariente es: " << relative->getFullName() << endl
                             << endl;
                    }
                    else
                    {

                        cout << "No se encontró el familiar especificado." << endl
                             << endl;
                    }
                    break;
                case 4:
                    cout << "Mamá de: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer del teclado
                    getline(cin, familyMember);
                    relative = bst.findRelativeMember(familyMember, MOTHER);
                    if (relative != nullptr)
                    {

                        cout << "El pariente es: " << relative->getFullName() << endl
                             << endl;
                    }
                    else
                    {
                        cout << "No se encontró el familiar especificado." << endl
                             << endl;
                    }
                    break;
                case 5:
                    cout << "Hermano de: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer del teclado
                    getline(cin, familyMember);
                    relative = bst.findRelativeMember(familyMember, BROTHER);
                    if (relative != nullptr)
                    {

                        cout << "El pariente es: " << relative->getFullName() << endl
                             << endl;
                    }
                    else
                    {
                        cout << "No se encontró el familiar especificado." << endl
                             << endl;
                    }
                    break;
                case 6:
                    cout << " Hermana de: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer del teclado
                    getline(cin, familyMember);
                    relative = bst.findRelativeMember(familyMember, SISTER);
                    if (relative != nullptr)
                    {
                        cout << "El pariente es: " << relative->getFullName() << endl
                             << endl;
                    }
                    else
                    {
                        cout << "No se encontró el familiar especificado." << endl
                             << endl;
                    }
                    break;
                case 7:
                    cout << "Cuñado de: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer del teclado
                    getline(cin, familyMember);
                    relative = bst.findRelativeMember(familyMember, BROTHERINLAW);
                    if (relative != nullptr)
                    {
                        cout << "El pariente es: " << relative->getFullName() << endl
                             << endl;
                    }
                    else
                    {
                        cout << "No se encontró el familiar especificado." << endl
                             << endl;
                    }
                    break;
                case 8:
                    cout << "Cuñada de: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer del teclado
                    getline(cin, familyMember);
                    relative = bst.findRelativeMember(familyMember, SISTERINLAW);
                    if (relative != nullptr)
                    {
                        cout << "El pariente es: " << relative->getFullName() << endl
                             << endl;
                    }
                    else
                    {
                        cout << "No se encontró el familiar especificado." << endl
                             << endl;
                    }
                    break;
                case 9:
                    while (Heap)
                    {
                        cout << "¿Desea ver un Heap Máximo o Mínimo? (Escriba 'Max' o 'Min')" << endl;
                        cin >> maxOrMin;

                        if (maxOrMin == "Max" || maxOrMin == "max")
                        {
                            HeapTree heapTreeMax(true);

                            while (Heap)
                            {
                                cout << "Seleccione la característica (Edad, Ahorros, Ataque, Defensa, Sabiduría):" << endl;
                                cin >> feature;
                                int featureCode = heapTreeMax.getFeatureCode(feature);
                                if (featureCode != -1)
                                {
                                    cout << "Seleccione el orden de impresión (1. PostOrder, 2. PreOrder, 3. InOrder):" << endl;
                                    cin >> order;

                                    switch (order)
                                    {
                                    case 1:
                                        for (int i = 0; i < 14; i++)
                                        {
                                            heapTreeMax.insert(postOrderArray[i], featureCode);
                                        }
                                        break;
                                    case 2:
                                        for (int i = 0; i < 14; i++)
                                        {
                                            heapTreeMax.insert(preOrderArray[i], featureCode);
                                        }
                                        break;
                                    case 3:
                                        for (int i = 0; i < 14; i++)
                                        {
                                            heapTreeMax.insert(inOrderArray[i], featureCode);
                                        }
                                        break;
                                    default:
                                        cout << "Orden de impresión no válido. Intente nuevamente." << endl;
                                        break;
                                    }

                                    Person maxPerson = heapTreeMax.getExtremumFeaturePerson(featureCode, true);
                                    cout << endl;
                                    cout << "La persona con la el valor máximo para esta característica es: " << maxPerson.getFullName() << " con un valor de " << ((featureCode == 2) ? "$" + to_string(maxPerson.getFeatureValue(featureCode)) : to_string(maxPerson.getFeatureValue(featureCode))) << endl
                                         << endl;
                                    // Muestra detalles de la persona con la máxima característica
                                    // maxPerson.getName(), maxPerson.getAge(), etc.
                                    cout << "¿Quiere salir de esta opción? (Escriba 'Si' o 'No')  ";
                                    cin >> selection;
                                    cout << endl;
                                    if (selection == "Si" || selection == "si" || selection == "S" || selection == "s")
                                    {
                                        Heap = false;
                                    }
                                    break;
                                }
                                else
                                {
                                    cout << "Característica no válida. Intente nuevamente." << endl;
                                }
                            }
                        }
                        else if (maxOrMin == "Min" || maxOrMin == "min")
                        {
                            HeapTree heapTreeMin(false);

                            while (Heap)
                            {
                                cout << "Seleccione la característica (Edad, Ahorros, Ataque, Defensa, Sabiduría):" << endl;
                                cin >> feature;
                                int featureCode = heapTreeMin.getFeatureCode(feature);
                                if (featureCode != -1)
                                {
                                    cout << "Seleccione el orden de impresión (1. PostOrder, 2. PreOrder, 3. InOrder):" << endl;
                                    cin >> order;

                                    switch (order)
                                    {
                                    case 1:
                                        for (int i = 0; i < 14; i++)
                                        {
                                            heapTreeMin.insert(postOrderArray[i], featureCode);
                                        }
                                        break;
                                    case 2:
                                        for (int i = 0; i < 14; i++)
                                        {
                                            heapTreeMin.insert(preOrderArray[i], featureCode);
                                        }
                                        break;
                                    case 3:
                                        for (int i = 0; i < 14; i++)
                                        {

                                            heapTreeMin.insert(inOrderArray[i], featureCode);
                                        }

                                        break;
                                    default:
                                        cout << "Orden de impresión no válido. Intente nuevamente." << endl;
                                        break;
                                    }

                                    Person minPerson = heapTreeMin.getExtremumFeaturePerson(featureCode, false);

                                    cout << endl;
                                    cout << "La persona con la el valor máximo para esta característica es: " << minPerson.getFullName() << " con un valor de " << ((featureCode == 2) ? "$" + to_string(minPerson.getFeatureValue(featureCode)) : to_string(minPerson.getFeatureValue(featureCode))) << endl
                                         << endl;
                                    // Muestra detalles de la persona con la máxima característica
                                    // Muestra detalles de la persona con la mínima característica
                                    // minPerson.getName(), minPerson.getAge(), etc.
                                    cout << "¿Quiere salir de esta opción? (Escriba 'Si' o 'No')  ";
                                    cin >> selection;
                                    cout << endl;
                                    if (selection == "Si" || selection == "si" || selection == "S" || selection == "s")
                                    {
                                        Heap = false;
                                    }
                                    break;
                                }
                                else
                                {
                                    cout << "Característica no válida. Intente nuevamente." << endl;
                                }
                            }
                        }
                    }
                    break;
                case 0:
                    exit = false;
                    cout << endl;
                    cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                    break;

                default:
                    cout << "Opción no válida. Inténtelo de nuevo." << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            else
            {
                cout << "Número fuera de rango. Inténtelo de nuevo." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Opción no válida. Inténtelo de nuevo." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (exit);
}