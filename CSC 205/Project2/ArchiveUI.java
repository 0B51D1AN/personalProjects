import java.util.*;
import java.io.*;
public class ArchiveUI
{

public static LibraryBook[] newLibrary;
public static String input="";
public static ArrayList<String> data= new ArrayList<String>();
public static ArrayList<LibraryBook> Library= new ArrayList<LibraryBook>();
public static int index=0;




public static void main (String[] args) throws FileNotFoundException
{
File curDir = new File(".");
  String[] fileNames = curDir.list();

    for(String s:fileNames)
     if(s.endsWith(".dat"))
      data.add(s);


clearScreen();
first();

formatter(input);
clearScreen();

sort();
Menu();
}



///////////////////////////////////
//Clears Screen (Implement in other methods)
public static void clearScreen()
{
   System.out.println("\u001b[H\u001b[2J");

}


////////////////////////////////////
// Reads the file entered by user and sorts it based on the title of the books 
public static void formatter(String file) throws FileNotFoundException 
{

Scanner scanner= new Scanner(new File(file));
scanner.useDelimiter(";");


while(scanner.hasNext())
{
Library.add(new LibraryBook(scanner.next(),scanner.next(),scanner.nextInt(),scanner.nextDouble(),scanner.next()));
scanner.nextLine();
}

}




public static void sort()
{

LibraryBook t= new LibraryBook("","",0,0.0,"");
int size= Library.size();
newLibrary= new LibraryBook[Library.size()];

for(int i=0; i<Library.size();i++)
{
newLibrary[i]=Library.get(i);
}



for(int i=0; i<newLibrary.length; i++)
{
  for(int g=0; g<newLibrary.length;g++)
  {
	int a = newLibrary[g].compareTo(newLibrary[i]);
	//System.out.println(a);
	if(a>0)
	{
	t=newLibrary[i];
	newLibrary[i]=newLibrary[g];
	newLibrary[g]=t;
	}

  }



}




}









///////////////////////////////////
//Formatter that finds all .dat files and prompts the user for which they would like to use


public static void first() throws FileNotFoundException 
{
Scanner scn1=new Scanner (System.in);
try{

System.out.println("Here is the list of files on hand"+"\n" +"Which file would you like to search?");

for(int i=0; i<data.size(); i++)
	System.out.print(data.get(i)+"	");

System.out.println();
String file= scn1.next();


if(data.contains(file))
{
input= file;
}
else
{
clearScreen();
System.out.println("Unable to find the file requested, please try again...");
first();
}

}catch (Exception e){
}

	
}











// UI to guide the user
// 	1. Print all books in format
//      2. Search for a book by title
// 	3. Exit the Program



///////////////////////////////////////////////////
// Uses for loop to print all books in the inputed file, continuing at the user's discression

public static void printBooks()
{
Scanner scn= new Scanner(System.in);

System.out.print("Book #"+(index+1)+"\n"+newLibrary[index].toString()+"\nPlease hit 1 to continue... Hit 2 to return to menu");
String ans=scn.next();
if(newLibrary.length==1&& ans.equals("1"))
{
clearScreen();
printBooks();
}
if(index==newLibrary.length-1)
index=-1;
if(ans.toLowerCase().equals("1"))
{
clearScreen();
index++;
printBooks();
}
if(ans.equals("2"))
{
clearScreen();
Menu();
}
else
{
clearScreen();
System.out.println("Invalid Entry. Please Enter a valid Command:");
printBooks();

}
}















////////////////////////////////////////////
//Asks user for title then searches index for said book

public static void searchBook()
{
Scanner scner= new Scanner(System.in);

System.out.println("Please enter the Title of the Book:\n Press 1 to return to Menu: \n");

String ans= scner.nextLine();
//scner.close();
System.out.println(ans);
if(ans.equals("1"))
{
clearScreen();
Menu();
}
else
{
for(int i=0; i<newLibrary.length; i++)
{
if(newLibrary[i].getTitle().toLowerCase().equals(ans.toLowerCase()))
{
clearScreen();
System.out.println("Book #"+(i+1)+"\n"+newLibrary[i].toString()+"\n");
searchBook();
}
}

clearScreen();
System.out.println("That book is not in this file...");
searchBook();

}
}




///////////////////////////////////////////
// Guides the user to each option/method
//
//
//
public static void Menu() 
{
//try{
Scanner scn2= new Scanner(System.in);


System.out.println("			The Archive"+"\n"+"\n"+"Welcome! "+"\n"+"There are a total of: "+ newLibrary.length+" Books in this file...\nPlease enter a number for the respective action you would like to take:");

System.out.println("1. Display all books on record"+"\n"+"2. Search for a book by Title"+ "\n"+ "3. Exit Program");

String answer=scn2.nextLine();

if(answer.equals("1"))
{
clearScreen();
printBooks();
}
if(answer.equals("2"))
{
clearScreen();
searchBook();
}
if(answer.equals("3"))
{
	clearScreen();
	System.out.println("Goodbye");
	System.exit(0);
	//end=true;
	//break;
}
else
{
	clearScreen();
	System.out.println("You have inputed an invalid command, please try again:");
	Menu();
}
//}catch (Exception ex){
//System.out.println("um");
//}
}
	




}
