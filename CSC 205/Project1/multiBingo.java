import java.util.*;
public class multiBingo 
{
public static void main(String [] args)
{

Scanner scn= new Scanner(System.in);

System.out.println("Welcome to Multiplayer Bingo! \nHow many players would you like to play the game?");

int numPlayers=scn.nextInt();

bingoPlayer [] ans= new bingoPlayer[numPlayers];
System.out.println("Please enter your player names: ");
int n=0;
int i=0;
String [] playerNames=new String [numPlayers];

//while(n<numPlayers)
//{
	System.out.println("Player "+(i+1)+":");
	//playerNames[i]= scn.next();
	
	//String name= (String)scn.next();

	//ans[i]=new bingoPlayer("bingoPlayer");
	System.out.println();
	//`ans[i].printStats();
	System.out.println();	
	i++;
	n++;
	System.out.println(n);
//}


bingoPlayer b1= new bingoPlayer("test");
b1.printStats();
bingoPlayer b2= new bingoPlayer("test2");

//b1.printStats();
b2.printStats();

}



}
