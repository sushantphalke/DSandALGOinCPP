import java.util.*;
import java.util.concurrent.Semaphore;
import java.sql.Timestamp;
class Client implements Runnable 
{
    public long exthread;
    public void run()
    {
       try
       {
        Timestamp tsp = new Timestamp(System.currentTimeMillis()); 
        
       
        long start_time=tsp.getTime();
        String str_start=tsp.toString();
        Thread.sleep(2000);    
        Timestamp tsp2 = new Timestamp(System.currentTimeMillis());
        System.out.println("cook with id "+exthread+" started cooking for client with id "+Thread.currentThread().getId()+" at "+str_start+"("+start_time+")"+ " completed at time"+tsp2.toString()+"("+tsp2.getTime()+")");  
        }
        catch(Exception e)
        {
            System.out.println("sleep excepion");
        }
    }
}
class Cook extends Thread
{
    Client c;
    
    public Cook(Client cc)
    {
    c=cc;
    }
    public void run()
    {
       try
       { Thread tc=new Thread(c);
        c.exthread=Thread.currentThread().getId();
        tc.start();
        tc.join();
        Controller.sema.release();
       }
       catch(Exception e)
       {
        System.out.println("exception cook "+e);
       }
    
    }
}
class CookHead extends Thread
{
    int n;
    int count;
    Queue<Client> q;
    CookHead(int n,Queue<Client> q)
    {
        this.n=n;
        this.q=q;
        count=0;
    }

    public void run()
    {
       try{   
                while( !q.isEmpty())
                {   
                    Controller.sema.acquire();
                    Cook c=new Cook(q.poll());
                    c.start();
                }
           
            }
        catch(Exception e)
        {
        System.out.println("cook head");
        }
    }
} 

class Waiter extends Thread
{
    int no;
    Queue<Client> queue;
    Waiter(int n, Queue<Client> q)
    {
        no=n;
        queue=q;
    } 
    public void run()
    {
        try
        {
            for(int i=0;i<no;i++)
            {
                Client c= new Client();
                queue.add(c);
                //System.out.println("client added");                
            }        
        }
        catch(Exception ex)
        {
            System.out.println("opps...ran into exception");
        }
    }
}

class Controller
{
    static Semaphore sema;
    public static void main(String str[])
    {
        int cno,eno;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter no of client processes ");
        cno=sc.nextInt();
        System.out.println("Enter no of executive processes ");
        eno=sc.nextInt();
        sema = new Semaphore(eno);
        if(cno<eno)
        {
            sc.close();
            return;
        }
        Queue<Client> queue=new LinkedList<Client>();
        Waiter w=new Waiter(cno, queue);
        w.run();
        CookHead ch=new CookHead(eno, queue);
        ch.start();
        System.out.println("exiting...");
        sc.close();
    }
}