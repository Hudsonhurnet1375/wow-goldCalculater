// wowProfit.cpp
// calculate World of Warcraft profith with and without bot
#include <iostream>
#include <iomanip>
#include "NormalProfit.h"
using namespace std;

int main() {

	cout << fixed << setprecision(2);	
	unsigned int condition{1};
	int token{0};
	int gameTime{0};
	int gold{0};
	int vpn{0};

	system("cls");
	cout << "\n\n ======================================================================\n\n"
		<< " *|---- Welcome to WOW profit calculate ----|*"
		<<"\n\n Please Enter \n\n";
	cout << " Token: " ;
	cin >> token;
	cout << " Game Time: ";	
	cin >> gameTime;
	cout << " Gold: ";
	cin >> gold;
	cout << " VPN :";	
	cin >> vpn;
	system("cls");
	

	// initial Object of BotClass and NormalProfit
	NormalProfit normal(token, gameTime, gold, vpn);


	do {
		// display fandemental info
		cout << "\n TOKEN is:" 		<< setw(9) << "|\t" << token << ".G"
			<< "\n GAME TIME is:" 	<< setw(5) << "|\t" << gameTime << ".T" 
			<< "\n Gold:" 			<< setw(13) << "|\t" << gold << ".T"
			<< "\n VPN is:"			<< setw(11) << "|\t" << vpn << ".T" << endl;

		cout << "\n==============================================\n"
			<< "\n Etner  option: \n"
			<< "\n 1. Bot \t 2. Normal \t 3. Start \t 4. Exit \n | " ;

		// get Option from user
		unsigned int userInput{0};
		cin >> userInput;

		switch (userInput) {
			// bot profit
			case 1:
				system("cls");
				normal.setBotInfo();
				normal.setBotGold();
				normal.setBotToken();
				break; // exits switch

			// noraml profit
			case 2:
				system("cls");
				normal.setInfo();
				normal.setGold();
				normal.setToken();
				break; // exits switch

			
			case 3:
				system("cls");
				cout << "\n\n ======================================================================\n\n"
					<< " *|---- Welcome to WOW profit calculate ----|*"
					<<"\n\n Please Enter \n\n";

				cout << " Token: " ;
				cin >> token;
				cout << " Game Time: ";	
				cin >> gameTime;
				cout << " Gold: ";
				cin >> gold;
				cout << " VPN :";	
				cin >> vpn;
				system("cls");
				break;
			// exit	
			case 4:		
				condition = 0;
				system("cls");
				break; // exits switch

			default:
				cout << " ====== WARNING : ENTER VALID OPTION (1.2.3) ======\n";
		}// end switch
		
			
		
	}while (condition != 0);
}