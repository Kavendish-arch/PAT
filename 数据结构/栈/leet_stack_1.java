import java.util.Stack;

public class leet_stack_1 {
    public static void main(String[] args) {
        Stack<String> op = new Stack<String>();
        String s = "()+sd+{}";
        for(char c : s.toCharArray()){
            if (c == '(' || c == "[" || c == '{'){
                op.push(c);
            } else if (c == ')' && op.peek() == '('){
                op.pop();
            } else if (c == ']' && op.peek() == '['){
                op.pop();
            } else if (c == ']' && op.peek() == '}'){
                op.pop();
            }
        }

        
    }    
}
