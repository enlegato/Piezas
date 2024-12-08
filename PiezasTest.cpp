/**
 * Unit Tests for Piezas
 **/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
protected:
	PiezasTest() {}			   // constructor runs before each test
	virtual ~PiezasTest() {}   // destructor cleans up after tests
	virtual void SetUp() {}	   // sets up before each test (after constructor)
	virtual void TearDown() {} // clean up after each test, (before destructor)
};

TEST(PiezasTest, x_wins) // DELETE THIS TEST AFTER CONFIRMING IT RUNS
{
	Piezas board = Piezas();
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);

	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(2);

	board.dropPiece(3);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);

	if (board.pieceAt(0, 0) != X)
	{
		ASSERT_TRUE(false);
	}

	if (board.gameState() != X)
	{
		ASSERT_TRUE(false);
	}

	ASSERT_TRUE(true);
}

TEST(PiezasTest, o_wins) // DELETE THIS TEST AFTER CONFIRMING IT RUNS
{
	Piezas board = Piezas();
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);

	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(3);

	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(2);

	if (board.pieceAt(0, 1) != O)
	{
		ASSERT_TRUE(false);
	}

	if (board.gameState() != O)
	{
		ASSERT_TRUE(false);
	}

	ASSERT_TRUE(true);
}

TEST(PiezasTest, basic_test) // DELETE THIS TEST AFTER CONFIRMING IT RUNS
{
	Piezas board = Piezas();
	for (int i = 0; i < 13; i++)
	{
		if (board.dropPiece(0) == Blank)
		{
			if (board.dropPiece(1) == Blank)
			{
				if (board.dropPiece(2) == Blank)
				{
					if (board.dropPiece(3) == Blank)
					{
						board.gameState();
					}
				}
			}
		}
	}
	board.pieceAt(0, 0);
	board.reset();
	ASSERT_TRUE(true);
}

TEST(PiezasTest, smoke_test) // DELETE THIS TEST AFTER CONFIRMING IT RUNS
{
	Piezas board;
	ASSERT_TRUE(true);
}
