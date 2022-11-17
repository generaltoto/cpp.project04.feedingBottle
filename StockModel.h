#pragma once

/// Manages the stock of the products in a feeding bottle.
class StockModel
{
protected:
	int milkQuantity;
	int cocoaQuantity;

public:

	/// Constructor.
	StockModel();

	/// Returns the milk stock value
	int getMilkStock();

	/// Returns the cocoa stock value
	int getCocoaStock();

	/// Adds some quantity to the stock 
	/// \param milkToAdd : quantity of milk to add to the stock (in mL)
	/// \param cocoaToAdd : quantity of cocoa to add to the stock (in mg)
	void addStock(int milkToAdd, int cocoaToAdd);

	/// Removes some materials from the stock 
	/// \param milkToRemove : quantity of milk to remove from the stock (in mL)
	/// \param cocoaToRemove : quantity of cocoa to remove from the stock (in mg)
	void emptyStock(int milkToRemove, int cocoaToRemove);
};
