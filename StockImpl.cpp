#include "StockModel.h"

StockModel::StockModel()
{
	milkQuantity = 1000;
	cocoaQuantity = 500;
}

float StockModel::getMilkStock() { return this->milkQuantity; }

float StockModel::getCocoaStock() { return this->cocoaQuantity; }

void StockModel::addStock(float milkToAdd, float cocoaToAdd)
{
	this->milkQuantity += milkToAdd;
	this->cocoaQuantity += cocoaToAdd;
}

void StockModel::emptyStock(float milkToAdd, float cocoaToAdd)
{
	this->milkQuantity -= milkToAdd;
	this->cocoaQuantity -= cocoaToAdd;
}
