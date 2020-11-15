import java.util.*;

public class MyExp {
    public int base;
    public int exp;

    public MyExp() {}
    public MyExp(int base, int exp) {
        this.base = base;
        this.exp = exp;
    }

    public void getValue() {
        int toRet = 1;
        for(int i=0; i<exp; ++i) toRet *= base;
        System.out.println(base+"의 "+exp+"승 = "+toRet);
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        MyExp myExpon = new MyExp();

        myExpon.base = cin.nextInt();
        myExpon.exp = cin.nextInt();

        myExpon.getValue();
        cin.close();
    }
}
