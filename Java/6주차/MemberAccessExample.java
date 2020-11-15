public class MemberAccessExample {
    public static void main(String[] args) {
        A a = new A();
        B b = new B();

        a.p = 5;
        // a.n = 5; // private member, 컴파일 오류 발생

        b.p = 5;
        // b.n = 5; // private member, 컴파일 오류 발생
        b.setN(10);

        int i = b.getN();

        // b.m = 20; // private member, 컴파일 오류 발생
        b.setM(20);
        System.out.println(b.toString());
    }
}
