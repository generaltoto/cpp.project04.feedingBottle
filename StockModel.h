#pragma once

class StockModel
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

class MilkStock : public StockModel { MilkStock(float quantity); };

class CocoaStock : public StockModel { CocoaStock(float quantity); };
