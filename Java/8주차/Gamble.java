import java.util.Scanner;

class Person {
    public String name;
    
    public Person(String name) {this.name = name;}
    public int[] gambling() {
        int[] numbers = new int[3];
        for(int i=0; i<3; ++i) numbers[i] = (int)(Math.round(Math.random()*3));
        return numbers;
    }
    public static boolean isWin(Person p) {
        int[] result = p.gambling();

        System.out.printf("%s의 결과는 %d %d %d 입니다.\n", p.name, result[0], result[1], result[2]);
        if(result[0] == result[1] && result[0] == result[2] && result[1] == result[2]) 
            return true;
        else 
            return false;
    }
}

public class Gamble {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Person p1 = new Person("준호");
        Person p2 = new Person("우석");

        while(true) {
            if(Person.isWin(p1)) {
                System.out.printf("%s is win!\n", p1.name);
                break;
            }

            if(Person.isWin(p2)) {
                System.out.printf("%s is win!\n", p2.name);
                break;
            }
        }

        cin.close();
    }
}
