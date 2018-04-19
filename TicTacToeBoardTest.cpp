/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, toggleXTurn)
{
        TicTacToeBoard t;
	ASSERT_TRUE(t.toggleTurn() == 'O');
}

TEST(TicTacToeBoardTest, toggleOTurn)
{
        TicTacToeBoard t;
        t.toggleTurn();
	ASSERT_TRUE(t.toggleTurn() == 'X');
}

TEST(TicTacToeBoardTest, columnOOB)
{
        TicTacToeBoard t;
	ASSERT_TRUE(t.placePiece(2, 3) == '?');
}

TEST(TicTacToeBoardTest, rowOOB)
{
        TicTacToeBoard t;
	ASSERT_TRUE(t.placePiece(3, 2) == '?');
}

TEST(TicTacToeBoardTest, placeXPiece)
{
        TicTacToeBoard t;
	ASSERT_TRUE(t.placePiece(0, 2) == 'X');
}

TEST(TicTacToeBoardTest, placeOPiece)
{
        TicTacToeBoard t;
         t.toggleTurn();
	ASSERT_TRUE(t.placePiece(0, 2) == 'O');
}

TEST(TicTacToeBoardTest, alreadyInPlace)
{
        TicTacToeBoard t;
        t.placePiece(0,2);
	ASSERT_TRUE(t.placePiece(0, 2) == 'X');
}

TEST(TicTacToeBoardTest, alreadyInPlaceFalse)
{
        TicTacToeBoard t;
        t.placePiece(0,2);
	ASSERT_FALSE(t.placePiece(0, 2) == 'O');
}

TEST(TicTacToeBoardTest, getBlank)
{
        TicTacToeBoard t;
	ASSERT_TRUE(t.getPiece(0, 0) == Blank);
}

TEST(TicTacToeBoardTest, getXPiece)
{
        TicTacToeBoard t;
        t.placePiece(1,2);
	ASSERT_TRUE(t.getPiece(1, 2) == X);
}

TEST(TicTacToeBoardTest, getPieceOOB)
{
        TicTacToeBoard t;
	ASSERT_TRUE(t.getPiece(4, 2) == Invalid);
}


TEST(TicTacToeBoardTest, getOPieceF)
{
        TicTacToeBoard t;
        t.placePiece(2,2);
	ASSERT_FALSE(t.getPiece(2, 2) == O);
}

TEST(TicTacToeBoardTest, getWinOnStart)
{
        TicTacToeBoard t;
	ASSERT_TRUE(t.getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, xWinDiagonally)
{
        TicTacToeBoard t;
        for(int i=0; i<3; i++)
        {   
          for(int j=0; j< 3; j++)
            t.placePiece(i, j);
        }
	ASSERT_TRUE(t.getWinner() == X);
}

TEST(TicTacToeBoardTest, fullBoard)
{
        TicTacToeBoard t;
        for(int i=0; i<2; i++)
        {   
          for(int j=0; j< 3; j++)
          {
            t.placePiece(i, j);
          }
        }
        t.toggleTurn();
        for(int i=0;i<3;i++)
        {
         t.placePiece(2, i); 
        }
	ASSERT_TRUE(t.getWinner() == Blank);
}

TEST(TicTacToeBoardTest, xWinAcross)
{
        TicTacToeBoard t;
        t.placePiece(0,0);
        t.placePiece(1,1);
        t.placePiece(0,1);
        t.placePiece(1,2);
        t.placePiece(0,2);
	ASSERT_TRUE(t.getWinner() == X);
}

TEST(TicTacToeBoardTest, oWinDown)
{
        TicTacToeBoard t;
        t.placePiece(0,0);
        t.placePiece(2,1);
        t.placePiece(2,2);
        t.placePiece(1,1);
        t.placePiece(1,2);
        t.placePiece(0,1);
	ASSERT_TRUE(t.getWinner() == O);
}
