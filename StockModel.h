#pragma once

class StockModel
{
protected:
	float milkQuantity;
	float cocoaQuantity;

public:

	StockModel();

	/// Returns the milk stock value
	float getMilkStock();

	/// Returns the cocoa stock value
	float getCocoaStock();

	/// Adds some quantity to the stock 
	/// \param milkToAdd : quantity of milk to add to the stock (in mL)
	/// \param cocoaToAdd : quantity of cocoa to add to the stock (in mg)
	void addStock(float milkToAdd, float cocoaToAdd);

	/// Removes some materials from the stock 
	/// \param milkToRemove : quantity of milk to remove from the stock (in mL)
	/// \param cocoaToRemove : quantity of cocoa to remove from the stock (in mg)
	void emptyStock(float milkToRemove, float cocoaToRemove);
};
