class Person2 {}
class Student2 extends Person2 {}
class Researcher extends Person2 {}
class Professor extends Researcher {} 

public class InstatanceOfExample {
    public static void main(String[] args) {
        Person2 jee = new Person2();
        Person2 kim = new Professor();
        Person2 lee = new Researcher();

        if(jee instanceof Student2) System.out.println("jee는 Student 타입");
        if(jee instanceof Researcher) System.out.println("jee는 Researcher 타입");
        if(kim instanceof Student2) System.out.println("kim은 Student 타입");
        if(kim instanceof Professor) System.out.println("kim은 Professor 타입");
        if(kim instanceof Researcher) System.out.println("kim은 Researcher 타입");
        if(kim instanceof Person2) System.out.println("kim은 Person 타입");
        if(lee instanceof Professor) System.out.println("lee는 Professor 타입");
        if("java" instanceof String) System.out.println("\"java\"는 String 타입");
    }
}
