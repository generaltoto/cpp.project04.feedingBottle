#include "StockModel.h"


float StockModel::getStock() { return this->quantity; }

void StockModel::addStock(float quantityToAdd) { this->quantity += quantityToAdd; }

void StockModel::emptyStock(float quantityToRemove) { this->quantity -= quantityToRemove; }

MilkStock::MilkStock(float quantity) { addStock(quantity); };

CocoaStock::CocoaStock(float quantity) { addStock(quantity); };
