/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
#include <iostream>
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/



TEST(TicTacToeBoardTest, ToggleO)
{
	TicTacToeBoard B;
	ASSERT_TRUE(O == B.toggleTurn());
}

TEST(TicTacToeBoardTest, ToggleO_Fail)
{
	TicTacToeBoard B;
	ASSERT_FALSE(X == B.toggleTurn());
}

TEST(TicTacToeBoardTest, ToggleX)
{
	TicTacToeBoard B;
	B.toggleTurn(); 
	ASSERT_TRUE(X == B.toggleTurn());
}

TEST(TicTacToeBoardTest, ToggleX_Fail)
{
	TicTacToeBoard B;
	B.toggleTurn();
	ASSERT_FALSE(O == B.toggleTurn());
}

TEST(TicTacToeBoardTest, outofbound_row)
{
	TicTacToeBoard B;
	ASSERT_EQ(B.placePiece(3, 1), Invalid);
}

TEST(TicTacToeBoardTest, outofbound_col)
{
	TicTacToeBoard B;
	ASSERT_EQ(B.placePiece(1, 3), Invalid);
}

TEST(TicTacToeBoardTest, placepiece_X)
{
	TicTacToeBoard B;
	ASSERT_EQ(B.placePiece(0, 0), X);
}

TEST(TicTacToeBoardTest, placepiece_O)
{
	TicTacToeBoard B;
	B.toggleTurn();
	ASSERT_EQ(B.placePiece(0, 0), O);
}

TEST(TicTacToeBoardTest, winner_row_x)
{
	TicTacToeBoard B;
	B.placePiece(0,0);
	B.placePiece(0,1);
	B.placePiece(1,0);
	B.placePiece(2,2);
	B.placePiece(2,0);
	ASSERT_EQ(B.getWinner(), X);
}

TEST(TicTacToeBoardTest, winner_row_O)
{
	TicTacToeBoard B;
	B.toggleTurn();
	B.placePiece(0,0);
	B.placePiece(0,1);
	B.placePiece(1,0);
	B.placePiece(2,2);
	B.placePiece(2,0);
	ASSERT_EQ(B.getWinner(), O);
}


TEST(TicTacToeBoardTest, winner_col_x)
{
	TicTacToeBoard B;
	B.placePiece(0,0);
	B.placePiece(1,0);
	B.placePiece(0,1);
	B.placePiece(2,2);
	B.placePiece(0,2);
	ASSERT_EQ(B.getWinner(), X);
}

TEST(TicTacToeBoardTest, winner_col_O)
{
	TicTacToeBoard B;
	B.toggleTurn();
	B.placePiece(0,0);
	B.placePiece(1,0);
	B.placePiece(0,1);
	B.placePiece(2,2);
	B.placePiece(0,2);
	ASSERT_EQ(B.getWinner(), O);
}

TEST(TicTacToeBoardTest, boardFull)
{
	TicTacToeBoard B;
	B.toggleTurn();
	B.placePiece(0,0);
	B.placePiece(1,0);
	B.placePiece(2,0);
	B.placePiece(2,2);
	B.placePiece(1,2);
	B.placePiece(0,2);
	B.placePiece(0,1);
	B.placePiece(1,1);
	B.placePiece(2,1);
	ASSERT_EQ(B.getWinner(), Blank);
}



