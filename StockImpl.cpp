#include "StockModel.h"

StockModel::StockModel() {
	milkQuantity = 1000;
	cocoaQuantity = 500;
}

int StockModel::getMilkStock() { return this->milkQuantity; }

int StockModel::getCocoaStock() { return this->cocoaQuantity; }

void StockModel::addStock(int milkToAdd, int cocoaToAdd) {
	this->milkQuantity += milkToAdd;
	this->cocoaQuantity += cocoaToAdd;
}

void StockModel::emptyStock(int milkToAdd, int cocoaToAdd) {
	this->milkQuantity -= milkToAdd;
	this->cocoaQuantity -= cocoaToAdd;
}
