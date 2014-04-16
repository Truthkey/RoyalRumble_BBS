#include <windows.h>
#include <string.h>
#include <iostream>
using namespace std; 
 
// Returns an empty string if dialog is canceled
string openfilename(char *filter = "All Files (*.*)\0*.*\0", HWND owner = NULL)
{
  OPENFILENAME ofn;
  char fileName[MAX_PATH] = "";
  ZeroMemory(&ofn, sizeof(ofn));
 
  ofn.lStructSize = sizeof(OPENFILENAME);
  ofn.hwndOwner = owner;
  ofn.lpstrFilter = filter;
  ofn.lpstrFile = fileName;
  ofn.nMaxFile = MAX_PATH;
  ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
  ofn.lpstrDefExt = "";
 
  string fileNameStr;
 
  if ( GetOpenFileName(&ofn) )
    fileNameStr = fileName;
 
  return fileNameStr;
}