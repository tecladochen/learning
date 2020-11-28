package com.Tecladochen;

import java.util.Date;
import java.util.Scanner;

public class Account {
    private int id = 0;
    private double balance = 0;
    private static double annualInterestRate = 0;
    private Date dateCreated;
    public Account(){
        this(0,0);
    }
    public Account(int id,double balance){
        this.id = id;
        this.balance = balance;
        dateCreated = new Date();
    }

    public Date getDateCreated() {
        return dateCreated;
    }

    public int getId() {
        return id;
    }

    public static double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public double getBalance() {
        return balance;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public static void setAnnualInterestRate(double annualInterestRate) {
        Account.annualInterestRate = annualInterestRate;
    }

    public double getMonthlyInterestRate(){
        return annualInterestRate/12;
    }

    public double getMonthlyInterest(){
        return balance * (this.getMonthlyInterestRate() /100);
    }

    public void withDraw(double num){
        this.balance -= num;
    }

    public void deposit(double num){
        this.balance += num;
    }

    @Override
    public String toString() {
        return "id=" + id +
                ", balance=" + balance +
                ", dateCreated=" + dateCreated.toString() ;
    }
}
class checkingAccount extends Account {
    private double overdraft = 2000;
    public checkingAccount(int id,double balance,double overdraft){
        super(id,balance);
        this.overdraft = overdraft;
    }

    @Override
    public String toString() {
        return "checkingAccount{" +
                super.toString() +
                "overdraft=" + overdraft +
                '}';
    }
}
class savingAccount extends Account {
    public savingAccount(int id,double balance){
        super(id,balance);
    }

    @Override
    public String toString() {
        return "checkingAccount{" +
                super.toString() +
                '}';
    }
}
class TestAccount{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter account's id and balance :");
        int id = input.nextInt();
        double balance = input.nextDouble();
        System.out.print("Please select Account Type (checking/saving) :");
        String select1 = input.next();
        if(select1.equals("checking")){
            System.out.print("Please enter the overdraft limit :");
            double overdraft = input.nextDouble();
            checkingAccount check1 = new checkingAccount(id,balance,overdraft);
            System.out.print(check1.toString());
        }
        else{
            savingAccount save1 = new savingAccount(id,balance);
            System.out.print(save1.toString());
        }
    }
}