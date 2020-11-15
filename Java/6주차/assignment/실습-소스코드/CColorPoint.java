class Cpoint {
    int x, y;
    String name;

    Cpoint(int x, int y) {
        this.x = x;
        this.y = y;  
        this.name = ""; 
    } 
    
    void show() {System.out.printf("(%d, %d) %s\n", x, y, name);}
    public String toString() {return "("+x+", "+y+") 입니다.";}
}

public class CColorPoint extends Cpoint {
    CColorPoint(int x, int y, String name) {
        super(x, y);
        this.name = name;
    }    

    public static void main(String[] args) {
        Cpoint a, b;
        a = new Cpoint(2, 3);
        b = new CColorPoint(3, 4, "red");
        a.show();
        b.show();
        System.out.println(a);
        System.out.println(b);
    }
}
