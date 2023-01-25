import java.util.Scanner;



class fib {
  public static int parallel_fib(int n){
    if(n<=1)
    return n ;
    else {
        int x = parallel_fib(n-1);
        int y = parallel_fib(n-2);
       
        return x+y;
    }
  }
  
  public static void main(String[] args) {
    Scanner reader = new Scanner(System.in);
    int number = reader.nextInt();
    System.out.println("You entered: " + parallel_fib(number));
  }
}