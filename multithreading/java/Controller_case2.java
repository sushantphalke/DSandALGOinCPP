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
   ArrayList<Client> c;
    
    public Cook(ArrayList<Client> cc)
    {
    c=cc;
    }
    public void run()
    {
       try
       { 
        
        int s=c.size();
        ArrayList<Thread> tlist=new ArrayList<>();
        for(int i=0;i<s;i++)
        {
            tlist.add(new Thread(c.get(i)));
            c.get(i).exthread=Thread.currentThread().getId();
            tlist.get(i).start();
        }
        for(int i=0;i<s;i++)
        {
            tlist.get(i).join();
        }
        
        Controller_case2.sema.release();
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
                    Controller_case2.sema.acquire();
                    ArrayList<Client> proc_que=new ArrayList<>();
                    if(!q.isEmpty())proc_que.add(q.poll());
                    if(!q.isEmpty())proc_que.add(q.poll());
                    if(!q.isEmpty())proc_que.add(q.poll());
                    Cook c=new Cook(proc_que);
                    c.start();
                }
           
            }
        catch(Exception e)
        {
        System.out.println("cook headd "+e);
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

class Controller_case2
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