import java.io.Serializable;

@SuppressWarnings("serial")

public class HourlyEmployee extends Employee implements Serializable
{

public HourlyEmployee(String n, double hW)
{

super(n,hW);

}

public String getName()
{

return name;

}

public double getWage()
{

return hourlyWage;

}

public void setName(String n)
{
name=n;
System.out.println("Name has been changed");
}

public void setWage(double w)
{
hourlyWage=w;
//System.out.println("Hourly wage has been changed");
}


public void computePay(int hoursWorked)
{

if(hoursWorked > 40)
{

int temp= hoursWorked-40;
System.out.println("Pay:  "+Utilities.toDollars(((this.getWage()*40)+(this.getWage()*temp*1.5))));

}
else
System.out.println("Pay:  "+Utilities.toDollars((this.getWage()*hoursWorked)));

}


public String toString()
{

return Utilities.pad(this.getName(),35-Utilities.toDollars(this.getWage()).length())+Utilities.toDollars(this.getWage())+"/hour";

}

}
