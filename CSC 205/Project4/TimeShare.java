import java.util.*;
import java.io.*;

@SuppressWarnings("unchecked")

public class TimeShare 
{

public static Queue q1= new Queue();

public static int Clock=1;

public static double idle=0;

public static double usage=0;

//public static Queue jobQueue= new Queue();

//public static Queue finishQueue=new Queue();


public static void main (String [] args) throws FileNotFoundException, CloneNotSupportedException
{



formatter(args[0]);


//System.out.println(benchmark(q1).front());

runStats(benchmark(q1));

//runStats(q1);

}


public static Queue benchmark(Queue q) 
{

Queue jobQueue= new Queue();

Queue finishQueue= new Queue();

//boolean hasJob=true;

//Job work=new Job();

//Job temp=(Job) q.front();


while(!q.isEmpty() || !jobQueue.isEmpty())
{

Job temp= new Job();

Job work= new Job();

//if(!q.isEmpty())
//	temp= (Job) q.front();
System.out.println(q.isEmpty());


//System.out.println(temp);

if(!q.isEmpty())
{

	temp= (Job) q.front();
	//temp.startTime=Clock;
	//q.front()=temp;
	//System.out.println(temp.arrivalTime);
	if(temp.arrivalTime==Clock)
		jobQueue.enqueue(q.dequeue());

	//Job work= (Job) jobQueue.front();

	//System.out.println(q.dequeue());
}

if(!jobQueue.isEmpty())
{

	

	work= (Job) jobQueue.front();
	
	//System.out.println(work);
	
	//System.out.println(jobQueue.front());

	if(work.startTime>0 && work.runTime==(Clock-work.startTime))
	{
		
		work.turnTime=(Clock-work.arrivalTime);
		work.waitTime=work.startTime-work.arrivalTime;
	//	System.out.println(waitTime);
		//jobQueue.front()=work;
		
		finishQueue.enqueue(jobQueue.dequeue());
		//work=(Job) jobQueue.front();
	//	System.out.println(finishQueue.front());
	//	System.out.println(jobQueue.dequeue());
	}
	

	if(work.arrivalTime>=Clock)
	{
	work.startTime=Clock;
	System.out.println(work);
	}


}


if (jobQueue.isEmpty())
{
	idle++;
}
else
usage++;
//System.out.println(usage);
Clock++;
System.out.println(Clock);

}


return finishQueue;

}




public static void formatter(String file) throws FileNotFoundException
{
Scanner scn= new Scanner(new File(file));

while(scn.hasNext())
{
q1.enqueue(new Job(scn.next(),scn.nextInt(),scn.nextInt()));
}


}




public static void runStats(Queue q) throws CloneNotSupportedException
{

Queue temp= (Queue) q.clone();

System.out.println("\u001b[H\u001b[2J");


System.out.println("\t\t\t\t  BENCHMARK REPORTS\n\n");

System.out.println("ID\t Arrival Time\t Start Time\t Run Time\t Wait Time\t Turn Around Time");

while(temp.peek()!=null)
{
System.out.println(temp.dequeue());
}


System.out.println("\n\nAvg Wait Time:  "+"\n");
System.out.println("CPU Usage: "+usage+"\n");
System.out.println("CPU Idle: "+idle+"\n");
System.out.println("CPU Usage(%): "+(usage/(usage + idle))+"%\n");
}








}
