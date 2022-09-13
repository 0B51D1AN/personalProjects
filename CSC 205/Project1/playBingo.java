import java.util.*;
public class playBingo extends bingoCard
{

public static void main(String [] args)
{

////////////////////////////////////////////////////////
//
//INITIATE PLAYER


Scanner scn= new Scanner(System.in);

System.out.println("Hello, what would you like your username to be?");

String s=scn.next();

bingoPlayer p1= new bingoPlayer(s);


System.out.println("Good, now lets play the game..."+"\n"+"here is your Bingo Card: "+"\n");
System.out.println();
p1.printStats();
/////////////////////////////////////////////////////////

//PLAY GAME

while(checkWin()<=0)
{
p1.playGame();
p1.checkWin();
}
System.out.println();
p1.printStats();
//////////////////////////////////////////////////////////
//
//DECLARE WINNER + POST GAME STATS

System.out.println();
p1.declareWinner();

for(int i=0; i<caller.size(); i++)
	System.out.print(" "+caller.get(i));

System.out.println("\nIt took: "+caller.size()+" times to get a bingo");




}



///////////////////////////////////////////////////////////////////
//
//    OBJECTIVES:
//
//
//    1. Initiate Players
//    2.Play Game
//    3.Check Win
//    	-Say who won with how many draws
//    	-Show draws
//

}
