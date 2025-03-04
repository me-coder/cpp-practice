/**
 *	Author YHP
 *	Created: 16-March-2008
 */

#ifndef _CSTRINGHANDLER
#define _CSTRINGHANDLER

#include "StringHandler.h"

class STRING_HANDLER_API CStringHandler
{
public:
    /**
     *	Default constructor.
     */
    CStringHandler();

    /**
     *	Parameterized constructor.
     */
    CStringHandler(const char *str);

    /**
     *	Parameterized constructor.
     */
    CStringHandler(const double num);

    /**
     *	Copy constructor.
     */
    CStringHandler(const CStringHandler &cstr);

    /**
     *	Dstructor.
     */
    ~CStringHandler();

    /**
     *	Returns charcter string for this CStringHandler object
     */
    const char *CSHToChar(void) const;

    /**
     *	CStringHandler object is returned as substring of this string as defined by the input parameters.
     *	The return type is an indication for the success of the method call.
     */
    bool SubString(const int start, const int end, CStringHandler &ocstr);

    /**
     *	Concatanates a string passed to the object this string
     */
    bool Append(const char *str);

    /**
     *	Returns length of this string as an integer value.
     */
    unsigned int GetLength(void) const;

    /**
     *	Converts all characters of this string to upper case.
     */
    bool ToUpper(void);

    /**
     *	Converts all characters of this string to lower case.
     */
    bool ToLower(void);

    /**
     *	Converts a passed 'this' CStringHandler object to double.
     */
    double CSHToDouble(void) const;

    /**
     *	Converts a passed character string to double.
     */
    double CSHToDouble(const char *str) const;

    /**
     *	Searches for specified substring and returns
     *	the index of its first occurence
     *	In case of error returns -1
     */
    int IndexOf(const char *str) const;

    /**
     *	Searches for specified substring from specified index
     *	and returns the index of its first occurence
     *	In case of error returns -1
     */
    int IndexOf(const char *str, const int beginIndex) const;

    /**
     *	Searches for specified substring and returns
     *	the index of its last occurence
     *	In case of error returns -1
     */
    int LastIndexOf(char *str) const;

    /**
     *	Splits the string of "this" object at the character 'ch'
     *	and passes the new CStringHandler Objects and
     *	also the number of new strings count.
     *	Call Cleanup method after utilization of strings to avoid memory leaks
     */
    bool Split(CStringHandler **&strArr, const char *ch, int &count) const;

    /**
     *	Overloads the above method for handling char*.
     */
    bool Split(CStringHandler **&strArr, char *str, const char *ch, int &count) const;

    /**
     *	Replaces character at specified index with the new character
     */
    bool Replace(const int atIndex, const char ch);

    /**
     *	Replaces specified string (toreplace) with new string(newstr)
     */
    bool Replace(const char *toreplace, const char *newstr);

    /**
     *	Replaces specified characters mentioned by char* (all occurences of
     *	individual charactes in this string) from 'this' CStringHandler object
     *	and returns a new CStringHandler object.
     */
    bool RemoveAll(const char *ch);

    /**
     *	Overloads the above method for handling char*.
     */
    bool RemoveAll(char *&str, const char *ch);

    /**
     *	Allocates CStringHandler array of size specified.
     *	It is a good practice to call 'Cleanup' method after using this array
     *	to avoid memory leak issues.
     *	This method returns a 1D array of CStringHandler pointer objects.
     */
    static bool CSHArray(CStringHandler **&strArr, const int count);

    /**
     *	Cleans "count" number of objects contained by strArr array
     */
    static bool CSHCleanup(CStringHandler **&strArr, const int count);

    /**
     *	Operator '==' overload
     */
    bool operator==(const CStringHandler &cstr);

    /**
     *	Operator '==' overload
     */
    bool operator==(const char *str);

    /**
     *	Operator '+=' overload
     */
    void operator+=(const CStringHandler cstr);

    /**
     *	Operator '+=' overload
     */
    void operator+=(const char *str);

    /**
     *	Operator '=' overload
     */
    CStringHandler &operator=(const CStringHandler cstr);

    /**
     *	Operator '=' overload
     */
    CStringHandler &operator=(const char *str);

    /**
     *	Operator '+' overload
     */
    void operator+(CStringHandler cstr);

    /**
     *	Operator '+' overload
     */
    void operator+(const char *str);

private:
    char *m_str;
};

#endif
