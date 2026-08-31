#pragma once
class VendingManchine
{
private:
	int money;		//Ç®ã‡Åié©îÃã@Åj
	int colaStock;	//ç›å…
public:
	VendingManchine();
	void insertMoney(int amount);
	void buyCola();
	int getMoney() const;
	int getColaStock() const;
};

