#include "Validation.h"
#include "Manager.h"

int main(int argc, char* argv[])
{
    Validation validation;
    validation.ValidParametrs(argc, argv);
    Manager manager = Manager();
}
