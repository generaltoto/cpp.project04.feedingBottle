#pragma once

class Stock
{
protected:
	float quantity = 1000.0;

public:

	Stock(float quantity);

	/** Returns the stock value */
	float getStock();

	/** Adds some quantity to the stock */
	void addStock(float quantityToAdd);

	/** Remove some quanty of the stock */
	void emptyStock(float quantityToRemove);
};

class MilkStock : public Stock {};

class CocoaStock : public Stock {};
