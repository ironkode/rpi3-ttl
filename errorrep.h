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
// ** -   **
// ** -   **
// ** -   **
// ** -   **
// **                                                                               **
// ***********************************************************************************



class errorrep
{
    enum errors // Add your errors here boys
    {
        // TTL driver errors
        TTL_WRITECLOSED = "UART WRITE ERROR: Uart_stream is closed or faulty",
        TTL_WRITELENGTH = "UART WRITE ERROR: Written Bytes do not correlate to the size of the data",
        TTL_READLENGTH  = "UART READ ERROR: Unable to read from interface, unknown error",
        TTL_READNODATA  = "UART READ ERROR: No bytes in buffer to read",
        TTL_SETUPSTREAM = "UART SETUP ERROR: Unable to setup UART interface"
    };


public:
    errorrep(const char * location, bool resume);
    ~errorrep();
    const bool write_log(errors fault);
    const string read_log();
private:
    const string currentDateTime();
    fstream logfile;
};






#endif // ERRORREP_H
