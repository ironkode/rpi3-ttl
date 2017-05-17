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

    uint8_t loopamount = 50; // Holds the amount of lines read, standard 50 lines
    bool keeplooping = true; // whether or not the loop should continue if strange things are found

    if (logfile.is_open())
    {
        logfile.seekg(-1, ios_base::end); // Go to one char before the end of the file
        while ((loopamount > 0) && keeplooping)
        {
            char currentchar;
            logfile.get(currentchar); //  get the current char being read
            if ((int) logfile.tellg() <= 1) // If the current character is at or before the last byte
            {
                logfile.seekg(0); // return to beginning of the first line
                getline(logfile, result); // set the first (so last line in the result) and smash that like button
                return result;
            } else if(currenchar == '\n') { // run through file untill new line is detected, then put it into the string
                getline(logfile, currentline);
                result.append(currentline);
                ++loopamount;
                logfile.seekg(-1, ios_base::current);
            } else {
                logfile.seekg(-2, ios_base::current);
            }
            return result;
        }
    }
    return; // Maybe add some error reporting idk love
}


const string
errorrep::currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
