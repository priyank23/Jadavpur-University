
import java.io.*;
import java.util.*;


public class FlightList {

    public Flight[] fl=new Flight[30];
    public int count;

    FlightList()
    {
        count =0;
        add( "Kolkata", "Ranchi",
                new Date (2020-1900, 12-1 ,8 ,13 ,46 ,12 ),
                3433 , 2998, 1,
                new Date (2020-1900, 12-1 ,7 ,14 ,23 ,89 ),
                "Vistara");
        add( "Kolkata", "Siliguri",
                new Date (2020-1900, 12-1 ,12 ,13 ,46 ,12 ),
                4433 , 4200, 1,
                new Date (2020-1900, 12-1 ,7 ,16 ,23 ,89 ),
                "Spicejet");
        add( "Ranchi", "Delhi",
                new Date (2020-1900, 12-1 ,13,13 ,46 ,12 ),
                7999 , -1, 0,
                new Date (2020-1900, 12-1 ,7 ,20 ,23 ,89 ),
                "Vistara");
        add( "Ranchi", "Bangalore",
                new Date (2020-1900, 12-1 ,18,13 ,46 ,12 ),
                10854 , 12998, 1,
                new Date (2020-1900, 12-1 ,8 ,4 ,23 ,89 ),
                "Indigo");
        add( "Kolkata", "Bangalore",
                new Date (2020-1900, 12-1 ,18 ,13 ,46 ,12 ),
                13433 , 10258, 1,
                new Date (2020-1900, 12-1 ,9 ,12,23 ,89 ),
                "Goair");
        add( "Kolkata", "Ranchi",
                new Date (2020-1900, 12-1 ,18,13 ,46 ,12 ),
                3433 , 1998, 1,
                new Date (2020-1900, 12-1 ,9 ,14 ,23 ,89 ),
                "Goair");
        add( "Kolkata", "Ranchi",
                new Date (2020-1900, 12-1 ,18,13 ,46 ,12 ),
                3493 , 2798, 1,
                new Date (2020-1900, 12-1 ,9 ,17 ,23 ,89 ),
                "Indigo");
        add( "Kolkata", "Dubai",
                new Date (2020-1900, 12-1 ,18 ,13 ,46 ,12 ),
                23493 , 22998, 1,
                new Date (2020-1900, 12-1 ,9 ,20 ,23 ,89 ),
                "Vistara");
        add( "Mumbai", "Ranchi",
                new Date (2020-1900, 12-1 ,19 ,13 ,46 ,12 ),
                14320 , -18, 0,
                new Date (2020-1900, 12-1 ,10 ,11 ,23 ,89 ),
                "Spicejet");
        add( "Kolkata", "Mumbai",
                new Date (2020-1900, 12-1 ,19 ,13 ,46 ,12 ),
                8654 , 6998, 1,
                new Date (2020-1900, 12-1 ,11 ,12 ,23 ,89 ),
                "Vistara");

    }

    public void add(String a,String b, Date h,int c, int d,int e, Date f,String g )
    {
        Flight fdf= new Flight(a,b,h,c,d,e,f,g);
        fl[count]=fdf;
        count+=1;
    }    
}
