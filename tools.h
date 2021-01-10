#pragma once
#include "windows.h"
#include <wchar.h>

#include  <io.h>
#include <direct.h>

class point
{
public:
	point(int a, int b)
	{
		x = a;
		y = b;
	}
	int x = 0;
	int y = 0;
};


class config
{
public:

	BOOL isFolderExist(char* folder)
	{
		int ret = 0;

		ret = _access(folder, 0);
		if (ret == 0)
			ret = TRUE;
		else
			ret = FALSE;

		return ret;
	}


	int32_t createDirectory(char* directoryPath)
	{
		uint32_t dirPathLen = 0;
		if (directoryPath != NULL) {
			dirPathLen = strlen(directoryPath);
		}
		if (dirPathLen > FILENAME_MAX)
		{
			return -1;
		}
		char tmpDirPath[FILENAME_MAX] = { 0 };
		for (uint32_t i = 0; i < dirPathLen; ++i)
		{
			tmpDirPath[i] = directoryPath[i];
			if (tmpDirPath[i] == '\\' || tmpDirPath[i] == '/')
			{
				if (!isFolderExist(tmpDirPath))
				{
					int ret = _mkdir(tmpDirPath);
					//BOOL ret = CreateDirectory(tmpDirPath, NULL);
					if (ret != 0)
						return -1;
				}
			}
		}
		return 0;

	}



	const LPWSTR getPath()
	{
		
		char ePath[256] = "%ProgramFiles%\\ÎüÑª¹íÎï×Ê\\111.ini\0";
		char dPath[256] = { 0 };
		LPWSTR lPath = (LPWSTR)malloc(sizeof(WCHAR) * 256);
		ExpandEnvironmentStringsA(ePath, dPath, 256);
		if (!isFolderExist(dPath))
			createDirectory(dPath);
		MultiByteToWideChar(CP_ACP, 0, dPath, 256, lPath, sizeof(WCHAR) * 256);
		//MessageBox(NULL, lPath, L"Â·¾¶", MB_OK);
		return lPath;
		
	}


	bool wIni()
	{
		if (!WritePrivateProfileString(
			L"map", L"mapLong", L"16",getPath())
			)
			//MessageBox(NULL, getPath(),L"Éú³ÉÅäÖÃÊ§°Ü", MB_OK);
		return 1;
	}
};
