/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package homework1;

/**
 *
 * @author naimahmumin
 */
public class EvaluatorTester {

    /**
     * @param args the command line arguments
     */
     
    public static void main(String[] args) {
       
       Evaluator anEvaluator = new Evaluator();
       for (String arg : args) {
           System.out.println(arg + " = " + anEvaluator.eval(arg));
       }
        
    }
    
}
    
   