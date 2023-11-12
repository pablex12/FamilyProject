
#include "Menu/menu.h"
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "spanish");
    Menu menu;
    menu.display();
    return 0;
}
