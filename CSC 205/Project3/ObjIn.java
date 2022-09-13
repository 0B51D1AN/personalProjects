import java.io.*;

import java.util.*;

@SuppressWarnings("unchecked")

public class ObjIn
{
      public static ArrayList<Employee>  objectIn(ArrayList<Employee> a)
      {
        
	ArrayList<Employee> ans=new ArrayList<Employee>();
	
	String fileName = "object.out";
       // int[] a = null;
        try {
          FileInputStream fileIn =
            new FileInputStream(fileName);
          ObjectInputStream in =
            new ObjectInputStream(fileIn);
          a = (ArrayList<Employee>) in.readObject();
          in.close();
        }
        catch (IOException e) {
          System.out.println(e.getMessage());
        }
        catch (ClassNotFoundException e)
        {
          System.out.println(e.getMessage());
        }
        //EmployeeTest.printRecords();
	
	
	
	for (int i = 0;  i < a.size();  i++)
	{
                System.out.print(""+(i+1)+".");
		System.out.println(a.get(i).toString());
		ans.add(a.get(i));
	}

	System.out.println("\n\n\n");
	
	return ans;

      }



}
