#include "errorrep.h"

using namespace std;


errorrep::errorrep(const char *location, bool resume)
{
    // set up the file depending on the given location and whether or not the file must be appended
    if (resume = false) // Continue if true
    {
        logfile.open(location, ios::in | ios::out | ios::trunc); // Truncate: Erase existing data and create new
        if (logfile.is_open())
        {
            logfile << "Starting logging with new file at " << currentDateTime() << endl;
        }
    } else {
        logfine.open(location, ios::in | ios::out | ios::app); // Append: continue at the end of the file
        logfile << "Continuing logging in existing file at " <<currentDateTime() << endl;
    }

}

errorrep::~errorrep()
{
    // close the current file and add a nice message showing when logging stopped.
    if (logfile.is_open())
    {
        logfile << "Stopping Logging at " << currentDateTime() << endl;
        logfile.close();
    } else {
        break;
     }
}


const bool
errorrep::write_log(errors fault)
{
    // Write predefined codes to the logfile
    if (logfile.is_open())
    {
        logfile << fault << " at " << currentDateTime() << endl;
    }
}


const string
errorrep::read_log()
{
    // Reads the text in a logfile
    string result;
    string currentline;

    if (logfile.is_open())
    {
        while (getline(logfile, currentline))
        {
            result << result + currentline << '\n';
        }

    }
}
