	// NormalProfit.h
// Calculate Normal Profit without using bot 

#include <iostream>

class NormalProfit {
public:
	// constructor
	NormalProfit(int a, int b, int c, int d) : token{a}, gameTime{b}, gold{c}, vpn{d} {}

	void setInfo(){

		std::cout << "\n\n ************** NORMAL PROFIT ************** \n\n";

		std::cout << " Game Play (HOUR): ";
		std::cin >> gamePlay;

		std::cout << " Gold per Hour: ";
		std::cin >> goldHour;

		std::cout << " Accounts: ";
		std::cin >> accounts;
	}


	void setBotInfo(){

		std::cout << "\n\n ************** BOT PROFIT ************** \n\n";

		std::cout << " Game Play (HOUR): ";
		std::cin >> gamePlay;						//gamePlay

		std::cout << " Gold per Hour: ";
		std::cin >> goldHour;						//goldHOur

		std::cout << " Accounts: ";
		std::cin >> accounts;						//accounts

		std::cout << " Banneto Price (EU): ";
		std::cin >> banneto;						//banneto

		std::cout << " Unlocker Price ($): ";
		std::cin >> unlocker;						//unlocker

		std::cout << " Euro: " ;
		std::cin >> euro;							//euro

		std::cout << " Dollar: ";
		std::cin >> dollar;							//dollar
	}		


	void setBotGold(){
		std::cout << "\n ***************** GOLD ***************** \n";

		//gold per day
		goldPerDay = (gamePlay * goldHour * accounts) / 100 * 95;
		std::cout << "\n Gold per day: " << goldPerDay;

		//gold per month
		goldPerMonth = (goldPerDay * 26) - (token * accounts);
		std::cout << "\n GOld per month: " << goldPerMonth;

		//gold sell price
		goldSellPrice = (static_cast<double>(goldPerMonth) / 1000 * static_cast<double>(gold)) - static_cast<double>(vpn);
		std::cout << "\n Gold sell price: " << goldSellPrice << " T" << std::endl;

		//gold price with bot
		botPrice = (banneto * euro) + (unlocker * dollar); // bot price to TOMAN
		std::cout << "\n\n BOT Price : " << botPrice << "\n Gold sell price with bot: " << goldSellPrice - botPrice << " T (GOLD)\n";

	}


	void setBotToken(){
		std::cout << "\n ***************** TOKEN *****************\n";


		//token per month
		double tokenPerMonth;
		tokenPerMonth = static_cast<double>(goldPerMonth) / static_cast<double>(token);
		std::cout << "\n Token per month: " << tokenPerMonth
			<< " == [" << goldPerMonth / token << "]";

		//game time per month
		double gameTimePerMonth;
		gameTimePerMonth = tokenPerMonth / 2;
		std::cout << "\n Game Time x60 per month : " << gameTimePerMonth
			<< " == [" << static_cast<int>(tokenPerMonth) / 2 << "]";

		// game time sell price
		int gameTimeSellPrice;
		gameTimeSellPrice = static_cast<int>(gameTimePerMonth) * gameTime - (botPrice + vpn);
		std::cout << "\n Game Time x60 sell price : " << gameTimeSellPrice << " T (GAME TIME x60)"
			<< " == [" << (gameTimePerMonth * gameTime - (botPrice + vpn)) << "]"
			<< "\n\n ****************************************\n\n";

		(goldSellPrice - botPrice) > gameTimeSellPrice ? std::cout << " The best Option is : ( GOLD )" << (goldSellPrice - botPrice) << " T\n" : std::cout << " The bets obtion is (GAME TIME x60): " << gameTimeSellPrice << " T\n";
		std::cout << "\n\n ****************************************\n\n";

	}

	//------------------------------------------------------------------------

	void setGold(){
		std::cout << "\n ***************** GOLD ***************** \n";

		//gold per day
		goldPerDay = (gamePlay * goldHour * accounts) / 100 * 95;
		std::cout << "\n Gold per day: " << goldPerDay;

		//gold per month
		goldPerMonth = (goldPerDay * 26) - (token * accounts);
		std::cout << "\n GOld per month: " << goldPerMonth;

		//gold sell price
		goldSellPrice = (static_cast<double>(goldPerMonth) / 1000 * static_cast<double>(gold)) - static_cast<double>(vpn);
		std::cout << "\n Gold sell Price: " << goldSellPrice << " T (GOLD)";
	}
	
	void setToken(){
		std::cout << "\n ***************** TOKEN *****************";

		//token per month
		double tokenPerMonth;
		tokenPerMonth = static_cast<double>(goldPerMonth) / static_cast<double>(token);
		std::cout << "\n Token per month: " << tokenPerMonth
			<< " == [" << goldPerMonth / token << "]";

		//game time per month
		double gameTimePerMonth;
		gameTimePerMonth = tokenPerMonth / 2;
		std::cout << "\n Game Time x60 per month : " << gameTimePerMonth
			<< " == [" << static_cast<int>(tokenPerMonth) / 2 << "]";

		// game time sell price
		int gameTimeSellPrice;
		gameTimeSellPrice = static_cast<int>(gameTimePerMonth) * gameTime - vpn;
		std::cout << "\n Game Time x60 sell price : " << gameTimeSellPrice << " T (Game TME x60)"
		<< " == [" << (gameTimePerMonth * gameTime - vpn) << "]"
			<< "\n\n ****************************************\n\n";

		goldSellPrice > gameTimeSellPrice ? std::cout << " The best  is (GOLD): " << goldSellPrice << " T\n" : std::cout << " The bets  is (GAME TIME x60): " << gameTimeSellPrice << " T\n";
		std::cout << "\n\n ****************************************\n\n";
	}

private:
	int token{0};
	int gameTime{0};
	int gold{0};
	int vpn{0};

	int gamePlay;
	int goldHour;
	int accounts;

	int goldPerMonth;
	int goldPerDay;
	double goldSellPrice;

	int banneto;
	int unlocker;
	int euro;
	int dollar;

	int botPrice;

}; // end calss