import java.util.*;
import java.io.IOException;

public class EmployeeTest
{

public  static ArrayList <Employee> file= new ArrayList<Employee>();


public static void main (String [] args)
{




clearScreen();
start();




}

public static void clearScreen()
{
System.out.println("\u001b[H\u001b[2J");
}






////////////////////////////////////////
//Guides the User through creating a new Employee and inserts it into the file ArrayList

public static void newEmployee()
{
Scanner scan= new Scanner(System.in);

double amt=0.0;

System.out.println("Please enter the name of your new Employee: ");

String name= scan.nextLine();


while(2>1)
{
try{
System.out.println("Hourly (h) or Salaried (s)?");

String e= scan.next().toLowerCase();

if(e.equals("h"))
{
  System.out.println("Please enter Employee's hourly wage: ");
  
  
  amt= scan.nextDouble();
  

  file.add(new HourlyEmployee(name,amt));

  break;

}
else if(e.equals("s"))
{
  System.out.println("Please enter Employee's annual salary: ");
  
  
  amt= scan.nextDouble();
  

  file.add(new SalariedEmployee(name,amt));
  
  break;
}
else
{
  clearScreen();
  System.out.println("Input was not h or s; Please try again: ");
 
}
}

catch(Exception e){
System.out.println("Invalid Input.. Please try again: ");
}

}



scan.close();

}






/////////////////////////////////////
//Asks user for percentage and raises all employees' wages by the amount

public static void raiseWages()
{
Scanner scn= new Scanner(System.in);

clearScreen();

if(file.size()==0)
{
	clearScreen();
	System.out.println("There are currently no Employees in the file\n\n\n");

}
else
{
  System.out.println("Please enter the percentage by which you would like to increase wages: ");

  double ans= scn.nextDouble();

  for(int i=0; i<file.size(); i++)
  {
    file.get(i).setWage(file.get(i).getWage()*(1+(ans/100.00)));
  }	
  System.out.println("Wages have been changed successfully\n\n");
}
scn.close();

}


///////////////////////////////////////
//Computes wages with imputed hours worked

public static void computeWages()
{

Scanner scn= new Scanner(System.in);

  if(file.size()==0)
  {
  
	clearScreen();
	System.out.println("There are currently no Employees in the file");
	
  }
  else
  {
		for(int i=0; i<file.size();i++)
		{
		System.out.println("Enter the number of hours worked by:  "+file.get(i).getName());

		int ans= scn.nextInt();

		file.get(i).computePay(ans);
		}
  }

	System.out.println("\n\n\n\n");
	scn.close();
}


public static void printRecords()
{
//System.out.println("	      EMPLOYEE  RECORDS		\n");
for(int i=0; i<file.size(); i++)
{

System.out.print(""+(i+1)+".");
System.out.println(file.get(i).toString());

}

System.out.println("\n\n\n");


}


public static void deleteEmployee()
{
Scanner scn= new Scanner(System.in);

//while(2>1)
//{
     try{

	printRecords();

	System.out.println("\nWhich Employee would you like to delete (Enter the appropriate number)?\n		Enter 0 to cancel..");

	int ans= scn.nextInt();
	
	if(ans==0)
	{
	clearScreen();
	System.out.println("Action canceled");
	}
	else
	{	
	file.remove(ans-1);
	clearScreen();
	System.out.println("Employee successfully removed");
	}

	}catch(Exception e){
	clearScreen();
	System.out.println("Invalid Input.. Please try again: ");
	deleteEmployee();
	}
scn.close();
//}

}

/////////////////////////////////////////
//Initiates UI with the User and prompts them with their options

public static void start()
{
Scanner scn= new Scanner(System.in);
ProcessBuilder processBuilder = new ProcessBuilder("java", "Utils/ObjIn.java" );
ProcessBuilder processBuilder2 = new ProcessBuilder("java", "Utils/ObjOut.java" );

System.out.println("	  Employee Database	");
System.out.println("\n"+"Commands: n- New Employee\n	  c- Compute Wages\n	  r- Raise Wages\n	  p- Print Records\n	  d- Download Data\n	  u- Upload Data\n	  k- Delete Employee\n	  q- Quit");	
System.out.println("Please enter a letter that corresponds with the action you would like to take: ");

String ans=scn.next();

switch (ans.toLowerCase())
{

case "n":	clearScreen();
		newEmployee();
		clearScreen();
		System.out.println("Employee was successfully created");
		start();

case "c":	clearScreen();
		computeWages();
		start();

case "r":	clearScreen();
		raiseWages();
		//System.out.println("Wages have been changed successfully");
		start();

case "p":	clearScreen();
		printRecords();
		start();

case "d":	clearScreen();
		try 
		{
			// Start the process
			Process process = processBuilder.start();
			
			// Wait for the process to complete
			int exitCode = process.waitFor();
			
			// Print the exit code
			System.out.println("Exit code: " + exitCode);
		} catch (IOException | InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println("File successfully downloaded\n");
		start();

case "u":	clearScreen();
		try 
		{
			// Start the process
			Process process = processBuilder2.start();
			
			// Wait for the process to complete
			int exitCode = process.waitFor();
			
			// Print the exit code
			System.out.println("Exit code: " + exitCode);
		} catch (IOException | InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println("	   File Uploaded\n");
		start();

case "k":	clearScreen();
		deleteEmployee();
		System.out.println("Employee Successfully Deleted");
		start();

case "q":	clearScreen();
		System.out.println("Goodbye");
		System.exit(0);

default:  clearScreen();
	  System.out.println("Command was not recognized; please try again...");
	  start();




}

scn.close();

}




}
