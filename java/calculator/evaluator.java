/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package calculator;
import java.util.*;

/**
 *
 * @author naimahmumin
 */

abstract class Operator {
    public static HashMap<String, Operator> operators = new HashMap<String, Operator>();  
    
    public Operator(){ 
    }  
    
    public abstract int priority();
    
    public static boolean check(String tok){            
        if(operators.containsKey(tok)){
            return true;
        }
        return false;
    }
    
    public static void addOperators(){
        operators.put("+", new AdditionOperator());
        operators.put("-", new SubtractionOperator());
        operators.put("*", new MultiplicationOperator());
        operators.put("/", new DivisionOperator());
        operators.put("#", new HashOperator());
        operators.put("!", new ExclamationOperator());
    
    }
    
    public abstract Operand execute(Operand op1, Operand op2);
       
}

class Operand {
    String token;
    int val;
    public Operand(String tok){
        token = tok;
        val = Integer.parseInt(tok);
    }
    
    public Operand(int value){
        val = value;
        token = String.valueOf(value);        
    }
    
    public static boolean check(String tok){
        int x;
        try{
            x =  Integer.parseInt(tok);
            
        }catch(NumberFormatException e){
          return false;
        }
        
        return String.valueOf(x).equals(tok);
    }
    
    public int getValue(){        
        return val;
    }
}

class AdditionOperator extends Operator{
    
    @Override
    public Operand execute(Operand op1, Operand op2){
        Operand sum = new Operand(op1.getValue() + op2.getValue());
        return sum;
    }
    
    @Override
    public int priority(){
        return 2;
    }

}

class SubtractionOperator extends Operator{
    @Override
    public Operand execute(Operand op1, Operand op2){        
        Operand difference = new Operand((op1.getValue() - op2.getValue()));
        return difference;
    }
    
    @Override
    public int priority(){
        return 2;
    }
}

class DivisionOperator  extends Operator{
    
    @Override
    public Operand execute(Operand op1, Operand op2){
        Operand quotient = new Operand(op1.getValue() / op2.getValue());
        return quotient;
    }
    
    @Override
    public int priority(){
        return 3;
    }

}

class MultiplicationOperator extends Operator{
    
    @Override
    public Operand execute(Operand op1, Operand op2){
        Operand product = new Operand(op1.getValue() * op2.getValue());
        return product;
    }
    
    @Override
    public int priority(){
        return 3;
    }

}

class ExclamationOperator extends Operator{
    
    @Override
    public Operand execute(Operand op1, Operand op2){
        return null;
    }
    
    @Override
    public int priority(){
        return 0;
    }

}

class HashOperator extends Operator{
    
    @Override
    public Operand execute(Operand op1, Operand op2){
        return null;
    }
    
    @Override
    public int priority(){
        return 1;
    }

}

public class evaluator {
    private Stack<Operand> opdStack;
    private Stack<Operator> oprStack;
    
    public evaluator() {
        opdStack = new Stack<Operand>();
        oprStack = new Stack<Operator>();
    }
    
    
    
    public int eval(String expr){
        String tok;
        int answer = 0;
        
        Operator.addOperators();
        
        oprStack.push((Operator) Operator.operators.get("#"));
        
        String delimiters = "+-*/#! ";
        
        StringTokenizer st = new StringTokenizer(expr+'!', delimiters, true);
        
        while(st.hasMoreTokens()) {
            if( !(tok = st.nextToken()).equals(" ")){
                
                if(Operand.check(tok)) {
                    opdStack.push(new Operand(tok));
                } else {
                    if(!Operator.check(tok)) {
                        System.out.println("*****Invalid token*****");
                        
                        System.exit(1);
                    }
                    
                    Operator newOpr = (Operator) Operator.operators.get(tok);
                    
                    while (((Operator)oprStack.peek()).priority() >= newOpr.priority()) {
                        
                        Operator oldOpr = ((Operator)oprStack.pop());
                        
                        //check if you're at the end of the string
                        if(oldOpr.priority() == 1 && newOpr.priority() == 0)
                            break;
                        
                        Operand op2 = ((Operand)opdStack.pop());
                        Operand op1 = ((Operand)opdStack.pop());
                        opdStack.push(oldOpr.execute(op1,op2));
                        
                        
                    }
                    
                    oprStack.push(newOpr);
                }
            }
            
            
        }      
        
        answer = opdStack.pop().getValue();
        
        
        return answer;
    }
    
}
