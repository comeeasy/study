import java.util.*;

public class StringStack implements Stack {
    List<String> stack;

    StringStack() {this.stack = new ArrayList<String>();}

    public int length() {
        return stack.size();
    }
    public String pop() {
        String tmp = stack.get(stack.size()-1);
        stack.remove(stack.size()-1);
        return tmp;
    }
    public Boolean push(Object str) {
        if(stack.add((String)str)) return true;
        else return false;
    }

    public static void main(String[] args) {
        StringStack ss = new StringStack();

        ss.push("Hello world!");
        System.out.println("\"Hello world!\" pushed");
        ss.push("Hello Java!");
        System.out.println("\"Hello Java\" pushed");

        System.err.println("pop");
        System.out.println(ss.pop());
        System.err.println("pop");
        System.out.println(ss.pop());
    }
}