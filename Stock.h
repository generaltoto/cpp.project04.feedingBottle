#pragma once

class Stock
{
protected:
	float quantity;

public:

	/** Returns the stock value */
	float getStock();

	/** Adds some quantity to the stock */
	void addStock(float quantityToAdd);

	/** Remove some quanty of the stock */
	void emptyStock(float quantityToRemove);
};

class MilkStock : public Stock { MilkStock(float quantity); };

class CocoaStock : public Stock { CocoaStock(float quantity); };
