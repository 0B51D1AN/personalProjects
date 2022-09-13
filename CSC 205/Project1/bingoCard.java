import java.util.*;
public class bingoCard
{
protected static int[][] bingCard;
public static ArrayList <Integer> called= new ArrayList<Integer>(25);
public static ArrayList <Integer> caller= new ArrayList<Integer>(75);
//public static int draws=caller.size();



/////////////////////////////////////////////

// Random Number Generator

public int ranNum(int min, int max)
{

return (int)(Math.random()*(max-min))+min;

}


//////////////////////////////////////////////

// Fills 2d Array by first picking 25 random numbers in increasing order depending on the column, then fills the array with the given numbers.

private void fillCard()
{
int col=4;
int min=1;
int max=15;

for(int i=0; i<25;i++)
{
int newNum=ranNum(min,max);

//Begins generating random numbers, checking to see if the number has already been used

while (called.contains(newNum)==true)
{

	newNum=ranNum(min,max);
	//f=0;
}

called.add(newNum);
//System.out.println(called.get(a));

//Increases the value of the random numbers given their column

	if(i==col)
	{
	col+=5;
	min=max+1;
	max+=15;
	}


}

called.trimToSize();
//System.out.println(called.size());
//Fills the array with the random numbers

int y=0;

for(int r=0; r<bingCard.length; r++)
{
	for(int c=0; c<bingCard[r].length;c++)
	{
	bingCard[r][c]=called.get(y);
	y++;
	//System.out.print(""+bingCard[r][c]+" ");
	}
	//System.out.println();

}

}

///////////////////////////////////////////////////////////////

// Constructor Class

public bingoCard()
{
bingCard=new int [5][5];
this.fillCard();
}


////////////////////////////////////////////////////////////////

//Prints Bingo Card

void printCard()
{

//System.err.println("Wut");
for(int r=0; r<bingCard.length; r++)
{
	System.out.println();
	for(int c=0; c<bingCard[r].length;c++)
	{
		if(bingCard[r][c]==0)
		System.out.print("| X  |");	
		else if(bingCard[r][c]<=9)
		System.out.print("| "+bingCard[r][c]+"  |");
		else
		System.out.print("| "+bingCard[r][c]+" |");
	}

}	


//System.out.println("Yes");


}

////////////////////////////////////////////////////////////

//Checks to see if any of the rows/columns/or diagonals have all been marked with "X"'s and returns true if they do.

public static int checkWin()
{
boolean win=false;
//String x="X";
int ans=0;

for(int r=0; r<bingCard.length; r++)
{
ans=0;
	for(int c=0; c<bingCard[r].length; c++)
	{
	if(bingCard[r][c]==0)			
		ans++;
	
	if(ans==5)
	   return 1;
	}

}




////////////////////////////////////////////////////////////


//public boolean colWin()

ans=0;
for(int r=0; r<bingCard.length; r++)
{
ans=0;
	for(int c=0; c<bingCard[r].length; c++)
	{
	if(bingCard[c][r]==0)
		ans++;

	if(ans==5)
	  return 2;
	}

}


////////////////////////////////////////////////////////////

//public boolean diagWin()

int lAns=0;
int rAns=0;

for(int r=0; r<bingCard.length; r++)
{
	for(int c=0; c<bingCard[r].length; c++)
	{
	if(r==c)
	{
	  if(bingCard[r][c]==0)
		lAns++;

	  if(lAns==5)
	    return 3;
	}
	
	}

}


for(int i=0; i<bingCard.length; i++)
{
	if(bingCard[i][bingCard.length-i-1]==0)
	rAns++;

	if(rAns==5)
	 return 3;

}
return 0;
}
	




////////////////////////////////////////////////////////////

//Enters a random number that has not been called yet and checks to see if the number is on the bingo card

public void playGame()
{
int rNum=ranNum(1,75);
	
	while(caller.contains(rNum)==true)
	{
		rNum=ranNum(1,75);
	}

	caller.add(rNum);
	

	for(int r=0; r<bingCard.length;r++)
	{
		for(int c=0; c<bingCard[r].length; c++)
		{
			if(rNum==bingCard[r][c])
			   bingCard[r][c]=0;
		}
	}





}



}
