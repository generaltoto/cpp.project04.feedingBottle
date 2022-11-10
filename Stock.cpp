#include "Stock.h"


Stock::Stock(float quantity) : quantity(quantity) {};

float Stock::getStock() { return this->quantity; }

void Stock::addStock(float quantityToAdd) { this->quantity += quantityToAdd; }

void Stock::emptyStock(float quantityToRemove) { this->quantity -= quantityToRemove; }