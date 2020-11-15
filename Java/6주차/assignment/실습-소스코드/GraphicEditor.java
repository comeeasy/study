import java.util.*;
abstract class Dobject {
    abstract void show();
}
class LLine extends Dobject {
    void show() {System.out.println("Line");}
}
class CCircle extends Dobject {
    void show() {System.out.println("Circle");}
}
class RRect extends Dobject {
    void show() {System.out.println("Rect");}
}
public class GraphicEditor {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        List<Dobject> list = new LinkedList<Dobject>();

        while(true) {
            System.out.print("삽입(1), 삭제(2), 모두 보기(3), 종료(4) >> ");
            int key = cin.nextInt();
            
            if(key == 4) break;
            switch(key) {
                case 1: System.out.print("도형 종류 Line(1), Rect(2), Circle(3) >> ");
                        key = cin.nextInt();
                        switch(key) {
                            case 1: list.add(new LLine());  break;
                            case 2: list.add(new RRect());  break;
                            case 3: list.add(new CCircle());break;
                        }
                        break;
                case 2: list.remove(list.size() - 1);   break;
                case 3: for (Dobject dobject : list) {dobject.show();}  
                        break;
            }
        }
        cin.close();
    }
}