package com.Tecladochen;

import java.util.Date;

class GeometricObject{
    private String color = "white";
    private boolean filled;
    private Date dateCreated;
    public GeometricObject(){
        dateCreated = new Date();
    }
    public GeometricObject(String color, boolean filled){
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
    public String toString(){
        return "created on " + dateCreated + "\ncolor: " + color + " and filled: " + filled;
    }
}
public class Triangle extends GeometricObject {
    private double side1, side2, side3;

    public Triangle() {
        side1 = 1.0;
        side2 = 1.0;
        side3 = 1.0;
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
    public String toString(){
        return "Triangle: side1 = " + side1 + "side2 = " + side2 + "side3 = " + side3;
    }

    public static void main(String[] args) {
        
    }
}
