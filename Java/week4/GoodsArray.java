import java.util.*;

public class GoodsArray {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in "UTF-8");
        Goods[] ga = new Goods[3];

        // set
        for(int i=0; i<3; ++i) {
            String name = cin.next();
            int price   = cin.nextInt();
            int numberOfStock = cin.nextInt();
            int sold    = cin.nextInt();
            ga[i] = new Goods(name, price, numberOfStock, sold);
        }
        
        // get
        for(int i=0; i<3; ++i) {
            System.out.print(ga[i].getName()+" ");
            System.out.print(ga[i].getPrice()+" ");
            System.out.print(ga[i].getNumberOfStock()+" ");
            System.out.println(ga[i].getSold());
        }

        cin.close();
    }
}
