#include "test_seq.h"
#include "test_sorts.h"
#include "Interface.h"


int main ()
{
    Test_seq();
    TEST_ALL_SORTS();
    cout << " ----------------------------------------------------------------------------" << endl;
    cout << "|           The sequence and sorting tests were successful!                  |" << endl;
    cout << " ----------------------------------------------------------------------------" << endl;
    Interface();
}
