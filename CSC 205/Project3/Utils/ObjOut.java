import java.io.*;
public class ObjOut
{
      public static void main(String[] args)
      {
        String fileName = "object.out";
        
        //Need to change a to be array in Employee Test so that it can be read to object.out
        int[] a = {1, 2, 3};
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
