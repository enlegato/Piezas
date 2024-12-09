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

TEST(PiezasTest, x_wins)
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

TEST(PiezasTest, o_wins)
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

TEST(PiezasTest, basic_test)
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

TEST(PiezasTest, output_of_dropPiece)
{
	Piezas board = Piezas();
	if (board.dropPiece(0) != X)
	{
		ASSERT_TRUE(false);
	}
	if (board.dropPiece(0) != O)
	{
		ASSERT_TRUE(false);
	}
	if (board.dropPiece(1) != X)
	{
		ASSERT_TRUE(false);
	}
	if (board.dropPiece(0) != O)
	{
		ASSERT_TRUE(false);
	}

	if (board.dropPiece(2) != X)
	{
		ASSERT_TRUE(false);
	}
	if (board.dropPiece(1) != O)
	{
		ASSERT_TRUE(false);
	}
	if (board.dropPiece(3) != X)
	{
		ASSERT_TRUE(false);
	}
	if (board.dropPiece(2) != O)
	{
		ASSERT_TRUE(false);
	}

	if (board.dropPiece(3) != X)
	{
		ASSERT_TRUE(false);
	}
	if (board.dropPiece(1) != O)
	{
		ASSERT_TRUE(false);
	}
	if (board.dropPiece(2) != X)
	{
		ASSERT_TRUE(false);
	}
	if (board.dropPiece(3) != O)
	{
		ASSERT_TRUE(false);
	}

	if (board.dropPiece(5) != Invalid)
	{
		ASSERT_TRUE(false);
	}
	if (board.dropPiece(-2) != Invalid)
	{
		ASSERT_TRUE(false);
	}

	if (board.dropPiece(3) != Blank)
	{
		ASSERT_TRUE(false);
	}

	ASSERT_TRUE(true);
}

TEST(PiezasTest, output_of_pieceAt)
{
	Piezas board = Piezas();
	board.dropPiece(0);
	if (board.pieceAt(0, 0) != X)
	{
		ASSERT_TRUE(false);
	}
	board.dropPiece(0);
	if (board.pieceAt(1, 0) != O)
	{
		ASSERT_TRUE(false);
	}
	board.dropPiece(1);
	if (board.pieceAt(0, 1) != X)
	{
		ASSERT_TRUE(false);
	}
	board.dropPiece(0);
	if (board.pieceAt(2, 0) != O)
	{
		ASSERT_TRUE(false);
	}

	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(3);
	board.dropPiece(2);

	board.dropPiece(3);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);

	if (board.pieceAt(0, 3) != X)
	{
		ASSERT_TRUE(false);
	}

	if (board.pieceAt(-1, 0) != Invalid)
	{
		ASSERT_TRUE(false);
	}

	if (board.pieceAt(6, 0) != Invalid)
	{
		ASSERT_TRUE(false);
	}

	if (board.pieceAt(0, -1) != Invalid)
	{
		ASSERT_TRUE(false);
	}

	if (board.pieceAt(0, 6) != Invalid)
	{
		ASSERT_TRUE(false);
	}

	if (board.gameState() != X)
	{
		ASSERT_TRUE(false);
	}

	ASSERT_TRUE(true);
}

TEST(PiezasTest, output_of_gameState)
{
	Piezas board = Piezas();
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);

	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);

	board.dropPiece(3);
	board.dropPiece(1);
	board.dropPiece(3);
	if (board.gameState() != Invalid)
	{
		ASSERT_TRUE(false);
	}
	board.dropPiece(2);

	if (board.gameState() != Blank)
	{
		ASSERT_TRUE(false);
	}

	ASSERT_TRUE(true);
}

TEST(PiezasTest, test_reset)
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

	if (board.gameState() != X)
	{
		ASSERT_TRUE(false);
	}
	board.reset();
	if (board.gameState() != Invalid)
	{
		ASSERT_TRUE(false);
	}
	if (board.pieceAt(0, 0) != Blank)
	{
		ASSERT_TRUE(false);
	}

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

	if (board.gameState() != X)
	{
		ASSERT_TRUE(false);
	}

	ASSERT_TRUE(true);
}