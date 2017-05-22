#ifndef ERRORREP_H
#define ERRORREP_H

#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


// ***********************************************************************************
// **                THAT THIS LIB MAY NEVER BE USED, GOD BLESS                     **
// ***********************************************************************************
// **                   One of the top classess of its class                        **
// **                                                                               **
// ** -  When the constructor is called add the name of the file to be written to.  **
// ** -  The resume bool in the constructor is used to set if the file must append. **
// ** -  write_log(string fault) writes the error to the file, returning success.   **
// ** -  When an error string is written to a file datetime is automatically added. **
// ** -  read_log returns a string with the last 50 errors recorded in the file.    **
// **                                                                               **
// ***********************************************************************************



class errorrep
{
public:
    errorrep(const char * location, bool resume);
    ~errorrep();
    const bool write_log(string fault);
    const string read_log();
private:
    const string currentDateTime();
    fstream logfile;
};






#endif // ERRORREP_H
