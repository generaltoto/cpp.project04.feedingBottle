#pragma once

class StockModel
{
protected:
	float milkQuantity;
	float cocoaQuantity;

public:

	StockModel();

	/** Returns the milk stock value */
	float getMilkStock();

	/** Returns the cocoa stock value */
	float getCocoaStock();

	/** Adds some quantity to the stock */
	void addStock(float milkToAdd, float cocoaToAdd);

	/** Remove some quanty of the stock */
	void emptyStock(float milkToAdd, float cocoaToAdd);
};
