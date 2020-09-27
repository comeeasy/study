public class Goods {
    public String name;
    public int price;
    public int numberOfStock;
    public int sold;

    public Goods(String name, int price, int numberOfStock, int sold) {
        this.name  = name;
        this.price = price;
        this.numberOfStock = numberOfStock;
        this.sold = sold;
    }

    public void state() {
        System.out.println("상품 이름:"+name);
        System.out.println("상품 가격:"+price);
        System.out.println("재고 수량:"+numberOfStock);
        System.out.println("팔린 수량:"+sold);
    }

    String getName()   {return name;}
    int getPrice()         {return price;}
    int getNumberOfStock() {return numberOfStock;}
    int getSold()          {return sold;}

    public static void main(String[] args) {
        Goods camera = new Goods("Nikon", 400000, 30, 50);
        camera.state();
    }
}