/**
 * Author Yashodhan Pise
 * Created: 16-March-2008
 * Modified: 21-March-2008
 * Modified: 29-March-2008
 * Updated: 09-February-2010
 */

/*
 *  This document has been designed to create a class that helps eliminate the pointer related * issues when handling a string (Just like in Java).
 *	This class can also be used as an example to understand the use of pointer and operator overloading concepts.
 */

#include "CStringHandler.h"

using namespace std;

/**
 * Default constructor.
 */
CStringHandler::CStringHandler()
{
  this->m_str = NULL;

  m_str = new char[1];
  m_str[0] = '\0';
}

/**
 * Parameterized constructor.
 */
CStringHandler::CStringHandler(const char *str)
{
  this->m_str = NULL;

  m_str = new char[strlen(str) + 1];
  strcpy(m_str, str);
}

/**
 * Parameterized constructor.
 */
CStringHandler::CStringHandler(const double num)
{
  char str[50];
  sprintf(str, "%lf", num);

  this->m_str = NULL;

  this->m_str = new char[strlen(str) + 1];
  strcpy(m_str, str);
}

/**
 * Copy constructor.
 */
CStringHandler::CStringHandler(const CStringHandler &cstr)
{
  this->m_str = NULL;

  // Deepcopy the string from cstr object
  this->m_str = new char[strlen(cstr.m_str) + 1];
  strcpy(m_str, cstr.m_str);
}

/**
 * Dstructor.
 */
CStringHandler::~CStringHandler()
{

  if (this->m_str)
    delete[] this->m_str;
  this->m_str = NULL;

  // cout<<"Destructor"<<endl;
}

/**
 * Returns charcter string for this CStringHandler object
 */
char *CStringHandler::CSHToChar(void) const
{
  return m_str;
}

/**
 * CStringHandler object is returned as substring of this string as defined by the input parameters.
 * The return type is an indication for the success of the method call.
 */
bool CStringHandler::SubString(const int start, const int end, CStringHandler &ocstr)
{
  if (start > end || end > (int)this->GetLength())
    return false;

  char *str = (char *)malloc(sizeof(char) * ((end - start) + 2));
  memset(str, 0x00, ((end - start) + 2));

  for (int i = start; i <= end; i++)
    str[i - start] = this->m_str[i];

  str[((end - start) + 1)] = '\0';

  ocstr += str;

  free((void *)str);
  str = NULL;

  return true;
}

/**
 * Concatanates a string passed to the object this string
 */
bool CStringHandler::Append(const char *str)
{
  bool b_rval = false;
  if (str && this->m_str)
  {
    char *tmp = (char *)realloc(this->m_str, sizeof(char) * (strlen(this->m_str) + strlen(str) + 1));

    if (NULL != tmp)
    {
      this->m_str = tmp;
      // strncat returns dest ptr or NULL if error
      b_rval = (strncat(this->m_str, str, strlen(str))) ? true : false;
    }
  }

  return b_rval;
}

/**
 * Returns length of this string as an integer value.
 */
unsigned int CStringHandler::GetLength(void) const
{
  unsigned int i_strlen = 0;
  if (this->m_str)
    i_strlen = strlen(this->m_str);

  return i_strlen;
}

/**
 * Converts all characters of this string to upper case.
 */
bool CStringHandler::ToUpper(void)
{
  bool b_rval = false;
  if (this->m_str)
  {
    for (unsigned int i = 0; i < strlen(this->m_str); i++)
      if (isalpha(this->m_str[i]) && islower(this->m_str[i]))
        this->m_str[i] = (char)toupper((int)this->m_str[i]);
    b_rval = true;
  }

  return b_rval;
}

/**
 * Converts all characters of this string to lower case.
 */
bool CStringHandler::ToLower(void)
{
  bool b_rval = false;
  if (this->m_str)
  {
    for (unsigned int i = 0; i < strlen(this->m_str); i++)
      if (isalpha(this->m_str[i]) && isupper(this->m_str[i]))
        this->m_str[i] = (char)tolower((int)this->m_str[i]);

    b_rval = true;
  }

  return b_rval;
}

/**
 * Converts a passed 'this' CStringHandler object to double.
 */
double CStringHandler::CSHToDouble(void) const
{
  return CSHToDouble(this->m_str);
}

/**
 * Converts a passed character string to double.
 */
double CStringHandler::CSHToDouble(const char *str) const
{
  return atof(str);
}

/**
 * Searches for specified substring and returns
 * the index of its first occurence
 * In case of error returns -1
 */
int CStringHandler::IndexOf(const char *str) const
{
  unsigned int strLen = strlen(str);        // Length of str
  unsigned int cstrLen = this->GetLength(); // Length of this string
  int index = -1;
  if (strLen > cstrLen)
    index = -1;
  else if (!strcmp(this->m_str, str))
    index = 0;
  else
  {
    for (unsigned int i = 0; i < cstrLen && index == -1; i++)
      if (this->m_str[i] == str[0])
        for (unsigned int j = 0; (j < strLen) && (this->m_str[i + j] == str[j]); j++)
          (j == strLen - 1) ? index = i : index = -1;

    // cout<<index << " : " << this->m_str[index]<<endl;
  }

  return index;
}

/**
 * Searches for specified substring from specified index
 * and returns the index of its first occurence
 * In case of error returns -1
 */
int CStringHandler::IndexOf(const char *str, const int beginIndex) const
{
  int index = -1;
  CStringHandler cstr(&(this->m_str[beginIndex]));
  return ((index = cstr.IndexOf(str)) != -1) ? beginIndex + index : index;
}

/**
 * Searches for specified substring and returns
 * the index of its last occurence
 * In case of error returns -1
 */
int CStringHandler::LastIndexOf(char *str) const
{
  unsigned int strLen = strlen(str);        // Length of str
  unsigned int cstrLen = this->GetLength(); // Length of this string
  int index = -1;

  if (!strcmp(this->m_str, str))
    index = 0;
  else if (strLen < cstrLen)
  {
    for (unsigned int i = cstrLen; i > 0 && index == -1; i--)
      if (this->m_str[i - 1] == str[strLen - 1])
        for (unsigned int j = 1; (j <= strLen) && (this->m_str[i - j] == str[strLen - j]); j++)
          (j == strLen) ? index = i - 1 : index = -1;
  }

  return index;
}

/**
 * Splits the string of "this" object at the character 'ch'
 * and passes the new CStringHandler Objects and
 * also the number of new strings count.
 * Call Cleanup method after utilization of strings to avoid memory leaks
 */
bool CStringHandler::Split(CStringHandler **&strArr, const char *ch, int &count) const
{
  return this->Split(strArr, this->m_str, ch, count);
}

/**
 * Overloads the above method for handling char*.
 */
bool CStringHandler::Split(CStringHandler **&strArr, char *str, const char *ch, int &count) const
{
  count = 0;
  if (!str)
    return false;

  char *dummy = (char *)malloc(sizeof(char) * (strlen(str) + 1));
  memset(dummy, 0x00, (strlen(str) + 1));
  strcpy(dummy, str);

  char **buf = (char **)malloc(sizeof(char *) * 1);
  char *temp = strtok(dummy, ch);

  while (NULL != temp)
  {
    // Allocate memory to copy temp to buf[i]
    buf[count] = (char *)malloc(sizeof(char) * (sizeof(temp) + 1));
    memset(buf[count], 0, sizeof(temp) + 1);
    // Copy string from temp to buf[i]
    strcpy(buf[count], temp);
    // cout<<buf[count]<<endl;
    temp = strtok(NULL, ch);

    // cout<<buf[count]<<endl;

    if (temp != NULL && strcmp(temp, buf[count]) != 0)
      buf = (char **)realloc(buf, sizeof(char *) * (count + 2));

    count++;
  }
  // cout<<"Comlpeted for loop"<<count<<endl;

  strArr = new CStringHandler *[count];

  // cout<<"Array formed"<<count<<endl;

  for (int j = 0; j < count && buf[j]; j++)
  {
    strArr[j] = new CStringHandler(buf[j]);
    // cout<<buf[j]<<endl;
    free((void *)buf[j]);
    buf[j] = NULL;
  }

  free(buf);
  buf = NULL;
  free(dummy);
  dummy = NULL;

  return true;
}

/**
 * Replace character at specified index with the new character
 */
bool CStringHandler::Replace(const int atIndex, const char ch)
{
  bool b_rval = false;
  if (this->m_str)
  {
    this->m_str[atIndex] = ch;
    b_rval = true;
  }

  return b_rval;
}

/**
 * Replace specified string (toreplace) with new string(newstr)
 */
bool CStringHandler::Replace(const char *toreplace, const char *newstr)
{
  if (!this->m_str || strlen(this->m_str) < strlen(toreplace))
    return false;

  unsigned int index = this->IndexOf(toreplace);
  unsigned int replaceLen = strlen(toreplace);
  unsigned int newLen = strlen(newstr);
  unsigned int length = (this->GetLength() + 1 + newLen - replaceLen);

  char *buf = (char *)malloc(sizeof(char) * (this->GetLength() + 1));
  memset(buf, 0x00, (this->GetLength() + 1));
  strcpy(buf, this->m_str);

  char *temp = buf;

  delete[] this->m_str;
  this->m_str = NULL;

  this->m_str = new char[length];

  for (unsigned int i = 0; i < length; i++)
  {
    if ((i >= index) && (i < index + newLen))
    {
      this->m_str[i] = *(newstr++);

      if (index + newLen - 1 == i)
        (index == 0) ? (temp += replaceLen) : (temp += replaceLen - 1);
    }
    else
      this->m_str[i] = *(temp++);

    // cout << this->m_str[i] << endl;
  }
  this->m_str[length - 1] = '\0';

  free(buf);
  buf = NULL;

  return true;
}

/**
 * Removes specified characters mentioned by char* (all occurences of
 * individual charactes in this string) from 'this' CStringHandler object
 * and returns execution status.
 */
bool CStringHandler::RemoveAll(const char *ch)
{
  bool b_rval = false;

  if (this->m_str)
  {
    try
    {
      char *dummy = (char *)malloc(sizeof(char) * (strlen(this->m_str) + 1));
      memset(dummy, 0x00, (strlen(this->m_str) + 1));
      strcpy(dummy, this->m_str);

      char *tokens = strtok(dummy, ch);

      char *buf = (char *)malloc(sizeof(char));
      buf[0] = '\0';

      while (tokens)
      {
        buf = (char *)realloc(buf, sizeof(char) * (strlen(buf) + strlen(tokens) + 1));
        buf = strncat(buf, tokens, strlen(tokens));
        // cout << buf << endl;
        tokens = strtok(NULL, ch);
      }
      free(dummy);
      dummy = NULL;

      if (buf)
      {
        this->m_str = (char *)realloc(this->m_str, sizeof(char) * (strlen(buf) + 1));
        if (this->m_str)
          strcpy(this->m_str, buf);

        b_rval = true;
        free(buf);
        buf = NULL;
      }
      else
      {
        b_rval = false;
      }
    }
    catch (...)
    {
      b_rval = false;
    }
  }

  return b_rval;
}

/**
 * Overloads the above method for handling char*.
 */
bool CStringHandler::RemoveAll(char *&str, const char *ch)
{
  if (!str)
    return false;

  try
  {
    char *temp = strtok(str, ch);
    char *buf = (char *)malloc(sizeof(char));
    memset(buf, 0x00, sizeof(char));

    while (temp)
    {
      buf = (char *)realloc(this->m_str, sizeof(char) * (strlen(str) + strlen(temp) + 1));
      strncat(buf, temp, strlen(temp) + 1);
      temp = strtok(NULL, ch);
    }

    str = (char *)realloc(str, sizeof(char) * (strlen(buf) + 1));

    free(buf);
    buf = NULL;
  }
  catch (...)
  {
    return false;
  }

  return true;
}

/**
 * Allocates CStringHandler array of size specified.
 * It is a good practice to call 'Cleanup' method after using this array
 * to avoid memory leak issues.
 * This method returns a 1D array of CStringHandler pointer objects.
 */
bool CStringHandler::CSHArray(CStringHandler **&strArr, const int count)
{
  if (!count)
    return false;

  strArr = new CStringHandler *[count];
  if (strArr)
    for (int i = 0; i < count; i++, strArr[i] = new CStringHandler)
      ;
  return true;
}

/**
 * Cleans "count" number of objects contained by strArr array
 */
bool CStringHandler::CSHCleanup(CStringHandler **&strArr, const int count)
{
  bool b_rval = false;

  if (strArr)
  {
    try
    {
      for (int i = 0; i < count; i++)
      {
        delete strArr[i];
        strArr[i] = NULL;
      }
      delete[] strArr;
      strArr = NULL;
      b_rval = true;
    }
    catch (...)
    {
      b_rval = false;
    }
  }
  return b_rval;
}

/**
 * Operator '==' overload.
 */
bool CStringHandler::operator==(const CStringHandler &cstr)
{
  return (!strcmp(this->m_str, cstr.CSHToChar())) ? true : false;
}

/**
 * Operator '==' overload.
 */
bool CStringHandler::operator==(const char *str)
{
  return (!strcmp(this->m_str, str)) ? true : false;
}

/**
 * Operator '+=' overload.
 */
void CStringHandler::operator+=(const CStringHandler cstr)
{
  this->Append(cstr.CSHToChar());
}

/**
 * Operator '+=' overload.
 */
void CStringHandler::operator+=(const char *str)
{
  this->Append(str);
}

/**
 * Operator '=' overload.
 */
void CStringHandler::operator=(const CStringHandler &cstr)
{
  delete[] this->m_str;
  this->m_str = new char[(int)cstr.GetLength() + 1];

  strcpy(this->m_str, cstr.CSHToChar());
}

/**
 * Operator '=' overload.
 */
void CStringHandler::operator=(const char *str)
{
  delete[] this->m_str;
  this->m_str = new char[strlen(str) + 1];

  strcpy(this->m_str, str);
}

/**
 * Operator '+' overload.
 */
void CStringHandler::operator+(const CStringHandler cstr)
{
  this->Append(cstr.CSHToChar());
}

/**
 * Operator '+' overload.
 */
void CStringHandler::operator+(const char *str)
{
  this->Append(str);
}
