package Tang;

import java.awt.*;
import java.util.Scanner;

public abstract class GeometricObject implements Comparable<GeometricObject>{
    private String color="white";
    private boolean filled;
    public GeometricObject() {
    }
    public GeometricObject(String color, boolean filled) {
        this.color=color;
        this.filled=filled;
    }
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color=color;
    }
    public boolean isFilled() {
        return filled;
    }
    public void setFilled(boolean filled) {
        this.filled=filled;
    }
    public String toString() {
        return "color: "+color+" and filled: "+filled;
    }
    public static int max(GeometricObject Obj1,GeometricObject Obj2) {
        if(Obj1.compareTo(Obj2)>0)
            return 1;
        if(Obj1.compareTo(Obj2)<0)
            return -1;
        return 0;
    }
    public Object clone() {
        try {
            return super.clone();
        }
        catch(CloneNotSupportedException ex) {
            return null;
        }
    }
    public abstract double getArea() ;
    public abstract double getPerimeter();
    public abstract void howToColor();
    public abstract void add(GeometricObject complex1,GeometricObject complex2);
    public abstract void subtract(GeometricObject complex1,GeometricObject complex2);
    public abstract void multiply(GeometricObject complex1,GeometricObject complex2);
    public abstract void divide(GeometricObject complex1,GeometricObject complex2);
    public abstract double abs(GeometricObject complex);
    public abstract String toString(GeometricObject complex);
    public abstract double getRealPart();
    public abstract double getImaginarypart();
}
interface Colorable {
    public abstract void howToColor() ;
}
// class Circle extends GeometricObject{
//    private double r;
//    public Circle(){
//    }
//    public Circle(double r) {
//        this.r=r;
//    }
//    public double getR() {
//        return r;
//    }
//    public void setR(double r) {
//        this.r=r;
//    }
//    @Override
//    public double getArea() {
//        return Math.PI*r*r;
//    }
//    @Override
//    public double getPerimeter() {
//        return 2*Math.PI*r;
//    }
//    @Override
//    public int compareTo(GeometricObject arg0) {
//        if(this.getArea()>arg0.getArea())
//            return 1;
//        if(this.getArea()<arg0.getArea())
//            return -1;
//        return 0;
//    }
//
//     @Override
//     public void howToColor() {
//
//     }
// }
// class ComparableCircle extends Circle{
//    public ComparableCircle(double radius) {
//        super(radius);
//    }
//    @Override
//    public int compareTo(GeometricObject arg0) {
//        if(this.getArea()>arg0.getArea())
//            return 1;
//        if(this.getArea()<arg0.getArea())
//            return -1;
//        return 0;
//    }
//}
//class Rectangle extends GeometricObject{
//    private double length;
//    private double width;
//    public Rectangle() {
//    }
//    public Rectangle(double length,double width) {
//        this.length=length;
//        this.width=width;
//    }
//    public double getLength() {
//        return length;
//    }
//    public void setLength(double length) {
//        this.length=length;
//    }
//    public double getWidth() {
//        return width;
//    }
//    public void setWidth(double width) {
//        this.width=width;
//    }
//    @Override
//    public double getArea() {
//        return length*width;
//    }
//    @Override
//    public double getPerimeter() {
//        return 2*(length+width);
//    }
//    @Override
//    public int compareTo(GeometricObject arg0) {
//        if(this.getArea()>arg0.getArea())
//            return 1;
//        if(this.getArea()<arg0.getArea())
//            return -1;
//        return 0;
//    }
//
//    @Override
//    public void howToColor() {
//
//    }
//}
//class one {
//    public static void main(String[] args) {
//        Scanner input=new Scanner(System.in);
//
//        System.out.print("Enter the first rectangle's length and width: ");
//        double length1=input.nextDouble();
//        double width1=input.nextDouble();
//        System.out.print("Enter the second rectangle's length and width: ");
//        double length2=input.nextDouble();
//        double width2=input.nextDouble();
//        GeometricObject rectangle1=new Rectangle(length1,width1);
//        GeometricObject rectangle2=new Rectangle(length2,width2);
//        int num1=GeometricObject.max(rectangle1, rectangle2);
//        if(num1==1)
//            System.out.println("The first one is bigger than the second! ");
//        if(num1==-1)
//            System.out.println("The first one is smaller than the second! ");
//        if(num1==0)
//            System.out.println("The first one is as big as the second! ");
//
//        System.out.print("Enter the first circle's radius: ");
//        double r1=input.nextDouble();
//        System.out.print("Enter the second circle's radius: ");
//        double r2=input.nextDouble();
//        GeometricObject circle1=new Circle(r1);
//        GeometricObject circle2=new Circle(r2);
//        int num2=GeometricObject.max(circle1,circle2);
//        if(num2==1)
//            System.out.println("The first one is bigger than the second! ");
//        if(num2==-1)
//            System.out.println("The first one is smaller than the second! ");
//        if(num2==0)
//            System.out.println("The first one is as big as the second! ");
//    }
//}
//class ComparableCircle extends Circle{
//    public ComparableCircle(double radius) {
//        super(radius);
//    }
//    @Override
//    public int compareTo(GeometricObject arg0) {
//        if(this.getArea()>arg0.getArea())
//            return 1;
//        if(this.getArea()<arg0.getArea())
//            return -1;
//        return 0;
//    }
//}
//    class Square extends GeometricObject implements Colorable{
//    private double side=0;
//    private boolean canbeColored;
//    public Square() {
//    }
//    public Square(double side,boolean canbeColored) {
//        this.side=side;
//        this.canbeColored=canbeColored;
//    }
//    public double getSide() {
//        return side;
//    }
//    public void setSide(double side) {
//        this.side=side;
//    }
//    public boolean getCanbeColored() {
//        return canbeColored;
//    }
//    @Override
//    public double getArea() {
//        return side*side;
//    }
//    @Override
//    public double getPerimeter() {
//        return 4*side;
//    }
//    @Override
//    public int compareTo(GeometricObject arg0) {
//        // TODO Auto-generated method stub
//        return 0;
//    }
//    @Override
//    public  void howToColor() {
//        if(getCanbeColored())
//            System.out.println("Color all four sides");
//        else
//            System.out.println("Can not be colored");
//    }
//}
//class three {
//    public static void main(String[] args) {
//        Scanner input=new Scanner(System.in);
//        System.out.println("Enter side and canbeColored for five objects:");
//        GeometricObject[] square=new Square[5];
//        for(int i=0;i<5;i++) {
//            double side=input.nextDouble();
//            boolean canbeColored=input.nextBoolean();
//            square[i]=new Square(side,canbeColored);
//        }
//        for(int i=0;i<5;i++) {
//            System.out.print("第"+(i+1)+"个对象:");
//            square[i].howToColor();
//        }
//    }
//}
//class Octagon extends GeometricObject implements Cloneable{
//    private double side=0;
//    public Octagon() {
//    }
//    public Octagon(double side) {
//        this.side=side;
//    }
//    public double getSide() {
//        return side;
//    }
//    public void setSide(double side) {
//        this.side=side;
//    }
//    @Override
//    public int compareTo(GeometricObject arg0) {
//        if(this.getArea()>arg0.getArea())
//            return 1;
//        if(this.getArea()<arg0.getArea())
//            return -1;
//        return 0;
//    }
//
//    @Override
//    public double getArea() {
//        return (2+4/Math.sqrt(2))*side*side;
//    }
//    @Override
//    public double getPerimeter() {
//        return 8*side;
//    }
//    @Override
//    public void howToColor() {
//        // TODO Auto-generated method stub
//    }
//}
//class four {
//    public static void main(String[] args) {
//        GeometricObject octagon1=new Octagon(5);
//        System.out.println("The area is: "+octagon1.getArea());
//        System.out.println("The perimeter is: "+octagon1.getPerimeter());
//        GeometricObject octagon2=(GeometricObject) octagon1.clone();
//        int num=GeometricObject.max(octagon1,octagon2);
//        if(num==1)
//            System.out.println("The first one is bigger than the second! ");
//        if(num==-1)
//            System.out.println("The first one is smaller than the second! ");
//        if(num==0)
//            System.out.println("The first one is as big as the second! ");
//    }
//}
// class five {
//    public static void main(String[] args) {
//        Scanner input=new Scanner(System.in);
//        GeometricObject[] geometricObject1=new Rectangle[2];
//        GeometricObject[] geometricObject2=new Circle[2];
//        System.out.print("Enter the first rectangle's length and width: ");
//        double length1=input.nextDouble();
//        double width1=input.nextDouble();
//        System.out.print("Enter the second rectangle's length and width: ");
//        double length2=input.nextDouble();
//        double width2=input.nextDouble();
//        geometricObject1[0]=new Rectangle(length1,width1);
//        geometricObject1[1]=new Rectangle(length2,width2);
//        System.out.print("Enter the first circle's radius: ");
//        double r1=input.nextDouble();
//        System.out.print("Enter the second circle's radius: ");
//        double r2=input.nextDouble();
//        geometricObject2[0]=new ComparableCircle(r1);
//        geometricObject2[1]=new ComparableCircle(r2);
//        System.out.println("The sum of area is:"+(sumArea(geometricObject1)+sumArea(geometricObject2)));
//    }
//    public static double sumArea(GeometricObject[] a) {
//        double sum=0;
//        for(int i=0;i<2;i++) {
//            sum+=a[i].getArea();
//        }
//        return sum;
//    }
//}
class Complex extends GeometricObject implements Cloneable{
    private double realPart;
    private double imaginarypart;
    public Complex() {
    }
    public Complex(double realPart) {
        this.realPart=realPart;
        this.imaginarypart=0;
    }
    public Complex(double realPart,double imaginarypart) {
        this.realPart=realPart;
        this.imaginarypart=imaginarypart;
    }
    @Override
    public double getRealPart() {
        return realPart;
    }
    @Override
    public double getImaginarypart() {
        return imaginarypart;
    }
    public void setRealPart(double realPart) {
        this.realPart=realPart;
    }
    public void setImaginarypart(double imaginarypart) {
        this.imaginarypart=imaginarypart;
    }
    @Override
    public void add(GeometricObject complex1,GeometricObject complex2) {
        System.out.println("("+toString(complex1)+") + ("+toString(complex2)+") = "
                +(complex1.getRealPart()+complex2.getRealPart())+" + "
                +(complex1.getImaginarypart()+complex2.getImaginarypart())+"i");
    }
    @Override
    public void subtract(GeometricObject complex1,GeometricObject complex2) {
        System.out.println("("+toString(complex1)+") - ("+toString(complex2)+") = "
                +(complex1.getRealPart()-complex2.getRealPart())+" + "
                +(complex1.getImaginarypart()-complex2.getImaginarypart())+"i");
    }
    @Override
    public void multiply(GeometricObject complex1,GeometricObject complex2) {
        System.out.println("("+toString(complex1)+") * ("+toString(complex2)+") = "
                +(complex1.getRealPart()*complex2.getRealPart()-complex1.getImaginarypart()*complex2.getImaginarypart())+" + "
                +(complex1.getImaginarypart()*complex2.getRealPart()+complex1.getRealPart()*complex2.getImaginarypart())+"i");
    }
    @Override
    public void divide(GeometricObject complex1,GeometricObject complex2) {
        System.out.println("("+toString(complex1)+") / ("+toString(complex2)+") = "
                +((complex1.getRealPart()*complex2.getRealPart()+complex1.getImaginarypart()*complex2.getImaginarypart())
                /(complex2.getRealPart()*complex2.getRealPart()+complex2.getImaginarypart()*complex2.getImaginarypart()))+" + "
                +((complex1.getImaginarypart()*complex2.getRealPart()-complex1.getRealPart()*complex2.getImaginarypart())
                /(complex2.getRealPart()*complex2.getRealPart()+complex2.getImaginarypart()*complex2.getImaginarypart()))+"i");
    }
    @Override
    public double abs(GeometricObject complex) {
        return Math.sqrt(complex.getRealPart()*complex.getRealPart()+complex.getImaginarypart()*complex.getImaginarypart());
    }
    @Override
    public String toString(GeometricObject complex) {
        if(complex.getImaginarypart()!=0)
            return complex.getRealPart()+" + "+complex.getImaginarypart()+"i";
        else
            return complex.getRealPart()+"";
    }
    @Override
    public int compareTo(GeometricObject complex) {
        if(abs(this)>abs(complex))
            return 1;
        if(abs(this)<abs(complex))
            return -1;
        return 0;
    }
    @Override
    public double getArea() {
        // TODO Auto-generated method stub
        return 0;
    }
    @Override
    public double getPerimeter() {
        // TODO Auto-generated method stub
        return 0;
    }
    @Override
    public void howToColor() {
        // TODO Auto-generated method stub

    }
}
class six {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        GeometricObject complex=new Complex();

        System.out.print("Enter the first complex number: ");
        double realPart1=input.nextDouble();
        double imaginarypart1=input.nextDouble();
        GeometricObject complex1=new Complex(realPart1,imaginarypart1);

        System.out.print("Enter the second complex number: ");
        double realPart2=input.nextDouble();
        double imaginarypart2=input.nextDouble();
        GeometricObject complex2=new Complex(realPart2,imaginarypart2);

        complex.add(complex1,complex2);
        complex.subtract(complex1,complex2);
        complex.multiply(complex1,complex2);
        complex.divide(complex1,complex2);
        System.out.println("|("+complex1.toString(complex1)+")| = "+complex1.abs(complex1));
        System.out.println("|("+complex2.toString(complex2)+")| = "+complex2.abs(complex2));
        if(complex.max(complex1,complex2)>0)
            System.out.println("The first complex is bigger  than the second!");
        else if(complex.max(complex1,complex2)<0)
            System.out.println("The first complex is smaller  than the second!");
        else
            System.out.println("The first complex is as big as the second!");
    }
}