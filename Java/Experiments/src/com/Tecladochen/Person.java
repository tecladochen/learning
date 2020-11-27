package com.Tecladochen;

import java.util.GregorianCalendar;

public class Person {
    private String name,address,number,email;
    public Person(String name, String address, String number, String email){
        this.name = name;
        this.address = address;
        this.number = number;
        this.email = email;
    }
}
class Student extends Person {
    public Student(String name, String address, String number, String email, String rank){
        super(name,address,number,email);
        final  String ranks = rank;
    }
}
class Employee extends Person {
    private String office;//办公室
    private int salary;//工资
    private MyDate employtime;
    public Employee(String name, String address, String number, String email,String office,
                    int salary,int year, int month, int day) {
        super(name, address, number, email);
        this.office = office;
        this.salary = salary;
        employtime = new MyDate(year, month, day);
    }
}
class Faculty extends Employee {
    private double workstart;
    private double workend;
    private String rank;
    public Faculty(String name, String address, String number, String email,String office,
                   int salary,int year, int month, int day,double workstart,double workend,
                   String rank){
        super(name,address,number,email,office,salary,year,month,day);
        this.workstart = workstart;
        this.workend = workend;
        this.rank = rank;
    }
}
class Staff extends Employee {
    private String call;
    public Staff(String name, String address, String number, String email,String office,
                 int salary,int year, int month, int day,String call){
        super(name,address,number,email,office,salary,year,month,day);
        this.call = call;
    }
}
class MyDate {
    private int year, month, day;

    public MyDate() {
        java.util.GregorianCalendar now = new java.util.GregorianCalendar();
        year = now.get(GregorianCalendar.YEAR);
        month = now.get(GregorianCalendar.MONTH);
        day = now.get(GregorianCalendar.DAY_OF_MONTH);
    }

    public MyDate(Long i) {
        java.util.GregorianCalendar now = new java.util.GregorianCalendar();
        now.setTimeInMillis(i);
        year = now.get(GregorianCalendar.YEAR);
        month = now.get(GregorianCalendar.MONTH);
        day = now.get(GregorianCalendar.DAY_OF_MONTH);
    }

    public MyDate(int x, int y, int z) {
        year = x;
        month = y;
        day = z;
    }

    public int getYear() {
        return year;
    }

    public int getMonth() {
        return month;
    }

    public int getDay() {
        return day;
    }

    public void setDate(Long i) {
        java.util.GregorianCalendar now = new java.util.GregorianCalendar();
        now.setTimeInMillis(i);
        year = now.get(GregorianCalendar.YEAR);
        month = now.get(GregorianCalendar.MONTH);
        day = now.get(GregorianCalendar.DAY_OF_MONTH);
    }
}