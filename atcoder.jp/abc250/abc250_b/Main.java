import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int count = 0;
        int count2 = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<a; j++){
                count = count2;
                for(int k = 0; k<n; k++){
                    for(int l = 0; l<b; l++){
                        if(count%2==0)
                            System.out.print(".");
                        else
                            System.out.print("#");
                    }
                    count++;
                }
                System.out.println();
            }
          count2++;
        }
    }
}