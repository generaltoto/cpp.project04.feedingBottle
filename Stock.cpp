#include "Stock.h"


float Stock::getStock() { return this->quantity; }

void Stock::addStock(float quantityToAdd) { this->quantity += quantityToAdd; }

void Stock::emptyStock(float quantityToRemove) { this->quantity -= quantityToRemove; }

MilkStock::MilkStock(float quantity) { addStock(quantity); };

CocoaStock::CocoaStock(float quantity) { addStock(quantity); };
