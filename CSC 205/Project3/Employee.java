import java.io.Serializable;

@SuppressWarnings("serial")


abstract class Employee implements Serializable
{

protected String name;

protected double hourlyWage;

protected int hoursWorked;

public Employee(String n, double hW)
{
name=n;

hourlyWage=hW;

//hoursWorked=40;
}

public abstract String getName();

public abstract double getWage();

public abstract void setName(String n);

public abstract void setWage(double w);

public abstract  void computePay(int hoursWorked);

}

