public class bingoPlayer extends bingoCard
{
private boolean winner=false;
private String name;
private bingoCard card;

//////////////////////////////////////////////////

public bingoPlayer(String pName)
{

name= pName;
card= new bingoCard();

}


//////////////////////////////////////////////////

public void printStats()
{
System.out.println("Player Name:     " +name+ "\n"+"\n"+ "     B    I    N    G    O ");
card.printCard();

}

////////////////////////////////////////////////


public String getName()
{
return name;
}

///////////////////////////////////////////////

public void declareWinner()
{

if(this.checkWin()==3)
	System.out.println("\n You just got a Diagonal Bingo!!"+"\n");
if(this.checkWin()==1)
	System.out.println("\n You just got a Horizontal Bingo!!"+"\n");
if(this.checkWin()==2)
	System.out.println("\n You just got a Vertical Bingo!!"+"\n");


}



}
