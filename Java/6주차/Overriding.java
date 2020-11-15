class Person3 {
    String phone;
    public void setPhone(String phone) {this.phone = phone;}
    public String getPhone() {return "Professor: " + phone;}
}

class Professor2 extends Person3 {
    public String getPhone() {
        return super.getPhone();
    }
}

public class Overriding {
    public static void main(String[] args) {
        Professor2  pf = new Professor2();

        pf.setPhone("011-123-1234");
        System.out.println(pf.getPhone());
        Person3 p = pf;
        System.out.println(p.getPhone());
    }
}
