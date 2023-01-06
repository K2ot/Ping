#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

#include <ctime>


int main()
{
	std::string ipAddress;
	std::string command;
	std::string ping;
	std::string pingResult;
	std::fstream plik;
	std::time_t rawtime =0 ;
	const std::time_t now = std::time(nullptr);

	ipAddress = "212.77.100.101";
	command = "ping " + ipAddress + " -n 1 > buforPing.txt";

	while (true)
	{

		system(command.c_str());

		plik.open("buforPing.txt", plik.in);
		if (!(plik.is_open()))
		{
			std::cout << "Plik nie owarty!" << std::endl;
		}

		while (!getline(plik, ping, ','))
		{
			plik >> ping;
		}
		plik.close();

		std::cout << ping << std::endl;

		//ping = "   timed out    ";
		if (ping.find("timed out")>0 && ping.find("timed out") <= ping.size())
		{
			std::cout << "find timed out" << std::endl;
			plik.open("pingLog.txt", plik.out | plik.app);
			if ((plik.is_open()))
			{
				time(&rawtime);
				plik << " Request timed out. " <<ctime(&rawtime) <<  std::endl;
				plik.close();
			}
		}
		Sleep(5000);
	}
	return 0;
}
