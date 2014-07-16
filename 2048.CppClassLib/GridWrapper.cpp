#include "stdafx.h"
#include "GridWrapper.h"

using namespace Cpp2048ClassLib;

GridWrapper::GridWrapper(void)
{
	mGrid = new TILE[SIZE*SIZE];
}

GridWrapper::~GridWrapper()
{
	delete [] mGrid;
}

TILE GridWrapper::GetTileForPosition(const tilePtr c, const tilePtr r)
{
	return mGrid[SIZE*r + c];
}

void GridWrapper::SetTileForPosition(const TILE value, const tilePtr c, const tilePtr r)
{
	mGrid[SIZE*r + c] = value;
}

void GridWrapper::CopyFrom(GridWrapper other)
{
	for (tilePtr c=0; c<SIZE; ++c)
	{
		for (tilePtr r=0; r<SIZE; ++r)
		{
			TILE tile = other.GetTileForPosition(c, r);
			this->SetTileForPosition(tile, c, r);
		}
	}
}