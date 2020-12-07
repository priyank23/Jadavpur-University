
import java.io.*;
import java.util.*;


public class Flight{
    public String origin;
    public String destination;
    public Date startdate;
    public int cost;
    public int isOffer;
    public int offercost;
    public Date validity;
    public String company;
    //public String duration;

    Flight(String a,String b,Date h, int c, int d,int e, Date f, String com )
    {
        origin=a;
        destination=b;
        startdate=h;
        cost=c;
        isOffer=e;
        offercost=d;
        validity=f;
        company=com;
    };
}
