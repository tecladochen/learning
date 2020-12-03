package com.Tecladochen;

import java.util.Date;
import java.util.Scanner;

public abstract class GeometricObject {
    private String color = "white";
    private boolean filled;
    private java.util.Date dateCreated;
    protected GeometricObject(){
        dateCreated = new Date();
    }
    protected GeometricObject(String color, boolean filled){
        dateCreated = new Date();
        this.color = color;
        this.filled = filled;
    }
    public String getColor(){
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    public Date getDateCreated() {
        return dateCreated;
    }

    @Override
    public String toString() {
        return "created on  " + dateCreated + "\ncolor: " + color + " and filled:" + filled;
    }
    public abstract double getArea();
    public abstract double getPerimeter();
}
class Triangle extends GeometricObject{
    private double side1, side2, side3;

    public Triangle() {
        this(1,1,1);
    }
    public Triangle(double x, double y, double z){
        side1 = x;
        side2 = y;
        side3 = z;
    }

    public double getSide1() {
        return side1;
    }

    public double getSide2() {
        return side2;
    }

    public double getSide3() {
        return side3;
    }
    public double getArea(){
        double p = (side1 + side2 + side3) / 2;
        return Math.sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }
    public double getPerimeter(){
        return side1 + side2 + side3;
    }
    @Override
    public String toString(){
        return super.toString() + "\nTriangle: side1 = " + side1 + " side2 = " + side2 + " side3 = " + side3;
    }
}
class TestAbstract{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("please enter :");
        double x = input.nextDouble();
        double y = input.nextDouble();
        double z = input.nextDouble();
        String color = input.next();
        boolean filled = input.nextBoolean();
        GeometricObject temp = new Triangle(x,y,z);
        temp.setColor(color);
        temp.setFilled(filled);
        System.out.println(temp.toString() + "\nArea:" + temp.getArea() + "  Perimeter:" + temp.getPerimeter());
    }
}