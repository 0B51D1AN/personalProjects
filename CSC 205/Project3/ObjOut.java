import java.io.*;

import java.util.*;


public class ObjOut
{
      public static void objectOut(ArrayList<Employee> a)
      {
        String fileName = "object.out";
        //int[] a = {1, 2, 3};
        try {
          FileOutputStream fileOut =
            new FileOutputStream(fileName);
          ObjectOutputStream out =
            new ObjectOutputStream(fileOut);
          out.writeObject(a);
          out.close();
        }
        catch (IOException e) {
          System.out.println(e.getMessage());
        }
      }
}
