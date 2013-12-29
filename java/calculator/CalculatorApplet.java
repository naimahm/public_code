/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package calculator;
import java.applet.Applet;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.*;

/**
 *
 * @author naimahmumin
 */
public class CalculatorApplet extends Applet implements ActionListener{
    TextField t = new TextField();
    Panel p = new Panel();
    Button b1 = new Button("1");
    Button b2 = new Button("2");
    Button b3 = new Button("3");
    Button b4 = new Button("4");
    Button b5 = new Button("5");
    Button b6 = new Button("6");
    Button b7 = new Button("7");
    Button b8 = new Button("8");
    Button b9 = new Button("9");
    Button b0 = new Button("0");
    Button bplus = new Button("+");
    Button bminus = new Button("-");
    Button bmult = new Button("*");
    Button bdivide = new Button("/");
    Button bequal = new Button("=");
    Button bdec = new Button(".");
    Button bleftparen = new Button("(");
    Button brightparen = new Button(")");
    Button bclear = new Button("C");
    Button bclearall = new Button("CE");
    float f1, f2;
    String operator = "";
    boolean equals = false;
    String expression = "";
    
    
    public void init(){
        setLayout(new BorderLayout());
        add(t, BorderLayout.NORTH);
        add(p, BorderLayout.CENTER);
        p.setLayout(new GridLayout(4,5));
        p.add(b7);
        p.add(b8);
        p.add(b9);
        p.add(bclearall);
        p.add(bmult);
        p.add(b4);
        p.add(b5);
        p.add(b6);
        p.add(bplus);
        p.add(bminus);
        p.add(b1);
        p.add(b2);
        p.add(b3);
        p.add(bdivide);
        p.add(bleftparen);
        p.add(b0);
        p.add(bdec);
        p.add(bclear);
        p.add(brightparen);
        p.add(bequal);
    
        b0.addActionListener(this);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener(this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
        bdivide.addActionListener(this);
        bequal.addActionListener(this);
        bplus.addActionListener(this);
        bminus.addActionListener(this);
        bmult.addActionListener(this);
        bdec.addActionListener(this);
        bleftparen.addActionListener(this);
        brightparen.addActionListener(this);
        bclear.addActionListener(this);
        bclearall.addActionListener(this);
    }
    
    public void clear(){
        t.setText("");
        f1 = f2 = 0;
        operator = "";
        expression = "";
    }
    
    public void actionPerformed(ActionEvent arg0) {
            System.out.println(expression);
        
        //if the last thing pressed was equals, clear the screen
        //and begin new expression
        if(equals){
            equals = false;
            clear();            
        }
            
        if(arg0.getSource()==b0)
            t.setText(t.getText()+"0");
        if(arg0.getSource()==b1)
            t.setText(t.getText()+"1");
        if(arg0.getSource()==b2)
            t.setText(t.getText()+"2");
        if(arg0.getSource()==b3)
            t.setText(t.getText()+"3");
        if(arg0.getSource()==b4)
            t.setText(t.getText()+"4");
        if(arg0.getSource()==b5)
            t.setText(t.getText()+"5");
        if(arg0.getSource()==b6)
            t.setText(t.getText()+"6");
        if(arg0.getSource()==b7)
            t.setText(t.getText()+"7");
        if(arg0.getSource()==b8)
            t.setText(t.getText()+"8");
        if(arg0.getSource()==b9)
            t.setText(t.getText()+"9");
        
        if(arg0.getSource()==bclear){
            String str = t.getText();
            if(str.length()>1)
                t.setText(str.substring(0, (str.length()-1)));
        }
        
        if(arg0.getSource()==bclearall){
            clear();
        }
        
        if(arg0.getSource()==bdivide){
            operator = bdivide.getLabel();
            if("".equals(expression))
                expression = t.getText() + " " + operator;
            else
                expression = expression + " " + t.getText() + operator;
            
            t.setText("");
        }
        
        if(arg0.getSource()==bmult){
            f1 = Float.parseFloat(t.getText());
            operator = bmult.getLabel();
            if("".equals(expression))
                expression = t.getText() + " " + operator;
            else
                expression = expression + " " + t.getText() + operator;
            
            t.setText("");
        }
        
        if(arg0.getSource()==bplus){
            f1 = Float.parseFloat(t.getText());
            operator = bplus.getLabel();
            if("".equals(expression))
                expression = t.getText() + " " + operator;
            else
                expression = expression + " " + t.getText() + operator;
            
            t.setText("");      
        }
        
        if(arg0.getSource()==bminus){
            f1 = Float.parseFloat(t.getText());
            operator = bminus.getLabel();
            if("".equals(expression))
                expression = t.getText() + " " + operator;
            else
                expression = expression + " " + t.getText() + operator;
            
            t.setText("");
        }
        
        if(arg0.getSource()==bdec)
            t.setText(t.getText()+".");
                
        if(arg0.getSource()==bleftparen){
            expression = expression + " " + t.getText() + bleftparen.getLabel();
            t.setText("");
        }        
                
        if(arg0.getSource()==brightparen){
            expression = expression + " " + t.getText() + brightparen.getLabel();
            t.setText("");
        }        
        
        if(arg0.getSource()==bequal){           
            expression = expression + t.getText();
            System.out.println(expression);
            evaluator anEvaluator = new evaluator();
            t.setText(String.valueOf(anEvaluator.eval(expression)));
            equals = true;            
        }
    }
    
}

