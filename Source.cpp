#include <windows.h>
#include <iostream>

#include "Util.h"

void main()
{
	SetConsoleTitle("Public Antivirus");

	while (true)
	{
		string FileName;
		cout << "Enter File Name: ";

		cin >> FileName;

		ReadFile(FileName);

		ReadHex(FileName);

		//WriteFile(HexText);

		for (auto i : TextDB)
		{
			if (ScanFileText(i))
			{
				cout << "Found: " << i << endl;
				Score = Score + 1;
			}
		}

		/* Scan Major Malicious Signatures */

		if (ScanFileText(Ta1))
		{
			cout << "Detection: Nanocore.Rat" << endl;
			Score = Score + 100;
		}

		if (ScanFileText(Ta2))
		{
			cout << "Detection: MachineName" << endl;
			Score = Score + 10;
		}

		if (ScanHexText(Ha1))
		{
			cout << "Detection: Padding" << endl;
			Score = Score + 5;
		}
		
		cout << "Malicious Score: " << Score << endl;

		/* End Scan Major Malicious Signatures*/

		system("pause");

		system("cls");
	}

	exit(1);
}
