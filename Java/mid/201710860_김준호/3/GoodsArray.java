import java.util.*;

class Goods {
    private String name;
    private int price;
    private int numberOfStock;
    private int sold;

    Goods(String name, int price, int numberOfStock, int sold) {
        this.name = name;
        this.price= price;
        this.numberOfStock = numberOfStock;
        this.sold = sold;
    }
    String getName() {return name;}
    int getPrice() {return price;}
    int getNumberOfStock() {return numberOfStock;}
    int getSold() {return sold;}
}

public class GoodsArray {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        ArrayList<Goods> list = new ArrayList<Goods>();

        System.out.println("상품 세개를 차례로 입력하라.");
        for(int i=0; i<3; ++i) {
            String name = cin.next();;
            int price = cin.nextInt();
            int numberOfStock = cin.nextInt();
            int sold = cin.nextInt();;

            list.add(new Goods(name, price, numberOfStock, sold));
        }

        System.out.println("입력된 상품 정보는 다음과 같습니다.");
        for(Goods goods : list) 
            System.out.printf("%s %d %d %d\n", goods.getName(), goods.getPrice(),
                                                goods.getNumberOfStock(), goods.getSold());

        cin.close();
    }
}