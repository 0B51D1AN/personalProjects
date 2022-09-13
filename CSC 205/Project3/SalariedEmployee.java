import java.io.Serializable;

@SuppressWarnings("serial")

public class SalariedEmployee extends Employee implements Serializable
{

private double annualSalary; 


public SalariedEmployee(String n, double hW)
{
super(n,(hW/52)/40);

annualSalary=hW;

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
}


public void computePay(int hoursWorked)
{

System.out.println("Pay:  "+Utilities.toDollars(((annualSalary/52)/40)*hoursWorked));

}


public String toString()
{

return Utilities.pad(this.getName(), 35-Utilities.toDollars(this.getWage()).length())+Utilities.toDollars(annualSalary)+"/year";

}

}
